#include "global.h"
#include "fss_initialisation.h"
int main(int args,char* argv[]){
	char buf[DISK_STORE];
	char buffer[BLOCK_SIZE];
	int cv=0;
	int u=0;
	char c='0';
	int n = 0;
	int handle=0;
	int fh=-1,i,j;
	struct inode in;struct dentry d;
	if(args==2 && !(strcmp("mount",argv[1])))
	{
				mount_fss();return;
	}
	fh = 0;	
	if((fh = open( FSS_FILENAME, O_RDWR , 0777  ))==-1){
		
		format_output(FSS_DISK_OPEN_ERROR);
		return;
	}
	//printf("\n %s %ld","FSS opened",fh);
	//copy the super_block into sb
	n = get_super_block(&sb,fh,&file_ptr_pos);
	if(n != 1){
	}
	if(args==3 && !(strcmp("cd",argv[1])))
	{	
		cv=1; 
		//cd();
	}
	if(args==2 && !(strcmp("cd..",argv[1])))
	{	
		cv=2;
		 //cdb();
	}
	if(args==3 && !(strcmp("rm",argv[1])))
	{	
		cv=3;
		//rm();
	}
	if(args==3 && !(strcmp("mkdir",argv[1])))
	{	
		cv=4;
		 //mkdir();
	}

	if(args==3 && !(strcmp("create",argv[1])))
	{	
		cv=5;
		// create();
	}
	if(args==2 && !(strcmp("ls",argv[1])))
	{	
		cv=6; 
		//ls();
	}
	if(args==4 && !(strcmp("cp",argv[1])))
	{	
		//cp();
		cv=7; //cp
	}
	if(args==3 && !(strcmp("read",argv[1])))
	{	
		cv=8;
		 //read()
	}

	if(args==3 && !(strcmp("write",argv[1])))
	{	
		cv=9;
		 //write();
	}
	if(args==3 && !(strcmp("open",argv[1])))
	{	
		cv=10; 
		//open();
	}
	if(args==3 && !(strcmp("close",argv[1])))
	{	
		cv=11;
		 //close();
	}
	if(args==3 && !(strcmp("delete",argv[1])))
	{	
		//cv=12;
		 //delete();
	}
if(args==2 && !(strcmp("pwd",argv[1])))
        {
                //cv=13;
		 //pwd()
        }

	switch(cv){
	case 1:
	
		/**
 			* cd: 
 			* open the file specified with the command (cd) 
 			* A simple cd program for a simulated file system.
 			* Usage:
 			*   ./fss cd <file_name> ...
 			* @invokes the my_open function
 			*/


			my_open(argv[2],fh);
			break;
	

	case 2:
 			/* cd..
 			* close the current and set the pointer pointing to the parent of current root. 
 			* A simple cd.. program for a simulated file system.
 			* Usage:
 			*   ./fss cd.. 
 			* @invokes the  my_close function
 			*/


			my_close(sb.s_current_root,fh);

			break;
	case 3:
			//del
			handle=my_open(argv[2],fh);
			my_delete(handle,fh);
			sb.s_current_root=sb.s_root;
			set_super_block(&sb,fh,&i);	
			break;
	case 4:
			
			


			/**
 			* mkdir
 			* create a new file in the current_parent or in the specified parent. 
 			* A simple mkdir.. program for a simulated file system.
 			* Usage:
 			*   ./fss mkdir 
 			* @invokes the  my_create function, 
 			*/
			//break;
			//to create dir/file
			//handle=my_create(argv[2],0,fh);

			//for dir
				handle=my_create(argv[2],1,fh);   //to make create dir here.
				
				while(i<DENTRIES_PER_BLOCK){
    			    		((dentry_ptr)buffer+i)->inode_no= -1;
  				      	//printf("\n%d %s",((dentry_ptr)buffer+i)->inode_no,((dentry_ptr)buffer+i)->d_name);
  				      	i++;
			       }
				 my_write(handle,buffer,BLOCK_SIZE,fh);
 			break;
	case 5:
			//for file
			//strcpy(,"ANY NAME");
			//	my_write(handle,buffer,BLOCK_SIZE,fh);
			handle=my_create(argv[2],0,fh);
			//memset(buffer,'\0',BLOCK_SIZE);
			//	my_read(0,buffer,BLOCK_SIZE,fh);
			//	printf("%s",buffer);print file
			//	while(i<DENTRIES_PER_BLOCK){
			//	if(((dentry_ptr)buffer+i)->inode_no!= -1)
			//	printf("\n%d %s",((dentry_ptr)buffer+i)->inode_no,((dentry_ptr)buffer+i)->d_name);	
			//	i++;
			//	}
				break;
	
      case 6:

			/**
 			* ls
 			* lists the contents of the data block.
 			* A simple ls program for a simulated file system.
 			* Usage:
 			*   ./fss ls
 			* @invokes the  my_read function,
 			*/
			i = 0;

			//for ls
			
			memset(buffer,'\0',BLOCK_SIZE);
			//printf("\n %d %s", sb.s_current_root,"Current rRoot");
			my_read(sb.s_current_root,buffer,sizeof buffer,fh);
			while(i<DENTRIES_PER_BLOCK)
			{
				 if(((dentry_ptr)buffer+i)->inode_no!= -1)
                              		printf("\n%d %s",((dentry_ptr)buffer+i)->inode_no,((dentry_ptr)buffer+i)->d_name);
                              		i++;
			}
                              		printf("\n");
			break;
	 case 7:

			/**
 			* cp
			* copies the contents of one file to the another file specified in the argument.
 			* A simple cp program for a simulated file system.
 			* Usage:
 			*   ./fss cp <file_source> <file_destination>
 			* @invokes the  my_open my_read and my_close for the source file and my_open, my_write, my_close for the destination file 
 			*/


			
			//for cp(a,b)
			handle=my_open(argv[2],fh);
			my_read(handle,buffer,sizeof buffer,fh);
			my_close(handle,fh);
			handle=my_create(argv[3],0,fh);
			my_write(handle,buffer,BLOCK_SIZE,fh);
			my_close(handle,fh);
			//sb.s_current_root = i;
                      	//set_super_block(&sb,fh,&i);

			break;

	case 8:
			 memset(buffer,'\0',BLOCK_SIZE);
		      	handle = my_open(argv[2],fh);
		      	//printf("\n %d %s",handle,"Check");
			my_read(handle,buffer,BLOCK_SIZE,fh);
		      	printf("%s",buffer);//print file
		     	my_close(handle,fh);
			//sb.s_current_root = i;
                      	//set_super_block(&sb,fh,&i);
			printf("\n");
			break;
 case 9:
		    	i =sb.s_current_root;
                      	handle = my_open(argv[2],fh);
			printf("Enter data:----\n");
			while(c!='#')
			{
				scanf("%c",&c);
				buffer[u]=c;
				u++;
			}
			buffer[u]='\0';
			//scanf("\n%s",buffer);
                      	my_write(handle,buffer,BLOCK_SIZE,fh);
                      	printf("\n%s",buffer);//print file
			my_close(handle,fh);
			//sb.s_current_root = i;
			printf("\n");
                      	//set_super_block(&sb,fh,&i);
                        break;

case 13:
memset(buffer,'\0',sizeof buffer);
handle = sb.s_current_root;//printf("%d",handle);
 while(handle != 0){
	map_position(handle,I_BLOCK,READ_FSS,&in,fh);
	strcat(buffer,in.d_name);
	strcat(buffer,"/");
	handle = in.parent_inode_no;//printf("%d",handle);
}
printf("%s",buffer);
break;
//	case 8:
			/**
 			* cut
 			* moves a file along with the contents of one file to the another file specified in the argument.
	 		* A simple cp program for a simulated file system.
 			* Usage:
 			*   ./fss cut <file_source> <file_destination>
 			* @invokes the  my_open my_read and my_close for the source file and my_open, my_write, my_close for the destination file
 			*/


			//for mv(a,b)
	/*		handle=my_open(argv[2],0,fh);
			my_read(handle,buffer,sizeof buffer);
			my_close(handle);  //not to delete open files
			handle_child=my_open(argv[3],0,fh);
			//my_write(fh,buffer,sizeof buffer);
			my_close(fh);
	
			break;

	}	
*/	
	//super_block_operation();

	close(fh);
	return 0;

}


//for cd..
//	my_close(sb.s_current_root,fh);

//del
//my_delete(3,fh);

//to create dir/file
	//handle=my_create(argv[2],0,fh);

//for dir
//	handle=my_create(argv[2],1,fh);
//	 while(i<DENTRIES_PER_BLOCK){
    //    if(((dentry_ptr)buffer+i)->inode_no!= -1)
  //      printf("\n%d %s",((dentry_ptr)buffer+i)->inode_no,((dentry_ptr)buffer+i)->d_name);
  //      i++;
//        }
//	my_write(handle,buffer,BLOCK_SIZE,fh);

//for file
	//strcpy(buffer,"ANY NAME");
//	my_write(handle,buffer,BLOCK_SIZE,fh);
	
	//memset(buffer,'\0',BLOCK_SIZE);
//	my_read(0,buffer,BLOCK_SIZE,fh);
//	printf("%s",buffer);print file
//	while(i<DENTRIES_PER_BLOCK){
//	if(((dentry_ptr)buffer+i)->inode_no!= -1)
//	printf("\n%d %s",((dentry_ptr)buffer+i)->inode_no,((dentry_ptr)buffer+i)->d_name);	
//	i++;
//	}

//for ls
//	my_read(sb.get_current_root);

//for cp(a,b)
//	fh=my_open(a,0);
//	my_read(fh,buffer,sizeof buffer);
//	my_close(fh);
//	fh=my_open(b,0);
//	my_write(fh,buffer,sizeof buffer);
//	my_close(fh);

//for mv(a,b)
//	fh=my_open(a,0);
//	my_read(fh,buffer,sizeof buffer);
//	my_close(fh);  //not to delete open files
//	my_delete(fh);
//	fh=my_open(b,0);
//	my_write(fh,buffer,sizeof buffer);
//	my_close(fh);
	
	
	
	//super_block_operation();

	close(fh);
	return 0;

}
