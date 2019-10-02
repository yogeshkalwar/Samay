#include "inode_operation.h"

int  i_lookup(/*inode_ptr ip,*/void *d_subdirs, dentry_ptr dp){
	int i =0;
	i = d_compare(d_subdirs,dp->d_name);//return 1 if new, else 0	
	
	if(!i){
	 	dp->inode_no = i;
	}
	else{
		
	}
        
	return i;
};
/*
 * refer to inode using this ptr,dentry struct we populate
 * we have new parent inode and and file/dir name( in dentry)
 * call operation on data block to fill this entry 
 * (only new entry's inode number $ name ) after calling 
 * int d_compare (struct dentry *, struct qstr *)
 */
int i_create(void *d_subdirs,/*inode_ptr ip, */ dentry_ptr dp, int t,char *qstr){

        int i = 0;
        i=d_iput(dp,d_subdirs,qstr);
        return i;
}

	
	//from main we have new dir name and parent name in dentry
	// we call root hasing function to find parent dir,get inode
	// call create(this function)populate dentry with list of subdirs
	//decsion to take this recursive search for dir from root to ..\
	//where to initiate ?
	//finally call 
	//void (*d_iput)(struct dentry *, struct inode *);
	//write
//}
int i_link(dentry_ptr dp,  dentry_ptr dp_new){
	/*
	* one dentry is to be create in the currrent inode
	* other dentry is present in someother inode
	* form a std mechanism to store this information  
	* normally its the same inode followed by a new name,
	*take dentry->dname from new link name, take original inode
	*from other dentry 
	*/
	
};

int i_unlink(/*inode_ptr ip,*/void *d_subdirs, int inode_no){
	//lookup()
	//int (*d_delete)(struct dentry *);
	

};

int i_symlink(/*inode_ptr ip,*/void *d_subdirs, dentry_ptr dp, const char *qstr){
};
int i_mkdir(void *d_subdirs,/*inode_ptr ip, */ dentry_ptr dp, int t,char *qstr){

	int i = 0;
	i=d_iput(dp,d_subdirs,qstr);
	return i;
};
int i_rmdir( dentry_ptr dp){
};

int i_rename(dentry_ptr dp,  dentry_ptr dp_new){
};
int i_readlink(dentry_ptr dp, char *buf,int t){
};
        
int i_permission(/*inode_ptr ip,*/void *d_subdirs, int t,char*qstr ){
};
int i_setattr( dentry_ptr dp, /*struct iattr **/void * buf){
};
int i_getattr(  dentry_ptr dp, /*struct kstat **/ void * buf){
};
