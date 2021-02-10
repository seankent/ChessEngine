//==============================================
// include
//==============================================
#include "evaluate.hpp"

//==============================================
// Evaluate
//==============================================
int Evaluate(Bitboard bitboard)
{
	int value = 0;
	value += EvaluateMaterial(bitboard);
	return value;
}

//==============================================
// EvaluateMaterial
//==============================================
int EvaluateMaterial(Bitboard bitboard)
{
	int value = 0;
	uint64_t UNIT;
	uint8_t i;

	uint64_t WR = bitboard.WR;
	uint64_t WN = bitboard.WN;
	uint64_t WB = bitboard.WB;
	uint64_t WQ = bitboard.WQ;
	uint64_t WP = bitboard.WP;
	uint64_t BR = bitboard.BR;
	uint64_t BN = bitboard.BN;
	uint64_t BB = bitboard.BB;
	uint64_t BQ = bitboard.BQ;
	uint64_t BP = bitboard.BP;

	while (WR != 0x0UL){
		UNIT = bitboard.LS1B(WR, i);
		WR ^= UNIT;
		value += 5;
	}
	while (WN != 0x0UL){
		UNIT = bitboard.LS1B(WN, i);
		WN ^= UNIT;
		value += 3;
	}
	while (WB != 0x0UL){
		UNIT = bitboard.LS1B(WB, i);
		WB ^= UNIT;
		value += 3;
	}
	while (WQ != 0x0UL){
		UNIT = bitboard.LS1B(WQ, i);
		WQ ^= UNIT;
		value += 9;
	}
	while (WP != 0x0UL){
		UNIT = bitboard.LS1B(WP, i);
		WP ^= UNIT;
		value += 1;
	}

	while (BR != 0x0UL){
		UNIT = bitboard.LS1B(BR, i);
		BR ^= UNIT;
		value -= 5;
	}
	while (BN != 0x0UL){
		UNIT = bitboard.LS1B(BN, i);
		BN ^= UNIT;
		value -= 3;
	}
	while (BB != 0x0UL){
		UNIT = bitboard.LS1B(BB, i);
		BB ^= UNIT;
		value -= 3;
	}
	while (BQ != 0x0UL){
		UNIT = bitboard.LS1B(BQ, i);
		BQ ^= UNIT;
		value -= 9;
	}
	while (BP != 0x0UL){
		UNIT = bitboard.LS1B(BP, i);
		BP ^= UNIT;
		value -= 1;
	}
	return value;
}