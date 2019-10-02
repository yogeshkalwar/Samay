# makefile for fss program

fss: global.o  
	gcc -o fss  main.c global.o dentry_operations.o inode_operation.o super_operations.o fss_initialisation.o 

global.o:dentry_operations.o
	gcc -c global.c  

dentry_operations.o:inode_operation.o	
	gcc -c dentry_operations.c

inode_operation.o:super_operation.o
	gcc -c inode_operation.c

super_operation.o:fss_initialisation.o	
	gcc -c super_operations.c

fss_initialisation.o:clean
	gcc -c fss_initialisation.c

clean:
	rm -f *.o fss core

