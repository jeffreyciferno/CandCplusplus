CFLAGS = -c -ansi -pedantic -Wall
CC = gcc
 
project2: project2.o matrix.o 
	$(CC) -o matrix project2.o matrix.o -g

project2.o: project2.c  
	$(CC) $(CFLAGS) project2.c -g

 
matrix.o: matrix.c
	$(CC) $(CFLAGS) matrix.c -g
 
clean:
	rm -f  *.o *.exe *~
