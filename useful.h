#ifndef __USEFUL
#define __USEFUL

/**********\
 * HEADER *
\**********/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/***************\
 * DEFINITIONS *
\***************/
#define FALSE 0
#define TRUE 1
#define MAXSIZE 10000

/*************\
 * FUNCTIONS *
\*************/


/***********\
 * STRUCTS *
\***********/
struct letter_list{
    char curr;
    struct list_head list;
};

#endif
