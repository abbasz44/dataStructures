/*Zachery Abbas
1019463
abbasz@uoguelph.ca */
#include "ds_memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ds_file_structds_file;
struct ds_counts_struct ds_counts;
int ds_create( char *filename, long size ){

    struct ds_blocks_struct header;
    char *teststr = calloc(20, sizeof(*teststr));
    char *str = calloc(size, sizeof(*str));

    header.length = size;
    header.start = 0;
    header.alloced = 0;

    ds_file.block[0] = header;

    if(filename == NULL){
        return 1;
    }

    ds_file.fp= fopen(filename, "w");
    if(ds_file.fp == NULL){

        return 1;
    }

    fwrite((const void*)&(header.start), sizeof(int), 1, ds_file.fp);
    fwrite((const void*)&(header.length), sizeof(int),  1, ds_file.fp);
    fwrite((const void*)&(header.alloced), sizeof(char), 1, ds_file.fp);

    return 0;
}
int ds_init(char *filename){
    if(filename == NULL){
        return 1;
    }
    FILE *ptr = fopen(filename,"wb+");
    if(ptr == NULL){
        printf("NULL\n");
        return 1;
    }


    ds_file.fp = ptr;
    ds_counts.reads = 0;
    ds_counts.writes = 0;

    return 0;
}

long ds_malloc (long amount){

    int i = 0;
    struct ds_blocks_struct temp;
    int orignal;
    int val = -1;

    for(i =0;i<MAX_BLOCK; i++){
        temp = ds_file.block[i];

        if(temp.length>=amount&&temp.alloced ==0){
            orignal = temp.length;
            temp.length = amount;
            temp.alloced = 1;
            ds_file.block[i] = temp;
            val = temp.start;
        }
    }
    for(i=0; i<MAX_BLOCK; i++){
        temp = ds_file.block[i];
        if(temp.length == 0){
            temp.start = temp.start + amount;
            temp.length = orignal - amount;
    }
        }
    return val;

}
void ds_free (long start){
    int i;


    for(i =0; i <= MAX_BLOCK;i++){
        ds_file.block[i];
        if(ds_file.block[i].start == start){
            ds_file.block[i].alloced = 0;
        }
    }


}
void *ds_read(void *ptr, long start, long bytes){

    int offset = ds_file.block[0].length + start;

    if(ds_file.fp == NULL || ptr == NULL){
        return NULL;
    }

    fseek(ds_file.fp, offset, SEEK_SET);
    fread(ptr, offset, 1, ds_file.fp);


    ds_counts.reads++;

    return ptr;
}
long ds_write(long start, void *ptr, long bytes){
    int offset = ds_file.block[0].length + start;

    if(ds_file.fp == NULL || ptr == NULL){
        /*printf("NULL\n");*/
        return 1;
    }

    fseek(ds_file.fp, offset, SEEK_SET);
    fwrite(ptr, 1, bytes, ds_file.fp);

    ds_counts.writes++;

    return start;
}
int ds_finish(){

    int i;

    for(i = 0; i <= MAX_BLOCK; i++){
        ds_write(ds_file.block[i].start, &(ds_file.block[i]), sizeof(ds_file.block[i]));

    }

    printf("reads: %d\n", ds_counts.reads);
    printf("writes: %d\n", ds_counts.writes);
    if(ds_file.fp == NULL)return 1;


    fclose(ds_file.fp);
    return 0;
}
