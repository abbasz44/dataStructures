all: add

add:a4.c main.c helper.c
	gcc -g -ansi -Wall -pedantic a4.c -o a4.o -c
	gcc -g -ansi -Wall -pedantic main.c -o main.o -c
	gcc -g -ansi -Wall -pedantic helper.c -o helper.o -c
	gcc -g -o a4  a4.o main.o helper.o
clean:
	rm *.o
	rm a4
