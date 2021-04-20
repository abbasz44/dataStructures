all: add

add: main.c ds_memory.c ds_array.c ds_list.c 
	gcc -ansi -Wall -pedantic main.c -o main.o -c
	gcc -ansi -Wall -pedantic ds_memory.c -o ds_memory.o -c
	gcc -ansi -Wall -pedantic ds_array.c -o ds_array.o -c
	gcc -ansi -Wall -pedantic ds_list.c -o ds_list.o -c
	gcc -o test main.o ds_memory.o ds_array.o ds_list.o

clean:
	rm *.o
	rm test

