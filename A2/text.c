/*Zachery Abbas
  abbasz@uoguelph.ca
  1019463
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "text.h"

struct node_struct *build_list( char * line )
{
  struct node_struct *head, **ptr;
  char string[50];
  char tmp[267];
  int startcount = 0;
  int endcount = 0;

  strcpy(tmp, line);

  ptr = &head;

  for (;*line;line++)
  {
     *ptr = malloc( sizeof( struct node_struct ) );

     if(*line != ' ' && *line != '\n' && (*line != '!' || *line != ';' || *line != '.' || *line != ',' || *line != '"'))
        {
            endcount++;
        } else {
            customstrcpy(tmp, startcount, endcount + 1, string);
            startcount = endcount + 1;
            endcount++;

                (*ptr)->data = string;
                ptr = &((*ptr)->next);
        }

    }

  *ptr = NULL;
  return head;
}
void customstrcpy(char* line, int start, int end, char* str){
    int i;
    int counter = 0;

    for(i= start; i < end; i++){
        str[counter] = line[i];
        counter++;
    }

    str[counter] = '\0';
}
void print_list( struct node_struct *ptr )
{
  while (ptr)
  {
    printf( "%s\n", (char*)ptr->data );
    ptr = ptr->next;
  }
  printf( "\n" );
}

int compar( const void *a, const void *b ){
  struct node_struct **ptr_a, **ptr_b;

  ptr_a = (struct node_struct **)a;
  ptr_b = (struct node_struct **)b;

  return strcmp((char*)(*ptr_a)->data,(char*)(*ptr_b)->data);
}
/*MERGE SORT SORTED MERGE AND FRONTBACKSPLIT were taken from https://www.geeksforgeeks.org/merge-sort-for-linked-list/ */

void MergeSort(struct node_struct** headRef){

    struct node_struct* var = *headRef;
    struct node_struct* a;
    struct node_struct* b;

    if ((var == NULL) || (var->next == NULL)) {
        return;
    }

    FrontBackSplit(var, &a, &b);
    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}
struct node_struct* SortedMerge(struct node_struct* a, struct node_struct* b){
    struct node_struct* result = NULL;

    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
    return (result);
}

void FrontBackSplit(struct node_struct* source, struct node_struct** frontRef, struct node_struct** backRef){
   struct node_struct* fast;
   struct node_struct* slow;
   slow = source;
   fast = source->next;

   while (fast != NULL) {
       fast = fast->next;
       if (fast != NULL) {
           slow = slow->next;
           fast = fast->next;
       }
   }

   *frontRef = source;
   *backRef = slow->next;
   slow->next = NULL;
}

struct node_struct *txt2words( FILE *fp ){

    char * line = malloc(sizeof(char)*257);
    struct node_struct * list;

    while(fgets(line, 256, fp)!=NULL){
        /*printf("%s\n", line);*/
        list = build_list(line);
    }

    return list;

}

int length(struct node_struct *list){
    int len = 0;

    while(list != NULL){
        len++;
        list = list->next;
    }
    return len;
}
struct node_struct*search(struct node_struct *list, char *target, int(*compar)(const void*,const void*)){
    int len = length(list);
    int i = 0;
    struct node_struct *toreturn = 0;
    int j = 0;
    int buf = 0;
    char *temp = 0;

    for(i=0;i <= len; i++){
        temp = list[i].data;
        buf = compar(temp, target);

        if(buf == 0){
            toreturn[j].data = &(list[i].data);
            j++;
        }
    }
    return toreturn;
}
struct node_struct *copy(struct node_struct *start, struct node_struct *end){
    struct node_struct * temp = end;
    struct node_struct *head = NULL;

    strcpy(head->data, start->data);
    head->next = NULL;

    while(strcmp((char *)temp->data, (char *)start->data)!=0){
        head->next = start->next;
        strcpy((char *)head->data, (char *)start->data);
    }
    return head;
}
void ftext( FILE *fp, struct node_struct *list ){
    int counter = 0;
    int len = length(list);
    int i = 0;

    for(i=0;i <= len; i++){
        if(counter != 80){
            if((strcmp((char *)list[i].data, ",") == 0 || strcmp((char *)list[i].data, ";") == 0 || strcmp((char *)list[i].data, "!") == 0 ||strcmp((char *)list[i].data, """") == 0 ||strcmp((char *)list[i].data, ".") == 0) && (strcmp((char *)list[i+1].data, ",") == 0 ||strcmp((char *)list[i+1].data, ";") == 0 || strcmp((char *)list[i+1].data, "!") == 0 ||strcmp((char *)list[i + 1].data, """") == 0 || strcmp((char *)list[i+1].data, ".") == 0)){
                printf(" %s ", (char *)list[i].data);

            }
            else if(isalpha((char *)(list[i].data))|| isdigit((int *)(list[i].data))){
                printf(" %s ", (char *)list[i].data);
            }
        }
        counter++;

        if(counter == 80){
            if((strcmp((char *)list[i].data, ",") == 0 || strcmp((char *)list[i].data, ";") == 0 || strcmp((char *)list[i].data, "!") == 0 ||strcmp((char *)list[i].data, """") == 0 ||strcmp((char *)list[i].data, ".") == 0) && (strcmp((char *)list[i+1].data, ",") == 0 ||strcmp((char *)list[i+1].data, ";") == 0 || strcmp((char *)list[i+1].data, "!") == 0 ||strcmp((char *)list[i + 1].data, """") == 0 || strcmp((char *)list[i+1].data, ".") == 0)){
                printf("%s\n", (char *)list[i].data);

            }
            else if(isalpha((char *)(list[i].data))|| isdigit((int *)(list[i].data))){
                printf("%s\n", (char *)list[i].data);
            }
        }
        counter++;
    }

}
struct node_struct *sort( struct node_struct *list, int(*compar)(const void*,const void*)){
    struct node_struct * sorted;

    sorted = list;
    MergeSort(&sorted);



    return sorted;
}
void remove_repeats(struct node_struct *list, int(*compar)(const void*,const void*)){
    int i= 0;
    int len = length(list);

    for(i = 0; i <= len; i++){
        if(compar(list[i].data, list[i+1].data) == 0){
            free(list[i+1].data);
        }
    }
}
void free_list( struct node_struct *list, int free_data){

    if(free_data != 0)
    {
        struct node_struct * temp = list;

        while(list != NULL)
        {
            list = list->next;
            free(list->data);
        }

        free(temp);
    }

    free(list);

}
