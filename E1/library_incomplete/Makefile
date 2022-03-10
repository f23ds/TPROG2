########################################################
CC=gcc
CFLAGS= -g -Wall -pedantic
EJS = main
########################################################
OBJECTS = main.o book.o library.o
########################################################

all: $(EJS) clear

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS)

main.o: main.c library.h 
	$(CC) $(CFLAGS) -c main.c

book.o: book.c book.h
	$(CC) $(CFLAGS) -c book.c

library.o: library.c library.h
	$(CC) $(CFLAGS) -c library.c

clear:
	rm -rf *.o 

clean:
	rm -rf *.o $(EJS)








run:
	@echo ">>>>>>Running main"
	./main

runv:
	@echo ">>>>>>Running main with valgrind"
	valgrind --leak-check=full ./main
