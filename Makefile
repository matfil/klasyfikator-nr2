CC = g++-4.7
FLAGS = -pedantic -W -c

all: test

test: main.o atrib.o
	$(CC) -o test main.o atrib.o

main.o: main.cpp atrib.h
	$(CC) $(FLAGS) -o main.o main.cpp 

atrib.o: atrib.cpp atrib.h
	$(CC) $(FLAGS) -o atrib.o atrib.cpp

clean:
	rm -f *.o test
