#include <generated/csr.h>
#include <liblitesdcard/sdcard.h>

#ifndef CSR_SDCORE_BASE
#error CSR_SDCORE_BASE not defined
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

