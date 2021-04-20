all: add

add:a3.c common.c binary.c name.c title.c principals.c
	gcc -g -ansi -Wall -pedantic a3.c -o a3.o -c
	gcc -g -ansi -Wall -pedantic common.c -o common.o -c
	gcc -g -ansi -Wall -pedantic binary.c -o binary.o -c
	gcc -g -ansi -Wall -pedantic name.c -o name.o -c
	gcc -g -ansi -Wall -pedantic title.c -o title.o -c
	gcc -g -ansi -Wall -pedantic principals.c -o principals.o -c
	gcc -g -o a3  a3.o common.o binary.o name.o title.o principals.o
clean:
	rm *.o
	rm a3
