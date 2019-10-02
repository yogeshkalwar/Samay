#include "global.h"
unsigned long map_position(int index,int type,int flag,void *buffer,int fh){
	
	unsigned long start_pos = 0;
	switch(type){
	case S_BLOCK:
		start_pos = index;
		lseek(fh,start_pos,SEEK_SET);
		if(flag==1)
		{
			write(fh,buffer,SIZE_OF_SUPER_BLOCK);
		}
		if(flag==0)
		{
			read(fh,buffer,SIZE_OF_SUPER_BLOCK);
		}	
		break;
	case I_BLOCK:
		start_pos=BLOCK_SIZE+(index*BLOCK_SIZE);
		lseek(fh,start_pos,SEEK_SET);
		if(flag==1)
		{
			write(fh,buffer,SIZE_OF_INODE_BLOCK);
		}
		if(flag==0)
		{
			read(fh,buffer,SIZE_OF_INODE_BLOCK);
		}	
		break;
	case D_BLOCK:
		start_pos=BLOCK_SIZE+INODE_COUNT*BLOCK_SIZE+(index*BLOCK_SIZE);
		lseek(fh,start_pos,SEEK_SET);
		if(flag==1)
		{
			write(fh,buffer,BLOCK_SIZE);
		}
		if(flag==0)
		{
			read(fh,buffer,BLOCK_SIZE);
		}	
		break;
	case DEN_BLOCK:
		break;
	default:
		return FILE_ERROR;
		
	}
	return start_pos;
}

