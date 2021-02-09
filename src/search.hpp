#ifndef SEARCH_HPP
#define SEARCH_HPP

//==============================================
// include
//==============================================
#include <iostream>
#include "bitboard.hpp"
#include "evaluate.hpp"

//==============================================
// define
//==============================================
#define MAX_DEPTH 8
#define INFINITY std::numeric_limits<int>::max()

//==============================================
// const
//==============================================
const uint8_t ids[] = {ROOK, KNIGHT, BISHOP, QUEEN, KING, PAWN};
const uint8_t idsPrmt[] = {QUEEN, KNIGHT, ROOK, BISHOP};

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
	uint8_t id0, id1;
	uint8_t i;
	uint8_t index;
	uint8_t indexPrmt;
	uint8_t d;
	int count;
	bool player;
	int value;
	int best;
	uint64_t BEST0, BEST1, BEST2;
	uint8_t ID0, ID1;
	uint64_t mem[MAX_DEPTH][38];
public:
	Search(Bitboard bitboard);
	void Store();
	void Load();
	void UpdateBest();
	void DepthFirstSearch(uint8_t D);
	void Minimax(uint8_t D);
	void AlphaBeta(uint8_t D);
};

#endif