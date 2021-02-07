#ifndef SEARCH_HPP
#define SEARCH_HPP

//==============================================
// include
//==============================================
#include <iostream>
#include "bitboard.hpp"

//==============================================
// Search
//==============================================
class Search
{
public:
	Bitboard bitboard;
	uint64_t UNIT0, UNIT1;
	uint64_t UNITS;
	uint64_t MOVES;
	uint8_t id0, id1, id2;
	int index;
	int indexPrmt;
	uint8_t i;
	uint8_t depth;
	uint64_t mem[16][32];
public:
	Search(Bitboard bitboard);
	void StoreBitboard();
	void StoreMove();
	void Load();
	void DepthFirstSearch();
};

#endif