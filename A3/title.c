/*Zachery Abbas
1019463
abbasz*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerfile.h"

int numtitle(FILE* fp){

    int count = 0;
    char* token;
    int flag = 0;
    int numcolons = 0;
    char buf[1000];
    char delim[5] = "\t";

    while(fgets(buf, 1000, fp) != NULL){
      numcolons = 0;
      flag = 0;
        token = strtok(buf, delim);

        while(token != NULL){


            if((numcolons == 1)){

                    if(strcmp(token, "movie") == 0){
                        flag = 1;
                    }

            }

            if((numcolons == 4)){

                    if(strcmp(token, "0") == 0){
                      if(flag == 1)  count++;
                    }

            }

            numcolons++;
            token = strtok(NULL, delim);

        }



    }
    return count;
}
struct title_basics * titlearray(FILE* fp, int len){
    char* token;
    int numcolons = 0;
    char buf[1000];
    int flag = 0;
    char delim[5] = "\t";
    char tconstbuf1[50];
    char primarybuf2[10000];
    struct title_basics * title = calloc(len, sizeof(struct name_basics));
    int i = 0;


       fseek(fp, 0, SEEK_SET);
      while(fgets(buf, 1000, fp) != NULL){

       numcolons = 0;
        flag = 0;

        token = strtok(buf, delim);
        strcpy(tconstbuf1,token);


        while(token != NULL){
            if((numcolons == 1))
            {
                if(strcmp(token, "movie") == 0)
                {
                  flag = 1;
                }
              }

              if((numcolons == 2) && flag == 1){
              strcpy(primarybuf2, token);
            }

              if((numcolons == 4))
              {
                  if(strcmp(token, "0") == 0)
                  {
                    if(flag == 1)
                    {
                      title[i].tconst = malloc(sizeof(char) *50);
                      strcpy(title[i].tconst, tconstbuf1);
                      title[i].primaryTitle = malloc(sizeof(char) * 1000);
                      strcpy(title[i].primaryTitle, primarybuf2);
                      i++;
                    }
                  }
                }

          numcolons++;
            token = strtok(NULL, delim);
        }

    }

    return title;

}
