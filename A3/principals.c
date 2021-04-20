/*Zachery Abbas
1019463
abbasz*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerfile.h"



int numprincipal(FILE* fp){

    int count = 0;
    char* token;
    int numcolons = 0;
    char buf[1000];
    char delim[5] = "\t";

    while(fgets(buf, 1000, fp) != NULL){
      numcolons =  0;

        token = strtok(buf, delim);

        while(token != NULL){


            if(numcolons == 3){

                    if(strcmp(token, "actor") == 0 || strcmp(token, "actress") == 0){
                        count++;
                    }

            }
              numcolons++;
            token = strtok(NULL, delim);

        }

    }
    return count;
}
struct title_principals * principalarry(FILE* fp, int len){
    char* token;
    int numcolons = 0;
    char buf[100000];
    char delim[5] = "\t";
    char nconstbuf1[50];
    char tconstbuf2[50];
    char primarybuf3[1000];
    struct title_principals * names = calloc(len, sizeof(struct name_basics));
    struct title_principals * node = NULL;
    int i = 0;

    fseek(fp, 0, SEEK_SET);
      while(fgets(buf, 1000, fp) != NULL){

        numcolons = 0;

        token = strtok(buf, delim);
        strcpy(tconstbuf2,token);


        while(token != NULL){


          if(numcolons == 2){
            strcpy(nconstbuf1, token);
          }

          if(numcolons == 4){
            strcpy(primarybuf3, token);
          }

            if(numcolons == 3){
                    if(strcmp(token, "actor") == 0){
                      node = newnode2();
                      strcpy(node->nconst, nconstbuf1);
                      strcpy(node->tconst, tconstbuf2);
                      strcpy(node->characters, primarybuf3);
                      names[i].nconst = malloc(sizeof(char) * 50);
                      strcpy(names[i].nconst, node->nconst);
                      names[i].tconst = malloc(sizeof(char) * 50);
                      strcpy(names[i].tconst, node->tconst);
                      names[i].characters = malloc(sizeof(char) * 1000);
                      strcpy(names[i].characters, node->characters);
                      i++;
                    }
                }

            numcolons++;
            token = strtok(NULL, delim);
          }
        }


    return names;

}