/*
* API to parse a string
* Input Args :
*	char *inp_str  - Input String
*	char parse_key - Char to be found
*	int *length    - Conatins length of the file/dir name before the key
*	char* out_str  - Conatins the string found before the key
*	int level	   - To find (n th)level of the key
* Return type:
*  int : indicate End of String, else returns any non zero value
*/
//why u have used int* length here, out of my scope
int parse_string(char *inp_str,char parse_key,int length,char* out_str,int level){
	//*length,char* out_str,int level){
	char *temp = NULL;
	char *prev = NULL;
	int pos = 0;
	
	int i = 0;
	temp = inp_str;
	while(i< level){
		prev =temp;
		temp = strchr( temp, parse_key );
		if(temp == NULL){
			length = strlen(prev);
			memcpy(out_str,prev,length);
			return END_OF_STRING;
		}
		pos = temp -prev  + 1;
		temp++;
		length = pos-1;
		i++;
	}
	
	memcpy(out_str,prev,length);
	return ( (*(temp +1 ) == '\0')?END_OF_STRING:(*temp));
}
/*
* API to fromat error string and print it to console
* Input Args :
*	int error_no  - Error number
* Return type:
*  void : 
*/
void format_output(int error_no){
	switch(error_no){
	case FSS_BAD_COMMAND:
		sprintf(output_buffer,"%s %d","Bad Command Entered"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FSS_DISK_OPEN_ERROR:
		sprintf(output_buffer,"%s %d","Cant open disk"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FSS_DISK_READ_ERROR:
		sprintf(output_buffer,"%s %d","Cant read disk"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FSS_COMMANND_NOT_FOUND:
		sprintf(output_buffer,"%s %d","Command not found"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FSS_COMMAND_READ_ERROR:
		sprintf(output_buffer,"%s %d","Cant read disk"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_CREATE_ERROR:
		sprintf(output_buffer,"%s %d","Cant create file/dir on disk"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_NUMERICAL_LMT_EXCEEDS:
		sprintf(output_buffer,"%s %d","Characters in file/dir name exceed limit"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_WRITE_ERROR:
		sprintf(output_buffer,"%s %d","Write operation failed"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_SYS_NO_FREE_SPACE:
		sprintf(output_buffer,"%s %d","Disk full"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_NAME_CHAR_INVALID:
		sprintf(output_buffer,"%s %d","Characters in file/dir name invalid"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_OPEN_ERROR:
		sprintf(output_buffer,"%s %d","Cant open file on disk"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_SYS_INVALID_USER:
		sprintf(output_buffer,"%s %d","User not found"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_SYS_FILE_NUMERICAL_LMT_IN_DIRACTORY_EXCEEDS:
		sprintf(output_buffer,"%s %d","Cant create file/dir in a directory"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_COPY_ERROR:
		sprintf(output_buffer,"%s %d","Cant copy file/dir to desired location"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_PASTE_ERROR:
		sprintf(output_buffer,"%s %d","Cant paste file/dir to desired location"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_NAME_DUPLICATE_ERROR:
		sprintf(output_buffer,"%s %d","File name already exists"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_SYS_FILE_NOT_FOUND_ERROR:
		sprintf(output_buffer,"%s %d","File not found"
			,error_no);
		printf("%s",output_buffer);
		break;
	case FILE_DELETION_ERROR:
		sprintf(output_buffer,"%s %d","File cannot be deleted"
			,error_no);
		printf("%s",output_buffer);
		break;
	default:
		printf("UNKNOWN ERROR");
	}
	printf("\n");
}




int my_create(char *file_name,int f_type,int fh){
	
	char block[BLOCK_SIZE];
	char *temp  = NULL;
	char *prev=NULL;
	int written_bytes=0;
    	inode_ptr *temp_i_ptr  = NULL;
	unsigned long pos = 0;
	int prev_len=0;
	int len=0;
	int i=0;
	int inode_no=0;
	int result=0;
	int absolute_path = 0;int d_no=0;
	int res = 0;int in_no = 0;int i_root = 0;
	char dir_name[MAX_LENGTH];
	char read_temp_buff[4*BLOCK_SIZE];
	int no_blocks = 0;
	int total = 0;
   	char ref_block[BLOCK_SIZE];
	
	memset(dir_name,'\0',MAX_LENGTH);
	memset(block,'0',BLOCK_SIZE);
	i = 1;
	if( *(file_name) == '/')
		absolute_path = 0;
	if(absolute_path==1){ //abs path "root:\amar.txt"
		pos=get_current_root(&sb); //defination to be changed
		i_root = pos;
		map_position(pos,I_BLOCK,READ_FSS,&temp1_inode,fh);
		temp = file_name+1;//wrong
		
	}else{ //relative path "\amar.txt"
		pos=get_current_root(&sb); //change
		temp = file_name;
		i_root=pos;
		map_position(pos,I_BLOCK,READ_FSS,&temp1_inode,fh);
		
	}
	//printf("%s",file_name);//return 0;
	while(result != END_OF_STRING){
		memset(dir_name,'\0',MAX_LENGTH);
		result = parse_string(temp,'/',len,dir_name,i++);
		
		strcpy(temp_dentry.d_name , dir_name);
		temp_dentry.inode_no = -1;	//	printf("\n fh %d",fh);return;
		map_position(temp1_inode.d_block[0],D_BLOCK,READ_FSS,block,fh);
		res = i_lookup(block,&temp_dentry);
		
		if(res==0){
			if(result != END_OF_STRING){
				return FILE_SYS_FILE_NOT_FOUND_ERROR;
			}
		}
		if(res != 0){
			if(result == END_OF_STRING){
				return FILE_NAME_DUPLICATE_ERROR;
			}
		}
		if(result != END_OF_STRING)
			pos = map_position(temp_dentry.inode_no,I_BLOCK,READ_FSS,&temp1_inode,fh);
		
	} // to check if went till last string
	// to create directory
	pos =(int)alloc_inode(&sb);
	if(pos == 0){
		//clear_inode(&sb,pos);
		return result;
	}
	if(pos == -1){ return result;}
	in_no = pos;
	//printf("\n INODE NUMBER:--   %d",in_no);
	pos = map_position(pos,I_BLOCK,READ_FSS,&temp2_inode,fh);
	/* we will use same dentry, int-->(inode_ptr) and vice versa*/
	temp_dentry.inode_no = temp2_inode.inode_no;
	/*while(temp1_inode.d_block[i]!=FILE_SYSTEM_NULL){
		memset(block,'0',BLOCK_SIZE);
		pos = map_position(temp1_inode.d_block[i],D_BLOCK,READ_FSS,block,fh);
		res =i_mkdir(block,&temp_dentry,0,dir_name);
		if (res==FILE_NAME_CHAR_EXCEEDS || res== FILE_NAME_CHAR_ILLEGAL)
		{	break;
		//	clear_inode(&sb,pos);return;
		}i++;
	}
	
	if(res != FILE_SYSTEM_NO_ERROR){
		clear_inode(&sb,pos);
	}
	

	*/
	memset(block,'0',BLOCK_SIZE);
	pos = map_position(temp1_inode.d_block[0],D_BLOCK,READ_FSS,block,fh);
	res =i_mkdir(block,&temp_dentry,0,dir_name);
	if(res != FILE_SYSTEM_NO_ERROR){
		clear_inode(&sb,pos);return;
	}
	//printf("\n File creation sucessful");
	dirty_inode(&sb,temp_dentry.inode_no);
	//////////////////////////////////////////////////////////////////////
	pos = map_position(temp1_inode.d_block[0],D_BLOCK,WRITE_FSS,block,fh);
	//my_write(temp1_inode.inode_no,block,SIZE_OF_DATABLOCK,fh);
	//////////////////////////////////////////////////////////////////////
	strcpy(temp2_inode.d_name,dir_name);	
	temp2_inode.i_ftype = f_type;
	temp2_inode.parent_inode_no=temp1_inode.inode_no;
	for(i=0;i<10;i++)
	{
		temp2_inode.d_block[i]=FILE_SYSTEM_NULL;
	}
	map_position(0,S_BLOCK,WRITE_FSS,&sb,fh);
	pos = map_position(in_no,I_BLOCK,WRITE_FSS,&temp2_inode,fh);	
	map_position(i_root,I_BLOCK,WRITE_FSS,&temp1_inode,fh);
	//printf("\n CREATED %d",temp2_inode.inode_no);
	//printf("\n CREATED",temp2_inode.inode_no);
	
	//printf	
	return temp2_inode.inode_no;
	
	
}

int my_open(char *file_name,int fh){
	char block[BLOCK_SIZE];
	char *temp  = NULL;
	char *prev=NULL;
	int written_bytes=0;
    inode_ptr *temp_i_ptr  = NULL;
	unsigned long pos = 0;
	int prev_len=0;
	int len=0;
	int i=0;
	int inode_no=0;
	int result=0;
	int absolute_path = 0;int d_no=0;
	int res = 0;int in_no = 0;int i_root = 0;
	char dir_name[MAX_LENGTH];
	char read_temp_buff[4*BLOCK_SIZE];
	int no_blocks = 0;
	int total = 0;
   	char ref_block[BLOCK_SIZE];
	
	memset(dir_name,'\0',MAX_LENGTH);
	memset(block,'0',BLOCK_SIZE);
	i = 1;
	//printf("ok");
	if( *(file_name) == '/')				                        
		absolute_path = 0;
	if(absolute_path==1){
		pos=get_root(&sb);
		i_root = pos;
		map_position(pos,I_BLOCK,READ_FSS,&temp1_inode,fh);
		temp = file_name+1;
	}else{
		pos=get_current_root(&sb);
		temp = file_name;
		i_root=pos;
		 map_position(pos,I_BLOCK,READ_FSS,&temp1_inode,fh);
	}	
	//nprintf("ok");

	while(result != END_OF_STRING){
		memset(dir_name,NULL_CHAR,MAX_LENGTH);	
		result = parse_string(temp,'/',&len,dir_name,i++);		 
		strcpy(temp_dentry.d_name , dir_name);			
		temp_dentry.inode_no = -1;
		map_position(temp1_inode.d_block[0],D_BLOCK,READ_FSS,block,fh);
		res = i_lookup(block,&temp_dentry);
		temp_dentry.inode_no = res;	
		if(res==0){	
			printf("\n Name not found");
			return FILE_SYS_FILE_NOT_FOUND_ERROR;
		}
		
		pos = map_position(temp_dentry.inode_no,I_BLOCK,READ_FSS,&temp1_inode,fh);
	} // to check if went till last string
	//printf("ok");
	
	set_current_root(&sb,temp1_inode.inode_no);
	map_position(0,S_BLOCK,WRITE_FSS,&sb,fh);
	//pos = map_position(1,I_BLOCK,READ_FSS,&temp2_inode,fh);
	return temp1_inode.inode_no;
	
	
	
}

void my_read(int inode_no,char *buffer,int size,int fh){
	int pos;
	int i;
	
	map_position(inode_no,I_BLOCK,READ_FSS,&temp1_inode,fh);
	
	// to create directory
	pos=temp1_inode.inode_no;
	memset(buffer,NULL_CHAR,size);
	//pos = map_position(temp1_inode.d_block[0],D_BLOCK,READ_FSS,block,fh);
	i=0;
	while(temp1_inode.d_block[i]!=FILE_SYSTEM_NULL)
	{
//		memset(buffer,NULL_CHAR,BLOCK_SIZE);
		map_position(temp1_inode.d_block[i],D_BLOCK,READ_FSS,buffer+(i*SIZE_OF_DATABLOCK),fh);
		i++;
				
	}	
	map_position(0,S_BLOCK,WRITE_FSS,&sb,fh);
	
}

int my_write(int inode_no,char *buffer,int size,int fh){
	int pos,d_no;
	int i = 0;int j =0;
	char temp_buff[SIZE_OF_DATABLOCK];
	
	map_position(inode_no,I_BLOCK,READ_FSS,&temp3_inode,fh);
		
	//printf("\n INODE NUMER:----  %d",inode_no);	
	while((size > 0) &&( i <10)){
		if(temp3_inode.i_ftype == 0)
		{
			d_no = temp3_inode.d_block[i];
			if(d_no==FILE_SYSTEM_NULL){
				pos = (int)alloc_data_block(&sb);
				if(pos == 0){
					printf("\n NO FREE SPACE");
					return;
				}
				temp3_inode.d_block[i] = pos;
				dirty_data_block(&sb,pos);
			}
		
		
			map_position(pos,D_BLOCK,WRITE_FSS,buffer+(i*SIZE_OF_DATABLOCK),fh);
		}
/*		if(temp3_inode.i_ftype == 1){
			i=0;
			while(temp3_inode.d_block[i]!=FILE_SYSTEM_NULL){
				i++;
			}
			pos=temp3_inode.d_block[i-1]; 
			map_position(pos,D_BLOCK,WRITE_FSS,buffer+(i*SIZE_OF_DATABLOCK),fh);
			//search dentry full
			while(j<DENTRIES_PER_BLOCK){
				if(((dentry_ptr)buffer +j)->inode_no == -1){
					break;
				}
				j++;
			}
			if(j==DENTRIES_PER_BLOCK-1){
                                pos = (int)alloc_data_block(&sb);
                                if(pos == 0){
                                        printf("\n NO FREE SPACE");
                                        return;
                                }
                		dirty_data_block(&sb,pos);
				temp3_inode.d_block[i] = pos;
                        }

		}*/

		 if(temp3_inode.i_ftype == 1){
                        i=0;
                        pos = temp3_inode.d_block[0];
			if(pos==FILE_SYSTEM_NULL)
			{
				pos = (int)alloc_data_block(&sb);
                                if(pos == 0){
                                	printf("\n NO FREE SPACE");
                                        return;
                                }
                        	temp3_inode.d_block[0] = pos;
                        	dirty_data_block(&sb,pos);
                        }
	
		
                        map_position(pos,D_BLOCK,WRITE_FSS,buffer+(i*SIZE_OF_DATABLOCK),fh);

                        //search dentry full
                 }


		size -= SIZE_OF_DATABLOCK;i++;
	}

	map_position(inode_no,I_BLOCK,WRITE_FSS,&temp3_inode,fh);
	map_position(0,S_BLOCK,WRITE_FSS,&sb,fh);
	//printf(" Current root %d",sb.s_current_root); 

}

void my_close(int inode_no,int fh){
		
	map_position(inode_no,I_BLOCK,READ_FSS,&temp1_inode,fh);
	//if(temp1_inode.i_ftype==0)
		set_current_root(&sb,temp1_inode.parent_inode_no);
	map_position(0,S_BLOCK,WRITE_FSS,&sb,fh);
	//printf("\n******DIR CHANGED*******");

}

void my_delete(int inode_no,int fh){
	int i=0;
	char buffer[BLOCK_SIZE];
	map_position(inode_no,I_BLOCK,READ_FSS,&temp1_inode,fh);
	clear_inode(&sb,inode_no);
	//printf("\n %d",temp1_inode.i_ftype);
	//printf("\n OK"); printf("\n OK"); printf("\n OK"); printf("\n OK"); printf("\n OK");
	//inode_no = temp1_inode.parent_inode_no;
	//map_position(inode_no,I_BLOCK,READ_FSS,&temp1_inode,fh);
	if(temp1_inode.i_ftype == 1)
	map_position(temp1_inode.d_block[0],D_BLOCK,READ_FSS,buffer,fh);
	
	if(temp1_inode.i_ftype == 0){
	while(temp1_inode.d_block[i]!=FILE_SYSTEM_NULL){
		clear_datablock(&sb,temp1_inode.d_block[i]);
		i++;printf("\n %d",i);
	}
	}
	
	map_position(0,S_BLOCK,WRITE_FSS,&sb,fh);

}



/*
* API to read FSS superblock 
*/
int get_super_block(struct superblock *sb, int fh,int *ptr_pos){
	
	int n = 0;int pos = 0;
	pos = lseek( fh, 0L, SEEK_CUR );
	if(pos == FILE_ERROR){
		return FSS_DISK_SEEK_ERROR;
	}
	
	n = read( fh, sb, SIZE_OF_SUPER_BLOCK );
	if(n == FILE_ERROR || n < SIZE_OF_SUPER_BLOCK){
		return FSS_DISK_READ_ERROR;
	}
	
	
	*ptr_pos = SIZE_OF_SUPER_BLOCK;
	return n;
}


int set_super_block(struct superblock *sb, int fh,int *ptr_pos){

        int n = 0;int pos = 0;
        pos = lseek( fh, 0L, SEEK_CUR );
        if(pos == FILE_ERROR){
                return FSS_DISK_SEEK_ERROR;
        }

        n = write( fh, sb, SIZE_OF_SUPER_BLOCK );
        if(n == FILE_ERROR || n < SIZE_OF_SUPER_BLOCK){
                return FSS_DISK_READ_ERROR;
        }


        *ptr_pos = SIZE_OF_SUPER_BLOCK;
        return n;
}

