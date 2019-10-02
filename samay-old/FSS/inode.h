#ifndef __INODE_H
#define __INODE_H
#include "common.h"
struct inode {
        unsigned int inode_no; 
        unsigned int parent_inode_no; 
        unsigned short i_mode;//16bit value used to indicate the format of the described file and the access rights. 
        unsigned short i_uid; //16bit user id associated with the file. 
        unsigned short i_gid;//16bit value of the group having access to this file. 
	unsigned short i_ftype;
	unsigned long i_size;             //32bit value indicating the size of the file in bytes. 
char d_name[5];        
time_t i_atime;
        time_t i_ctime;
        time_t i_mtime;
        //struct super_block *i_sb;
	unsigned short ref_count;
	DATA_BLOCK d_block[10];
        
};
typedef struct inode* inode_ptr;
#define SIZE_OF_INODE_BLOCK sizeof(struct inode)
#endif
