# IDIR = ../include
# CC = g++
# CFLAGS = -I.(IDIR)
# DEPS = bitboard.hpp
# OBJ = main.o bitboard.o bitboard_test.o


# %.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

# main: $(OBJ)
# 	$(CC) -o $@ $^ $(CFLAGS)

# main: main.cpp
# 	g++ main.cpp -o main


#clean:
	#rm *.o math

# IDIR = ../include
# CC = g++
# CFLAGS = -I.(IDIR)

# ODIR = ./obj
# #LDIR =../lib

# _DEPS = bitboard.h
# DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# _OBJ = main.o bitboard.o
# OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ)) 

# $(ODIR)/%.o: %.c $(DEPS)
# 	$(CC) -c -o $@ $< $(CFLAGS)

# # %.o: %.c $(DEPS)
# # 	$(CC) -c -o $@ $< $(CFLAGS)

# main: $(OBJ)
# 	$(CC) -o $@ $^ $(CFLAGS)

main: main.cpp bitboard.o bitboard_tests.o
	g++ -o main main.cpp bitboard.o

bitboard.o: bitboard.cpp
	g++ -c bitboard.cpp

bitboard_tests.o: bitboard_tests.cpp
	g++ -c bitboard_tests.cpp

clean:
	rm *.o main

