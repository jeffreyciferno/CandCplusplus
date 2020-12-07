CPPFLAGS = --std=c++11 -pedantic -Wall
CC = g++

project4: project4.cpp  matrix.o
	$(CC) $(CPPFLAGS) project4.cpp  matrix.o -o matrix

matrix.o: matrix.cpp
	$(CC) $(CPPFLAGS) -c matrix.cpp

clean:
	rm -f  *.o *.exe *~

