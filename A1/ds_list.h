/*Zachery Abbas
1019463
abbasz@uoguelph.ca */
#include <stdio.h>
#include <stdlib.h>

struct ds_list_item_struct {
    int item;
    long next;
};
void ds_create_list();
int ds_init_list();
int ds_replace_list( int value, long index );
int ds_insert_list( int value, long index );
int ds_delete_list( long index );
int ds_swap_list( long index1, long index2 );
long ds_find_list( int target);
int ds_read_elements_list( char *filename );
int ds_finish_list();
