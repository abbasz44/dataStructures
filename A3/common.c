/*Zachery Abbas
1019463
abbasz*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerfile.h"

FILE* openfile(char * filename){
    FILE *fp;

    fp = fopen(filename, "r");
    return fp;
}
struct name_basics* newnode(){
    struct name_basics * n = malloc(sizeof(struct name_basics));
    n->nconst = malloc(sizeof(char)*50);
    n->primaryName = malloc(sizeof(char)*1000);

    return n;
}
struct title_basics* newnode1(){
    struct title_basics* t= malloc(sizeof(struct title_basics));
    t->tconst = malloc(sizeof(char)*50);
    t->primaryTitle = malloc(sizeof(char)*100);

    return t;
}
struct title_principals* newnode2(){
    struct title_principals* t= malloc(sizeof(struct title_basics));
    t->nconst = malloc(sizeof(char)*50);
    t->tconst = malloc(sizeof(char)*50);
    t->characters = malloc(sizeof(char)*1000);

    return t;
}

struct name_basics_tree* newtreenode(struct name_basics elem){
    struct name_basics_tree * n = malloc(sizeof(struct name_basics_tree));
    n->nconst = malloc(sizeof(char)*50);
    n->primaryName = malloc(sizeof(char)*1000);
    strcpy(n->nconst, elem.nconst);
    strcpy(n->primaryName, elem.primaryName);
    n->left = NULL;
    n->right = NULL;

    return n;
}
struct title_basics_tree* newtreenode1(struct title_basics elem){
  struct title_basics_tree * n = malloc(sizeof(struct name_basics_tree));
  n->tconst = malloc(sizeof(char)*50);
  n->primaryTitle = malloc(sizeof(char)*1000);
  strcpy(n->tconst, elem.tconst);
  strcpy(n->primaryTitle, elem.primaryTitle);
  n->left = NULL;
  n->right = NULL;

  return n;
}
struct principal_basics_tree* newtreenode2(struct title_principals elem){
  struct principal_basics_tree * n = malloc(sizeof(struct principal_basics_tree));
  n->tconst = malloc(sizeof(char)*50);
  n->nconst = malloc(sizeof(char)*50);
  n->characters = malloc(sizeof(char)*1000);
  strcpy(n->characters, elem.characters);
  strcpy(n->tconst, elem.tconst);
  strcpy(n->nconst, elem.nconst);
  n->left = NULL;
  n->right = NULL;

  return n;
}
