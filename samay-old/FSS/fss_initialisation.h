#ifndef __FSS_INITIALISATION_H
#define __FSS_INITIALISATION_H
#include "global.h"
//#define MAX_BLOCKS
//#define MAX_BLOCK_SIZE
//void init_fss_memory();
int mount_fss();
//void create_fss_file();


/*
 * mount_fss:
 * Initialise struct super_block
 * Initialise root node
 * open fss.dat file in write/binary mode
 * fwrite super_block and root node to fss file
 * fclose , return with error code
 */
#endif
