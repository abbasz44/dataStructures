/*Zachery Abbas
1019463
abbasz@uoguelph.ca */
#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 256

long elements;
int ds_create_array();
int ds_init_array();
int ds_replace( int value, long index );
int ds_insert( int value, long index );
int ds_delete( long index );
int ds_swap( long index1, long index2 );
long ds_find( int target);
int ds_read_elements( char *filename );
int ds_finish_array();
