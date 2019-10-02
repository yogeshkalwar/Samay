#ifndef __DENTRY_H
#define __DENTRY_H
#include "common.h"
//#include "inode.h"
struct dentry {
        //struct inode *d_inode;
		int inode_no;
        char d_name[/*MAX_FILE_NAME_LEN*/5];
          
};
typedef struct dentry* dentry_ptr;
#define SIZE_OF_STRUCT_DENTRY sizeof(struct dentry)
#endif
