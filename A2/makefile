all: add

add: main.c text.c 
	gcc -ansi -Wall -pedantic main.c -o main.o -c
	gcc -ansi -Wall -pedantic text.c -o text.o -c
	gcc -o test main.o text.o
clean:
	rm *.o
	rm test
