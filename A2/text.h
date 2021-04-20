/*Zachery Abbas
  abbasz@uoguelph.ca
  1019463
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node_struct{
    void *data;
    struct node_struct *next;
    };
struct node{
      char letter;
      struct node *next;
    };
void customstrcpy(char* line, int start, int end, char* str);
void FrontBackSplit(struct node_struct* source, struct node_struct** frontRef, struct node_struct** backRef);
struct node_struct* SortedMerge(struct node_struct* a, struct node_struct* b);
void MergeSort(struct node_struct** headRef);
struct node_struct *build_list( char * line );
void print_list( struct node_struct *ptr );
int compar( const void *a, const void *b );
/*int mergesort_r(int left, int right, struct node_struct *list);
int mergesort(struct node_struct *list, int length);*/
struct node_struct *txt2words( FILE *fp );
struct node_struct*search( struct node_struct *list, char *target, int(*compar)(const void*,const void*));
struct node_struct *copy( struct node_struct *start, struct node_struct *end );
void ftext( FILE *fp, struct node_struct *list );
struct node_struct *sort( struct node_struct *list, int(*compar)(const void*,const void*));
void remove_repeats(struct node_struct *list, int(*compar)(const void*,const void*));
int length( struct node_struct *list);
void free_list( struct node_struct *list, int free_data);
