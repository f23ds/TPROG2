all: main clear

main: main.o queue_exercises.o libqueue.a 
	gcc -g -Wall -o main main.o queue_exercises.o -L. -lqueue 

main.o: main.c queue.h types.h queue_exercises.h
	gcc -g -Wall -c main.c

queue_exercises.o: queue_exercises.c queue.h types.h
	gcc -g -Wall -c queue_exercises.c

clear:
	rm *.o

clean:
	rm main *.o

