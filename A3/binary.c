/*Zachery Abbas
1019463
abbasz*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerfile.h"


struct name_basics_tree* convert(int low, int high, struct name_basics* array)
{

  struct name_basics_tree * root;
  int mid;

  if (low > high)
		return NULL;

 mid = (low + high) / 2;
 /*printf("arr nconst: %s, primaryName: %s\n", array[mid].nconst, array[mid].primaryName);*/

	root = newtreenode(array[mid]);
  /*printf("nconst: %s, primaryName: %s\n", root->nconst, root->primaryName);*/

	root->left = convert(low, mid - 1, array);
	root->right = convert(mid + 1, high, array);

  return root;
}

struct name_basics_tree* convertb(struct name_basics * array, int j){

	struct name_basics_tree *root = NULL;
  sortstructs(array, j);
	root = convert(0, j-1, array);


	return root;
}

int cmpname(const void * a, const void * b)
{
  struct name_basics * aa = (struct name_basics *)a;
  struct name_basics * bb = (struct name_basics *)b;

  return strcmp(aa->primaryName, bb->primaryName);
}

void sortstructs(struct name_basics * array, int len)
{
  /*seg faults here*/
  size_t arr_len  = len / sizeof(struct name_basics);
  qsort(array, arr_len, sizeof(struct name_basics), cmpname);
}

char * searchName(struct name_basics_tree* root, char * key)
{

    if (root == NULL || strcmp(root->primaryName, key) == 0)
       {
         /*char corr[50] = "HELLO";

        strcpy(corr, root->nconst);*/
         return root->nconst;
       }

    if (strcmp(root->primaryName, key) < 0)
       return searchName(root->right, key);


    return searchName(root->left, key);
}
char * searchNconst(struct name_basics_tree* root, char * key)
{

    if (root == NULL || strcmp(root->nconst, key) == 0)
       {
         /*char corr[50] = "HELLO";

        strcpy(corr, root->nconst);*/
         return root->primaryName;
       }

    if (strcmp(root->nconst, key) < 0)
       return searchNconst(root->right, key);


    return searchNconst(root->left, key);
}

void inorder(struct name_basics_tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        /*printf("%s\t %s \n", root->nconst, root->primaryName);*/
        inorder(root->right);
    }
}
struct title_basics_tree* convert1(int low, int high, struct title_basics* array)
{

  struct title_basics_tree * root;
  int mid;

  if (low > high)
		return NULL;

 mid = (low + high) / 2;
 /*printf("arr nconst: %s, primaryName: %s\n", array[mid].tconst, array[mid].primaryTitle);*/

	root = newtreenode1(array[mid]);
  /*printf("nconst: %s, primaryName: %s\n", root->tconst, root->primaryTitle);*/

	root->left = convert1(low, mid - 1, array);
	root->right = convert1(mid + 1, high, array);

  return root;
}
struct title_basics_tree* convertb1(struct title_basics * array, int j){

	struct title_basics_tree *root = NULL;
  sortstructs1(array, j);
	root = convert1(0, j-1, array);


	return root;
}
int cmpname1(const void * a, const void * b)
{
  struct title_basics * aa = (struct title_basics *)a;
  struct title_basics * bb = (struct title_basics *)b;

  return strcmp(aa->primaryTitle, bb->primaryTitle);
}
void sortstructs1(struct title_basics * array, int len)
{

  size_t arr_len  = len / sizeof(struct title_basics);
  qsort(array, arr_len, sizeof(struct title_basics), cmpname1);
}
void inorder1(struct title_basics_tree *root)
{
    if (root != NULL)
    {
        inorder1(root->left);
        /*printf("%s\t %s \n", root->tconst, root->primaryTitle);*/
        inorder1(root->right);
    }
}

char * searchTitle(struct title_basics_tree* root, char * key)
{

    if (root == NULL || strcmp(root->primaryTitle, key) == 0)
       {
         /*char corr[50] = "HELLO";

        strcpy(corr, root->nconst);*/
         return root->tconst;
       }

    if (strcmp(root->primaryTitle, key) < 0)
       return searchTitle(root->right, key);


    return searchTitle(root->left, key);
}
char * searchTconst(struct title_basics_tree* root, char * key)
{

    if (root == NULL || strcmp(root->tconst, key) == 0)
       {
         /*char corr[50] = "HELLO";

        strcpy(corr, root->nconst);*/
         return root->primaryTitle;
       }

    if (strcmp(root->tconst, key) < 0)
       return searchTconst(root->right, key);


    return searchTconst(root->left, key);
}
struct principal_basics_tree* convert2(int low, int high, struct title_principals* array)
{

  struct principal_basics_tree * root;
  int mid;

  if (low > high)
		return NULL;

 mid = (low + high) / 2;
 /*printf("arr nconst: %s, primaryName: %s\n", array[mid].nconst, array[mid].primaryName);*/

	root = newtreenode2(array[mid]);
  /*printf("nconst: %s, primaryName: %s\n", root->nconst, root->primaryName);*/

	root->left = convert2(low, mid - 1, array);
	root->right = convert2(mid + 1, high, array);

  return root;
}
struct principal_basics_tree* convertb2(struct title_principals * array, int j){

	struct principal_basics_tree *root = NULL;
  sortstructs2(array, j);
	root = convert2(0, j-1, array);


	return root;
}

int cmpname2(const void * a, const void * b)
{
  struct title_principals * aa = (struct title_principals *)a;
  struct title_principals * bb = (struct title_principals *)b;

  return strcmp(aa->nconst, bb->nconst);
}
void sortstructs2(struct title_principals * array, int len)
{
  /*seg faults here*/
  size_t arr_len  = len / sizeof(struct title_principals);
  qsort(array, arr_len, sizeof(struct title_principals), cmpname);
}

char * searchName2(struct principal_basics_tree* root, char * key)
{

    if (root == NULL || strcmp(root->nconst, key) == 0)
       {
         /*char corr[50] = "HELLO";

        strcpy(corr, root->nconst);*/
         return root->tconst;
       }

    if (strcmp(root->nconst, key) < 0)
       return searchName2(root->right, key);


    return searchName2(root->left, key);
}
char * searchTconst1(struct principal_basics_tree* root, char * key)
{

    if (root == NULL || strcmp(root->tconst, key) == 0)
       {
         /*char corr[50] = "HELLO";

        strcpy(corr, root->nconst);*/
         return root->nconst;
       }

    if (strcmp(root->tconst, key) < 0)
       return searchName2(root->right, key);


    return searchName2(root->left, key);
}



void inorder2(struct principal_basics_tree *root)
{
    if (root != NULL)
    {
        inorder2(root->left);
        /*printf("%s\t %s \n  %s\n", root->nconst, root->tconst, root->characters);*/
        inorder2(root->right);
    }
}
