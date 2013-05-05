CC = g++-4.7
FLAGS = -pedantic -W -c

all: test

test: main.o atrib.o data.o
	$(CC) -o test main.o atrib.o data.o

main.o: main.cpp atrib.h
	$(CC) $(FLAGS) -o main.o main.cpp 

atrib.o: atrib.cpp atrib.h
	$(CC) $(FLAGS) -o atrib.o atrib.cpp

data.o: data.cpp data.h
	$(CC) $(FLAGS) -o data.o data.cpp

clean:
	rm -f *.o test
