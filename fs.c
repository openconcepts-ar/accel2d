// Copyright (c) 2025 Victor Suarez Rovere <suarezvictor@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-only

#include <generated/csr.h>
#include <liblitesdcard/sdcard.h>

#ifndef CSR_SDCARD_CORE_BASE
#warning CSR_SDCARD_CORE_BASE not defined
#else

#include <libfatfs/diskio.h>
DISKOPS *FfDiskOps; //this is needed only for fatfs, but required to compile

#include "fat_io_lib/src/fat_access.c"
#include "fat_io_lib/src/fat_cache.c"
#include "fat_io_lib/src/fat_filelib.c"
#include "fat_io_lib/src/fat_format.c"
#include "fat_io_lib/src/fat_misc.c"
#include "fat_io_lib/src/fat_string.c"
#include "fat_io_lib/src/fat_table.c"
#include "fat_io_lib/src/fat_write.c"

static int sd_readsector(uint32_t start_block, uint8_t *buffer, uint32_t sector_count)
{
  sdcard_read(start_block, sector_count, buffer);
  return sector_count;
}

static int sd_writesector(uint32_t start_block, uint8_t *buffer, uint32_t sector_count)
{
  sdcard_write(start_block, sector_count, buffer);
  return sector_count;
}

DISKOPS *FfDiskOps; //this is needed to allow litex's library to compile

int fat_io_init(void)
{
  sdcard_init();

  fl_init();
  return fl_attach_media(sd_readsector, sd_writesector);
}
#endif

//FILE IO
//FIXME: this is just to avoid linker errors

#include <unistd.h>
#include <fcntl.h> //for open
#include <assert.h>

int open(const char *pathname, int flags, ...)
{
	assert(0);
	return -1;
}

ssize_t read(int fd, void *buf, size_t __nbyte)
{
	assert(0);
	return -1;
}

ssize_t write (int __fd, const void *__buf, size_t __nbyte)
{
	assert(0);
	return -1;
}

off_t lseek (int fd, off_t offset, int whence)
{
	assert(0);
	return -1;
}

int close(int fd)
{
	assert(0);
	return -1;
}

