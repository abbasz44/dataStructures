/*Zachery Abbas
1019463
abbasz*/
#include <stdio.h>
#include "headerfile.h"
int main(int argc, char **argv){
    int num;
  struct name_basics *actors;
  struct name_basics_tree * root;
  struct title_basics_tree* root1;
  struct principal_basics_tree* root2;
  struct title_basics *title;
  struct title_principals *prince;
  char buf[1000];
  char buf2[1000];
  int i = 0;
  int j = 0;
  int k = 0;
  char function[10];
  char * nconst = malloc(sizeof(char) * 50);
  char * tconst = malloc(sizeof(char) * 50);
  char * name = malloc(sizeof(char) * 50);
  char * titles = malloc(sizeof(char) * 50);
  char * titlecode = malloc(sizeof(char) * 50);
  char*  principalstring;
  char* namestring;
  char* titlestring;
  FILE* fp;
  namestring = malloc(strlen("/name.basics.tsv")+ strlen(argv[1])+1);
  strcpy(namestring, argv[1]);
  strcat(namestring, "/name.basics.tsv");


  fp=  openfile(namestring);


  num = numactors(fp);
   actors = namearray(fp, num);
   root = convertb(actors, num);

   for(k = 0; k<num;k++){
     free(actors[k].nconst);
     free(actors[k].primaryName);
   }
   free(actors);
   /*printf("%s %s\n", root->nconst, root->primaryName);*/
   printf("Searching for Keanu Reeves\n");
   name = searchName(root, "Keanu Reeves");
   printf("found: %s\n", name);

   inorder(root);
   titlestring = malloc(strlen("/title.basics.tsv")+ strlen(argv[1])+1);
   strcpy(titlestring, argv[1]);
   strcat(titlestring, "/title.basics.tsv");
   fp = openfile(titlestring);

   num = numtitle(fp);
  title = titlearray(fp, num);
  root1 = convertb1(title, num);
  for(k = 0; k<num;k++){
    free(title[k].tconst);
    free(title[k].primaryTitle);
  }
  free(title);
  /*printf("Searching for John Wick\n");
  titlecode = searchTitle(root1, "John Wick");
  printf("found: %s\n", titlecode);


  printf("Searching for Taika Waititi\n");
  name = searchName(root, "Taika Waititi");
  printf("found: %s\n", name);

  printf("Searching for Iron Man\n");
  titlecode = searchTitle(root1, "Iron Man");
  printf("found: %s\n", titlecode);*/



  /*inorder1(root1);
  printf("%s %s\n", root1->tconst, root1->primaryTitle);*/


    /*inorder2(root2);*/
     /*printf("%s\n", prince[0].characters);*/
    /*printf("%s %s\n", actors[0].nconst, actors[0].primaryName);*/
    /*printf("%s  %s\n", title[0].tconst, title[0].primaryTitle);*/


    /*printf("name or title?\n");
    printf("> ");
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%s", function);*/

    if(strcmp(function, "name") == 0)
    {
      i = 5;
      j = 0;
      while(buf[i] != '\0')
      {
        buf2[j] = buf[i];
        i++;
        j++;
      }

      buf2[j] = '\0';

      principalstring = malloc(strlen("/title.principals.tsv")+ strlen(argv[1])+1);
      strcpy(principalstring, argv[1]);
      strcat(principalstring, "/title.principals.tsv");

      fp = openfile("data/title.principals.tsv");

        num = numprincipal(fp);
        prince = principalarry(fp,num);
        root2 = convertb2(prince,num);
        for(k = 0; k<num;k++){
          free(prince[k].tconst);
          free(prince[k].nconst);
          free(prince[k].characters);

        }
        free(prince);

      nconst = searchName(root, buf2);
      printf("found: %s\n", nconst);
      tconst = searchName2(root2, nconst);
      printf("found: %s\n", tconst);
      titles = searchTitle(root1, tconst);
      printf("title: %s\n", titles);

    }


    if(strcmp(function, "title") == 0)
    {
      i = 6;
      j = 0;
      while(buf[i] != '\0')
      {
        buf2[j] = buf[i];
        i++;
        j++;
      }

      buf2[j] = '\0';

      fp = openfile("data/title.principals.tsv");

        num = numprincipal(fp);
        prince = principalarry(fp,num);
        root2 = convertb2(prince,num);
        for(k = 0; k<num;k++){
          free(prince[k].tconst);
          free(prince[k].nconst);
          free(prince[k].characters);

        }
        free(prince);


      tconst = searchTitle(root1, buf2);
      printf("found: %s\n", tconst);
      nconst = searchName2(root2, tconst);
      printf("found: %s\n", nconst);
      name = searchName(root, nconst);
      printf("found: %s\n", name);

    }
    printf("Searching for John Wick\n");
    titlecode = searchTitle(root1, "John Wick");
    printf("found: %s\n", titlecode);


    printf("Searching for Taika Waititi\n");
    name = searchName(root, "Taika Waititi");
    printf("found: %s\n", name);


    printf("Searching for Iron Man\n");
    titlecode = searchTitle(root1, "Iron Man");
    printf("found: %s\n", titlecode);

    printf("Searching for Avengers: Endgame\n");
    name = searchTitle(root1, "Avengers: Endgame");
    printf("found: %s\n", name);

    printf("Searching for Chris Evans\n");
    name = searchName(root, "Chris Evans");
    printf("found: %s\n", name);

    





    fclose(fp);
  return 0;
}
