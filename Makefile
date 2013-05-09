CC = g++-4.7
FLAGS = -pedantic -W -Wall -c

all: test

test: main.o atrib.o data.o 1R.o klas.o
	$(CC) -o test main.o atrib.o data.o 1R.o klas.o

main.o: main.cpp atrib.h
	$(CC) $(FLAGS) -o main.o main.cpp 

atrib.o: atrib.cpp atrib.h
	$(CC) $(FLAGS) -o atrib.o atrib.cpp

data.o: data.cpp data.h
	$(CC) $(FLAGS) -o data.o data.cpp

klas.o: klas.cpp klas.h
	$(CC) $(FLAGS) -o klas.o klas.cpp

1R.o: klas.h 1R.cpp 1R.h
	$(CC) $(FLAGS) -o 1R.o 1R.cpp

clean:
	rm -f *.o test
