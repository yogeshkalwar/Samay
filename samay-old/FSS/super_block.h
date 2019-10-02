#ifndef __SUPER_BLOCK_H
#define __SUPER_BLOCK_H
//#include "common.h"
#include "inode.h"
struct superblock {
		unsigned long s_inodes_count; // 32bit value indicating the total number of inodes,
		unsigned long s_blocks_count ;// 32bit value indicating the total number of blocks, 
		unsigned long s_free_datablock_count; // 32bit value indicating the total number of free blocks
		unsigned long s_free_inode_count ;// 32bit value indicating the total number of free inodes
		unsigned long s_first_data_block; // 32bit value identifying the first data block, in other word the id of the block containing the superblock structure. 
		
		unsigned long s_mtime;          /* Mount time */
    
		unsigned long s_first_ino ; //32bit value used as index to the first inode useable for standard files.
		unsigned short s_inode_size ;//16bit value indicating the size of the inode structure
	
                unsigned long s_root;
		int s_current_root;
		BITMAP s_inode_bmp[INODE_COUNT/8]; // shld be multiple of 8
		BITMAP s_datablock_bmp[DATABLOCK_COUNT/8]; // shld be multiple of 8

		
};
typedef struct superblock* superblock_ptr;
#define SIZE_OF_SUPER_BLOCK sizeof(struct superblock)
#endif

