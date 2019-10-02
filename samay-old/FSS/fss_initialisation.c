#include "fss_initialisation.h"
		int mount_fss()
		{
				char buf[DISK_STORE];
	int n = 0;
	int fh=-1,i,j;
	struct inode in;struct dentry d;
		  memset(buf,'0',sizeof buf);
		fh = open( FSS_FILENAME, O_RDWR|O_CREAT,0777 );
		
		lseek(fh,BLOCK_SIZE*(INODE_COUNT+1),SEEK_SET);

		write(fh,buf,sizeof(buf)-BLOCK_SIZE*(INODE_COUNT+1));
		in.inode_no = 0;
		in.i_size = SIZE_OF_INODE_BLOCK;
		in.ref_count = 0;
		in.d_block[0]=0;//BLOCK_SIZE*(INODE_COUNT+2);
		for(i = 1; i < 10; i++){
			in.d_block[i]=FILE_SYSTEM_NULL;
		}
		lseek(fh,BLOCK_SIZE,SEEK_SET);
		write(fh,&in,BLOCK_SIZE);
		memset(buf,'0',sizeof buf);
		for(i = 1; i < INODE_COUNT;i++){
			in.inode_no = i;
			in.i_size = SIZE_OF_INODE_BLOCK;
			in.ref_count = 0;
			for(j =0;j<10;j++){
				in.d_block[j]=FILE_SYSTEM_NULL;
			}
			lseek(fh,BLOCK_SIZE*(1+i),SEEK_SET);
			write(fh,&in,BLOCK_SIZE);
		}
//		lseek(fh,(INODE_COUNT+1)*BLOCK_SIZE,SEEK_SET);
		for(i =1; i < DATABLOCK_COUNT;i++){
			
			lseek(fh,(INODE_COUNT+1+i)*BLOCK_SIZE,SEEK_SET);
			write(fh,buf,BLOCK_SIZE);
		}
		d.inode_no = FILE_SYSTEM_NULL;
		memset(d.d_name,'\0',MAX_FILE_NAME_LEN);
		lseek(fh,(INODE_COUNT+1)*BLOCK_SIZE,SEEK_SET);
		for(i =0;i<DENTRIES_PER_BLOCK;i++)
		write(fh,&d,sizeof d);
		sb.s_inodes_count=INODE_COUNT  ; 
                sb.s_blocks_count=TOTAL_BLOCKS  ;
                sb.s_free_datablock_count=TOTAL_BLOCKS-(INODE_COUNT+1)-1; 
                sb.s_free_inode_count=INODE_COUNT-1 ;
                sb.s_first_data_block=0; 
                sb.s_mtime=0;   
                sb.s_first_ino=0 ; 
                sb.s_inode_size=0 ;
  		sb.s_root=0;
                sb.s_current_root=0;
		memset(sb.s_inode_bmp,255,INODE_COUNT/8);
                memset(sb.s_datablock_bmp,255,DATABLOCK_COUNT/8);
		sb.s_inode_bmp[0]=sb.s_inode_bmp[0]&127;//
		sb.s_datablock_bmp[0]=sb.s_datablock_bmp[0]&127;//254
		lseek(fh,0,SEEK_SET);
		write(fh,&sb,SIZE_OF_SUPER_BLOCK);
		close(fh);

			return;
		}
