/*Zachery Abbas
1019463
abbasz*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerfile.h"

int numactors(FILE* fp){

    int count = 0;
    char* token;
    char* actortoken;
    int numcolons = 0;
    char buf[1000];
    /*char delim[5] = "\t";*/

    while(fgets(buf, 1000, fp) != NULL){
        numcolons = 0;
        token = strtok(buf, "\t");

        while(token != NULL){

            if((numcolons % 4 == 0) && numcolons != 0){
              actortoken = strtok(token, ",");

                while(actortoken != NULL){
                    if(strcmp(actortoken, "actor") == 0 || strcmp(actortoken, "actress") == 0){
                        count++;

                    }
                    actortoken = strtok(NULL, ",");
                }
            }

            numcolons++;
            token = strtok(NULL, "\t");
        }

    }
    return count;
}
struct name_basics * namearray(FILE* fp, int len){
    char* token;
    char* actortoken;
    int numcolons = 0;
    char buf[1000];
    char delim[5] = "\t";
    char nconstbuf1[50];
    char primarybuf2[50];
    struct name_basics * names = calloc(len, sizeof(struct name_basics));
    struct name_basics * node = NULL;
    int i = 0;


    fseek(fp, 0, SEEK_SET);
      while(fgets(buf, 1000, fp) != NULL){

        numcolons = 0;

        token = strtok(buf, delim);
        strcpy(nconstbuf1,token);
        numcolons++;
        /*printf("%s\n", nconstbuf1);*/
        token = strtok(NULL, delim);
        strcpy(primarybuf2, token);
        numcolons++;
        /*printf("%s\n", primarybuf2);*/
        token = strtok(NULL, delim);

        while(token != NULL){

            if(numcolons  == 4){

               actortoken = strtok(token, ",");

                while(actortoken != NULL){

                    if((strcmp(actortoken, "actor") == 0) || (strcmp(actortoken, "actress") == 0)){

                      node = newnode();
                      strcpy(node->nconst, nconstbuf1);
                      strcpy(node->primaryName, primarybuf2);

                      names[i].nconst = malloc(sizeof(char) * 50);
                      strcpy(names[i].nconst, node->nconst);
                      names[i].primaryName = malloc(sizeof(char) * 100);
                      strcpy(names[i].primaryName, node->primaryName);

                      i++;
                    }

                    actortoken = strtok(NULL, ",");

                }
            }
              numcolons++;
            token = strtok(NULL, delim);

        }

    }

    return names;

}
