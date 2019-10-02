#ifndef __SUPER_OPERATION_H
#define __SUPER_OPERATION_H
//#include "common.h"
#include "super_block.h"
//#include "inode.h"

#define FILE_SUBFILE_INFO 0
#define FILE_PERMISSION_INFO 1
#define FILE_OWNER_INFO 2
#define FILE_DATA_BLOCK 3

//BYTE arr[8] = {(char)1,(char)2,(char)4,(char)8,(char)16,(char)32,(char)64,(char)128};

/*
 *allots a inode when a call mkdir/create file is made
 *calls write_super internally
 */
BYTE alloc_inode(superblock_ptr sbp);

/*
 *to read data from inode,pass void *, and type of data
 *to be read
 */
void read_inode(int inode_no,inode_ptr ip); //only used to read metadata

/*
 *set inode bytes to NULL,use inode number
 *set corresponding bitmap in sb
 *calls write_super internally
 */
void dirty_inode(superblock_ptr sbp,int inode_no);

/*
 *write data into inode
 *calls write_super internally
 */
void write_inode(inode_ptr ip,int data_pos);

/*
 *on commit writes to the file(HDD)
 *i.e put the inode on the block finally
 *using the inode number, call some map
 *function to find file offset
 *calls write_super internally
 */
void put_inode(int inode_no,inode_ptr ip);

/*
 *reset corresponding bitmap in sb
 */
void clear_inode(superblock_ptr sbp,int inode_no);
void clear_datablock(superblock_ptr sbp,int inode_no);

/*
 *updates sb in the file(hdd) superblock
 */
void write_super(superblock_ptr sbp);

/*
 *Format entire sb data into buffer statfs
 */
int  statfs(superblock_ptr sbp, void *statfs );

/*
 *destroys the file contens(hdd)
 */
void umount_begin(superblock_ptr sbp);

/*
 *update structure sb
 *calls write_super internally
 */
void set_current_root(superblock_ptr sbp,int inode_no);

/*
 *allots data_block during file descriptor write operation
 *calls write_super internally
 */
BYTE alloc_data_block(superblock_ptr sbp);

/*
 *gets inode of current working directory
 */
int get_current_root(superblock_ptr sbp);

/*
 *gets the root inode
 */
int get_root(superblock_ptr sbp);

void dirty_data_block(superblock_ptr sbp,int d_no/*struct inode *ib*/);


#endif

