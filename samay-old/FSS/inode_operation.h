#ifndef __INODE_OPERATION_H
#define __INODE_OPERATION_H
//#include "common.h"
//#include "inode.h"
//#include "dentry.h"
#include "dentry_operations.h"

int i_create(void *d_subdirs,/*inode_ptr ip, */ dentry_ptr dp, int t,char *qstr);
int i_lookup(/*inode_ptr ip,*/void *d_subdirs, dentry_ptr dp);
int i_link(dentry_ptr dp,  dentry_ptr dp_new);
int i_unlink(/*inode_ptr ip,*/void *d_subdirs, int inode_no);
int i_symlink(/*inode_ptr ip,*/void *d_subdirs, dentry_ptr dp, const char *);
int i_mkdir(/*inode_ptr ip,*/void *d_subdirs, dentry_ptr dp, int t,char *qstr);
int i_rmdir( dentry_ptr dp);
int i_rename(dentry_ptr dp,  dentry_ptr dp_new);
int i_readlink(dentry_ptr dp, char *buf,int t);
int i_permission(/*inode_ptr ip,*/void *d_subdirs, int t,char* );
int i_setattr( dentry_ptr dp, /*struct iattr **/void * buf);
int i_getattr(  dentry_ptr dp, /*struct kstat **/ void * buf);
        


#endif
