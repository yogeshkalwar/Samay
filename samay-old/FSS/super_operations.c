#include "super_operations.h"
/*
 *user fires command mkdir or create's a file 
 * alloc_node called :
 * poll for a free(non-dirty inode)
 * we will not maintain a list of free inodes
 * 
 * writing to file : 
 * write metadata/write file contents
 * check uesr rights
 * dyanamically calculate the
 * no of bytes written to console and cal no.of blocks
 * reqd on that basis.
 * set size of readbuffer to 4*size of block
 * memset readbuffer \0
 * scanf into readbuffer
 * cal strlen readbuffer
 * find no. of blocks reqd
 * find no.of current direct blocks
 * if less ,then call get_datablock methos of superblock
 * write the addr to inode diredt/indirect block
 * finally memcpy to respective blocks
 * 
 * reading operations may be of 2 types: 
 *	will depend on ls commmand or file read/write
 *	read metadata/ read file contents
 *	reading from a file: current scheme will fetch data
 *	in 5 data block at a time and dispaly it using printf
 *	on console
 * 
 * write_super: called after all operations except 
 * read_inode( reading of data_block ), we dont have
 * any cache memory, therefore not called after read,
 * 
 */
//extern BYTE arr[8];
BYTE arr[] = 		{128,
			64,32,16,
			8,4,2,1};
			
 
BYTE alloc_inode(superblock_ptr sbp){
// remains constant	sb->s_first_ino

	int i = 0;
	int j = 0;
	if(sbp->s_free_inode_count == 0)
		return /*FILE_SYS_NO_FREE_SPACE*/0;
	/*before returning from this function find next free block and
	 * store its value in s_first_ino
	 * global arr defined,  each bmp byte contains
	 * info of 8 inode_blocks
	 * suppose we want info of 100th block
	 * refer 100/8, refer 12th byte and in it 100%8
	 * i.e 4 th bit in 12th byte
	 */
	//sbp->s_free_inode_count--;
	//scan for next free block; 
	for(i=0;i<INODE_COUNT/8;i++){
		for(j = 0;j<8;j++){
			if((int)(sbp->s_inode_bmp[i]&arr[j]) == (int)(arr[j])){
				return (unsigned char)(i*8 +j);
			}
		}
	}
//	if(sbp->s_free_inode_count == 0)
//	return 0;
	return -1;	
	
}
/*
 * copies the inode/metadata info into the memory ref ib
 * maps the offset in the hdd file using the inode number
 * Input Args:
 *		int inode_no - Inode number passed
 *		struct inode *ib - Inode ptr
 * Return Type:
 *		void
 */
void read_inode(int inode_no,struct inode *ib/*,int info_type,void *info_block*/){
	//if ls more than file info returned in dirent(type) structure
	// to get file permissions, ownwer id etci.e reading of metadata
	
	//ignore above statemet, amar's mapping formula be used to calculate offset
}

void dirty_inode(superblock_ptr sbp,int inode_no/*struct inode *ib*/){ 
	//ib->inode_no/8;
	//ib->inode_no%8;
	//printf("\n %d %s",ib
	sbp->s_free_inode_count-- ;
	sbp->s_inode_bmp[inode_no/8]=sbp->s_inode_bmp[inode_no/8]&((int)arr[inode_no%8]-1);
}

void clear_datablock(superblock_ptr sbp,int inode_no/*struct inode *ib*/){ 
	//ib->inode_no/8;
	//ib->inode_no%8;
	//printf("\n %d %s",ib
	sbp->s_free_datablock_count++ ;
	sbp->s_inode_bmp[inode_no/8]=sbp->s_inode_bmp[inode_no/8]|(arr[inode_no%8]);
}
void write_inode(inode_ptr ip, int t){
	
}

/*
 *on commit writes to the file(HDD)
 *i.e put the inode on the block finally
 *using the inode number, call some map
 *function to find file offset
 *calls write_super internally
 */
void put_inode(int inode_no,inode_ptr ip){
}

/*
 *reset corresponding bitmap in sb
 */
void clear_inode(superblock_ptr sbp,int inode_no){
	sbp->s_free_inode_count++ ;
    sbp->s_inode_bmp[inode_no/8]=sbp->s_inode_bmp[inode_no/8]|(arr[inode_no%8]);


}



/*
 *updates sb in the file(hdd) superblock
 */
void write_super(superblock_ptr sbp){
}

/*
 *Format entire sb data into buffer statfs
 */
int statfs(superblock_ptr sbp, void* statfs){
}
 
/*
 *destroys the file contens(hdd)
 */       
void umount_begin(superblock_ptr sbp){
}

/*
 *update structure sb
 *calls write_super internally
 */
void set_current_root(superblock_ptr sbp,int inode_no)
{	sbp->s_current_root=inode_no;

}

void inode_delete(superblock_ptr sbp,int inode_ptr)
{
		  		
}



/*
 *allots data_block during file descriptor write operation
 *calls write_super internally
 */
BYTE alloc_data_block(superblock_ptr sbp){
	int i = 0;
int pos = -1;        int j = 0;
	if(sbp->s_free_datablock_count == 0)
		return /*FILE_SYS_NO_FREE_SPACE*/0;
	for(i=0;i<DATABLOCK_COUNT/8;i++){
		                for(j = 0;j<8;j++){
	if((int)(sbp->s_datablock_bmp[i]&arr[j]) == (int)(arr[j])){
		sbp->s_free_datablock_count-- ;	


		pos= (unsigned char)(i*8 +j);break;
	}
				}
	if(pos != -1)break;
	}
	sbp->s_datablock_bmp[pos/7]=sbp->s_datablock_bmp[pos/7]&((int)(arr[pos%7])-1)
		;
      if(pos == (i*8 +j))
return pos;


}	

/*
 *gets inode of current working directory
 */
int get_current_root(superblock_ptr sbp){
	return sbp->s_current_root;
}

/*
 *gets the root inode
 */


int get_root(superblock_ptr sbp){
	return sbp->s_current_root;
}

void dirty_data_block(superblock_ptr sbp,int d_no/*struct inode *ib*/){ 
	//ib->inode_no/8;
	//ib->inode_no%8;
	//printf("\n %d %s",ib
	sbp->s_free_datablock_count-- ;
	sbp->s_datablock_bmp[d_no/8]=sbp->s_datablock_bmp[d_no/8]&((int)arr[d_no%8]-1);
}


