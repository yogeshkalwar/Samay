#ifndef __GLOBAL_H
#define __GLOBAL_H 
#include "common.h"
#include "super_operations.h"
#include "inode_operation.h"
#include "dentry_operations.h"





unsigned long map_position(int index,int type,int flag,void *buffer,int fh);
int parse_string(char *inp_str,char parse_key,int length,char* out_str,int level);
void format_output(int error_no);
int my_create(char *file_name,int f_type,int fh);
int my_open(char *file_name,int fh);
void my_read(int inode_no,char *buffer,int size,int fh);
int my_write(int inode_no,char *buffer,int size,int fh);
void my_close(int inode_no,int fh);
void my_delete(int inode_no,int fh);
int get_super_block(struct superblock *sb, int fh,int *ptr_pos);
int set_super_block(struct superblock *sb, int fh,int *ptr_pos);

struct superblock sb;
struct inode temp1_inode;
struct inode  temp2_inode;
struct inode  temp3_inode;
struct dentry temp_dentry;
int command_type;
char output_buffer[MAX_LENGTH];
enum FSS_OBJECT{
	S_BLOCK = 0,
	I_BLOCK,
	D_BLOCK,
	DEN_BLOCK

};
FILE_HANDLE fh;
int file_ptr_pos;

#endif
