/*Zachery Abbas
1019463
abbasz*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct name_basics{
char *nconst;
char *primaryName;
};

struct title_basics{
    char* tconst;
    char* primaryTitle;
};
struct title_principals{
    char* tconst;
    char* nconst;
    char* characters;
};
struct name_basics_tree{
  char *primaryName;
  char *nconst;
  struct name_basics_tree * left, * right;
};
struct title_basics_tree{
  char *primaryTitle;
  char *tconst;
  struct title_basics_tree * left, * right;
};
struct principal_basics_tree{
  char* nconst;
  char* tconst;
  char* characters;
  struct principal_basics_tree * left, *right;
};

int numtitle(FILE* fp);
int numprincipal(FILE* fp);
FILE* openfile(char * filename);
int numactors(FILE* fp);
struct name_basics * namearray(FILE * fp, int len);
struct name_basics* newnode();
struct title_basics* newnode1();
struct title_principals* newnode2();
struct title_principals * principalarry(FILE* fp, int len);
struct title_basics * titlearray(FILE* fp, int len);
struct name_basics_tree* newtreenode(struct name_basics elem);
struct title_basics_tree* newtreenode1(struct title_basics elem);
struct name_basics_tree* convert(int low, int high, struct name_basics* array);
struct name_basics_tree* convertb(struct name_basics * array, int j);
int cmpname(const void * a, const void * b);
void sortstructs(struct name_basics * array, int len);
char * searchName(struct name_basics_tree* root, char * key);
void inorder(struct name_basics_tree *root);
struct title_basics_tree* convert1(int low, int high, struct title_basics* array);
struct title_basics_tree* convertb1(struct title_basics * array, int j);
int cmpname1(const void * a, const void * b);
void inorder1(struct title_basics_tree *root);
void sortstructs1(struct title_basics * array, int len);
struct principal_basics_tree* convert2(int low, int high, struct title_principals* array);
int cmpname2(const void * a, const void * b);
void sortstructs2(struct title_principals * array, int len);
char * searchName2(struct principal_basics_tree* root, char * key);
void inorder2(struct principal_basics_tree *root);
struct principal_basics_tree* newtreenode2(struct title_principals elem);
struct principal_basics_tree* convertb2(struct title_principals * array, int j);
char * searchNconst(struct name_basics_tree* root, char * key);
char * searchTitle(struct title_basics_tree* root, char * key);
char * searchTconst(struct title_basics_tree* root, char * key);
char * searchTconst1(struct principal_basics_tree* root, char * key);
