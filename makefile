all: juego

juego: main.o mundo.o
	gcc main.o mundo.o -o juego

main.o: main.c
	gcc main.c -c

mundo.o: mundo.c
	gcc mundo.c -c
