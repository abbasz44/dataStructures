#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "a4.h"

int main(){
	struct array *arryptr;
  int col = 0;
	arryptr = read_records();

	build_hash(arryptr, 500000 );

  col = hash1(arryptr, 500000 );
  printf("col = %d\n", col);
return 0;
}
