/*Zachery Abbas
1019463
abbasz
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "a4.h"

int char2int( unsigned char c )
{
  if ( isupper(c) )
  {
    return (int)(c - 'A');
  }
  if ( islower(c) )
  {
    return (int)(c - 'a');
  }
  return 26;
}

/*got the algoritium from zybooks*/
int hash1(char* string, int hash_size){

  int result;
  int i;

  for (i = 0; i<strlen(string); i++){
    result += char2int(string[i]);
  }

  result = (result+1) % hash_size;
  return result;

 }
 int hash2(char* string, int hash_size){

   int result;
   int i;

   for (i = 0; i<strlen(string); i++){
     result += char2int(string[i]);
   }

   result = (result+1) % hash_size;
   return result;

  }
  int hash3(char* string, int hash_size){

    int result;
    int i;

    for (i = 0; i<strlen(string); i++){
      result += char2int(string[i]);
    }

    result = (result+1) % hash_size;
    return result;

   }
