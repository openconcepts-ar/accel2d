// This file is Copyright (C) 2024 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <stdio.h>

#define BLOCKSIZE 512

// Parse an octal number, ignoring leading and trailing nonsense
static unsigned long
parseoct(const char *p, size_t n)
{
	unsigned long i = 0;

	while ((*p < '0' || *p > '7') && n > 0) {
		++p;
		--n;
	}
	while (*p >= '0' && *p <= '7' && n > 0) {
		i *= 8;
		i += *p - '0';
		++p;
		--n;
	}
	return (i);
}

// Returns true if this is 512 zero bytes
static int
is_end_of_archive(const char *p)
{
	int n;
	for (n = 0; n < BLOCKSIZE; ++n)
		if (p[n] != '\0')
			return (0);
	return (1);
}

// Verify the tar checksum
static int
verify_checksum(const char *p)
{
	int n, u = 0;
	for (n = 0; n < BLOCKSIZE; ++n) {
		if (n < 148 || n > 155)
			/* Standard tar checksum adds unsigned bytes. */
			u += ((unsigned char *)p)[n];
		else
			u += 0x20;

	}
	return (u == (int)parseoct(p + 148, 8));
}

// Extract a tar archive
typedef int (*process_archived_file_t)(FL_FILE *a, const char *fname, size_t flen);
static int untar(FL_FILE *a, process_archived_file_t process_fn)
{
	size_t bytes_read;
	unsigned long filesize;
	char buff[BLOCKSIZE];
	{
		bytes_read = fl_fread(buff, BLOCKSIZE, 1, a);
		if (bytes_read < BLOCKSIZE) {
			printf("UNTAR: short read: expected %d, got %d\n", BLOCKSIZE, (int)bytes_read);
			return -1;
		}
		if (is_end_of_archive(buff)) {
			return 0;
		}
		if (!verify_checksum(buff)) {
			printf("UNTAR: checksum failure\n");
			return -2;
		}
		filesize = parseoct(buff + 124, 12);
		switch (buff[156]) {
		case '1':
			printf("UNTAR: ignoring hardlink %s\n", buff);
			break;
		case '2':
			printf("UNTAR: ignoring symlink %s\n", buff);
			break;
		case '3':
			printf("UNTAR: ignoring character device %s\n", buff);
			break;
		case '4':
			printf("UNTAR: ignoring block device %s\n", buff);
			break;
		case '5':
			printf("UNTAR: directory %s\n", buff);
			//create_dir(buff, (int)parseoct(buff + 100, 8));
			filesize = 0;
			break;
		case '6':
			printf("UNTAR: ignoring FIFO %s\n", buff);
			break;
		default:
			process_fn(a, buff, filesize);
			filesize = 512-(filesize & 0x1FF); //skip unused bytes
			break;
		}
		if(filesize & 0x1FF)
			fl_fseek(a, filesize, SEEK_CUR);
	}
	return 1;
}

