#ifndef __DENTRY_OPERATION_H
#define __DENTRY_OPERATION_H

//#include "common.h"
#include "dentry.h"
//#include "inode.h"


/*
 *Map algo: simple
 *Club together directories/files with same starting alphabet
 *SPACE_PER_CHARACTER = no_of_files then put the entry in the next block's vacant
 *space
 *if this space gets full, we will leave that aside for time being
 */
/* enum INVALID_CHARS{
	INVALID_A = 124,
	INVALID_B = 63
};

/*
char valid_char[] = {'A','B','C','D'};
int invalid_char_ascii[] = { 63,124};
*/


int d_validate(char *qstr, int);
int d_hash(/*struct dentry *, */char *qstr,void* d_subdirs );
int d_compare(void *, char *qstr );
int d_delete(void*,int);
void d_release(dentry_ptr);
int d_iput(dentry_ptr, void*,char*);
int d_pos(char *,void * );

#endif
