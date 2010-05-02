bsp: main.c useful.h list.h
	gcc -Wall -o bsp main.c

debug: main.c useful.h list.h
	gcc -Wall -g -o bsp main.c
