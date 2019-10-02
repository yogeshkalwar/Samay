#include "dentry_operations.h"

/*
 * d_validate(struct dentry *, int lenght)
 * check for valid file name length
 * check for invalid characters in the files name
 * will be called before d_iput,d_compare,d_hash
 * After name is vaidated sb will allocate inode block
 * inode_op will form a valid dentry block and pass to d_iput
 * Input args:
 *		char *qstr - file/dir name string
 *		int length - max file name length permitted
 * Return type:
 *		int : if sucess return FILE_SYSTEM_NO_ERROR else the error
 */
char valid_char[] = {'a','b','c','d'};
int invalid_char_ascii[] = { 63,124};

/*
extern char valid_char[4] ;
extern int invalid_char_ascii[2] ;
*/
int d_validate (char *qstr, int length){
	char *invalid_char = NULL;
	int i = 0;
	//length validation
	if(/*strlen(qstr) > */length > MAX_FILE_NAME_LEN){
		return FILE_NAME_CHAR_EXCEEDS;
	}
	// write a routine to find if any invalid characters exist
	for(i=0;i <sizeof(invalid_char_ascii)/sizeof(int);i++){
		invalid_char = strchr( qstr, invalid_char_ascii[i] );
		if(invalid_char){
			return FILE_NAME_CHAR_ILLEGAL;
		}
		invalid_char=NULL;
	}
	return FILE_SYSTEM_NO_ERROR;
}
/*
 * d_hash (struct dentry *, char *qstr,void* d_subdirs )
 * check for valid file name length
 * check for invalid characters in the files name
 * will be called before d_iput,d_compare,d_hash
 * Input args:
 *		char *qstr - file/dir name string
 *		void* d_subdirs - ref to datablock memory
 * Return type:
 *		int : if sucess return hash pos  else the FILE_SYS_NO_FREE_SPACE
 */
int d_hash (/*struct dentry *, */char *qstr,void* d_subdirs ){ //added d_subdirs
	int pos = 0;

	pos = d_pos(qstr,d_subdirs);
	if(pos == NOT_FOUND)
	return FILE_SYS_NO_FREE_SPACE;
	return pos;
	
}

//i have input as data_block start wherin all dirent  are stored
int d_compare (void* d_subdirs , char *qstr ){
	int pos = 0; 
	int j = 0;
	int i = 0;
	pos = 0;
	for(i = 0;i <sizeof(valid_char)/sizeof(char);i++){
		if( *qstr == valid_char[i])
			break;
	}	
	for(j=DENTRIES_PER_BLOCK-1;j>=0;j--){
	if(!strcmp((((dentry_ptr)d_subdirs)+j)->d_name ,qstr) )
		return ((((dentry_ptr)d_subdirs)+j)->inode_no);
	}
	return 0;
			
}
/*
 * Reset or uninitilaise the memory occupied by dentry
 */
int d_delete(void* d_subdirs,int inode_no){
	
        int i=0;
	while(i<DENTRIES_PER_BLOCK)
	{
		if(((dentry_ptr)d_subdirs+i)->inode_no==inode_no)	
		{
			((dentry_ptr)d_subdirs+i)->inode_no=-1;
			memset(((dentry_ptr)d_subdirs+i)->d_name,NULL_CHAR,MAX_FILE_NAME_LEN);
			return 1;
		}
	
	}
}
/*
 * inode struct of parent directory
 * dentry of sub dir /file to be added
 * at start dp contains only valis inode number
 * after validating qstr,cpy string
 */
int d_iput(dentry_ptr dp, void* d_subdirs/*struct inode **/,char *qstr){
	int ret_val = 0;
	int pos = 0;
	
	ret_val = d_validate (qstr, strlen(qstr));
	if(ret_val == FILE_SYSTEM_NO_ERROR){
		strcpy(dp->d_name,qstr);
		ret_val =  d_compare (d_subdirs , qstr );
		if(ret_val==0)
			pos = d_hash(qstr,d_subdirs);
		else{
			printf("\nDuplicate Filename");
			return FILE_NAME_DUPLICATE_ERROR;
		}
		if(pos == FILE_SYS_NO_FREE_SPACE)
			return FILE_SYS_NO_FREE_SPACE;
		/*
		 * Got pos noe find offset i.e pos*SIZE_OF_STRUCT_DENTRY
		 */
		memcpy(((dentry_ptr)d_subdirs+pos),dp,SIZE_OF_STRUCT_DENTRY);
		return FILE_SYSTEM_NO_ERROR; 
	}
		return ret_val;

}
//hash function implementation logic
int d_pos(char * qstr,void *d_subdirs){

	int i = 0;
	int j = 0;
	for(i = 0;i <sizeof(valid_char)/sizeof(char);i++){
		if( *qstr == valid_char[i])
			break;
	}
	while(i<DENTRIES_PER_BLOCK){
		if((((dentry_ptr)d_subdirs)+i)->inode_no == -1 ){
			return i;
		}
		i+=sizeof(valid_char);
//	j++;
	}
	//probability based location
	for(j=DENTRIES_PER_BLOCK-1;j>=0;j--){
		if((((dentry_ptr)d_subdirs)+j)->inode_no == -1 ){
			return j;
		}
	}
	return NOT_FOUND;
}

