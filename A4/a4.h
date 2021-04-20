/*Zachery Abbas
1019463
abbasz
*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFFER_SIZE	1024

/*int collisions;
int duplicates;

struct record
{
  char *last_name;
  char *first_name;
  char *license_type;
  char *license_no;
  char *issue_date;
};

struct array
{
  struct record *arr;
  int nelements;
  struct record **hash;
  int hash_size;
};
int char2int( unsigned char c );
int str2int( char *s, int max );
struct array *read_records();
void build_hash( struct array *arrptr, int hash_size );
struct record *find( char *key, struct array *arrptr );
void build_hash1( struct array *arrptr, int hash_size );
void build_hash2( struct array *arrptr, int hash_size );
struct record *find_lastname( char *key, struct array *arrptr );
struct record *find_license_no( char *key, struct array *arrptr );
struct record *find_issue_date( char *key, struct array *arrptr );*/
int hash1(char* string, int hash_size);
int hash2(char* string, int hash_size);
int hash3(char* string, int hash_size);
int char2int( unsigned char c );
