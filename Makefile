CFLAGS = -g -DDEBUG
CC = g++ -std=c++11

all: fork

fork: main.o 
	$(CC) $(CFLAGS) main.o -o fork
	
main.o : main.cpp include.h
	$(CC) $(CFLAGS) -c main.cpp
	
clean:
	rm -f *.o fork
	rm -f *.txt
