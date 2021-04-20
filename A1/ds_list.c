/*Zachery Abbas
1019463
abbasz@uoguelph.ca */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ds_list.h"
#include "ds_memory.h"
#include "ds_array.h"

void ds_create_list(){
    ds_init("list.bin");
    ds_malloc(-1);
    ds_finish();

}
int ds_init_list(){

    ds_init("list.bin");

    return 0;
}
int ds_replace_list( int value, long index ){

    int temp = value;

    ds_write(index, &temp, sizeof(int));

    return 0;
}
int ds_insert_list( int value, long index ){
    int temp;
    int buf;
    long indx;
    int i;

    fseek(ds_file.fp, index, SEEK_SET);

    ds_read(&buf, index, sizeof(int));
    fseek(ds_file.fp, index, SEEK_SET);
    ds_write(index, &value, sizeof(value));

    indx = index + sizeof(int);
    fseek(ds_file.fp, MAX_ELEMENTS-1, SEEK_SET);

    for(i = MAX_ELEMENTS; i>indx; i--){
        fread(&temp, sizeof(int), 1, ds_file.fp);
        fseek(ds_file.fp, i, SEEK_SET);
        fwrite(&i, sizeof(int), 1, ds_file.fp);


    }
    index++;


    return 0;
}
int ds_delete_list( long index ){
    int i;

    for(i = index; i < MAX_BLOCK;i++){
        ds_file.fp[i] = ds_file.fp[i+1];

    }
    index--;
    return 0;
}
int ds_swap_list( long index1, long index2 ){
    int temp;
    int temp2;

    fseek(ds_file.fp, index1, SEEK_SET);
    fread(&temp, sizeof(int), 1, ds_file.fp);
    fseek(ds_file.fp, index2, SEEK_SET);
    fread(&temp2, sizeof(int), 1, ds_file.fp);
    fseek(ds_file.fp, index2, SEEK_SET);
    fwrite(&temp, sizeof(int), 1, ds_file.fp );
    fseek(ds_file.fp, index1, SEEK_SET);
    fwrite(&temp2, sizeof(int), 1, ds_file.fp);

    return 0;
}
long ds_find_list( int target){
    int i;
    int temp;


    for(i = 0; i < MAX_ELEMENTS; i++){
        fseek(ds_file.fp, i, SEEK_SET);
        fread(&temp, sizeof(int), 1, ds_file.fp);
        if(temp == target){
        return i;

        }
    }
    return 0;
}
int ds_read_elements_list( char *filename ){

     FILE *fptr;
     int temp;
     int i;
     int end;

     fptr = fopen(filename, "r");
     rewind(fptr);

     fseek(fptr, 0, SEEK_END);
     end = ftell(fptr);
     rewind(fptr);

     for(i=0; i < end; i++){
         fseek(fptr, sizeof(int)*i,SEEK_SET);
         fscanf(fptr, "%d", &temp);
         ds_insert(temp, i);

     }

     return 0;
}
int ds_finish_list(){

    ds_finish();

    return 0;
}
