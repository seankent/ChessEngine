CC = g++
CFLAGS = -Wall -g

main: main.o bitboard.o test_bitboard.o
	$(CC) $(CFLAGS) -o main main.o bitboard.o test_bitboard.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

bitboard.o: bitboard.cpp
	$(CC) $(CFLAGS) -c bitboard.cpp

test_bitboard.o: test_bitboard.cpp
	$(CC) $(CFLAGS) -c test_bitboard.cpp

clean:
	rm *.o main

