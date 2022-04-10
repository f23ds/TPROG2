CC=gcc
CFLAGS= -g -Wall 

SRC = test_sort.c list_sort.c list.c elements.c  
HDR = list_sort.h list.h elements.h types.h

all: $(SRC) $(HDR)
	$(CC) $(CFLAGS) -o test_sort $(SRC)

clean:
	rm -f test_sort
