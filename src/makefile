CC = g++
CFLAGS =
#CFLAGS = -Wall -g

main: main.o bitboard.o search.o game.o test_bitboard.o
	$(CC) $(CFLAGS) -o main main.o bitboard.o search.o game.o test_bitboard.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

bitboard.o: bitboard.cpp
	$(CC) $(CFLAGS) -c bitboard.cpp

search.o: search.cpp
	$(CC) $(CFLAGS) -c search.cpp

game.o: game.cpp
	$(CC) $(CFLAGS) -c game.cpp

test_bitboard.o: test_bitboard.cpp
	$(CC) $(CFLAGS) -c test_bitboard.cpp

clean:
	rm *.o main
