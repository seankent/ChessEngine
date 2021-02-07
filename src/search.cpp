//==============================================
// include
//==============================================
#include "search.hpp"


//==============================================
// Store
//==============================================
Search::Search(Bitboard bitboard)
{
	this->bitboard = bitboard;
}

//==============================================
// StoreBitboard
//==============================================
void Search::StoreBitboard()
{
	mem[depth][0] = bitboard.WR;
	mem[depth][1] = bitboard.WN;
	mem[depth][2] = bitboard.WB;
	mem[depth][3] = bitboard.WQ; 
	mem[depth][4] = bitboard.WK;
	mem[depth][5] = bitboard.WP; 
	mem[depth][6] = bitboard.BR;
	mem[depth][7] = bitboard.BN; 
	mem[depth][8] = bitboard.BB;
	mem[depth][9] = bitboard.BQ; 
	mem[depth][10] = bitboard.BK;
	mem[depth][11] = bitboard.BP; 
	mem[depth][12] = bitboard.WHITE_UNITS;
	mem[depth][13] = bitboard.BLACK_UNITS; 
	mem[depth][14] = bitboard.EMPTY;
	mem[depth][15] = bitboard.WHITE_ATTACKS; 
	mem[depth][16] = bitboard.BLACK_ATTACKS;
	mem[depth][17] = bitboard.turn;
	mem[depth][18] = bitboard.wkc;
	mem[depth][19] = bitboard.wqc;
	mem[depth][20] = bitboard.bkc;
	mem[depth][21] = bitboard.bqc;
	mem[depth][22] = bitboard.wc;
	mem[depth][23] = bitboard.bc;
}

//==============================================
// StoreMove
//==============================================
void Search::StoreMove()
{
	mem[depth][24] = UNIT0; 
	mem[depth][25] = UNIT1;
	mem[depth][26] = id0;
	mem[depth][27] = id1;
	mem[depth][28] = id2;
	mem[depth][29] = UNITS;
	mem[depth][30] = MOVES;
	mem[depth][31] = index;	
}

//==============================================
// Load
//==============================================
void Search::Load()
{
	bitboard.WR = mem[depth][0];
	bitboard.WN = mem[depth][1];
	bitboard.WB = mem[depth][2];
	bitboard.WQ = mem[depth][3]; 
	bitboard.WK = mem[depth][4];
	bitboard.WP = mem[depth][5]; 
	bitboard.BR = mem[depth][6];
	bitboard.BN = mem[depth][7]; 
	bitboard.BB = mem[depth][8];
	bitboard.BQ = mem[depth][9]; 
	bitboard.BK = mem[depth][10];
	bitboard.BP = mem[depth][11]; 
	bitboard.WHITE_UNITS = mem[depth][12];
	bitboard.BLACK_UNITS = mem[depth][13]; 
	bitboard.EMPTY = mem[depth][14];
	bitboard.WHITE_ATTACKS = mem[depth][15]; 
	bitboard.BLACK_ATTACKS = mem[depth][16];
	bitboard.turn = mem[depth][17];
	bitboard.wkc = mem[depth][18];
	bitboard.wqc = mem[depth][19];
	bitboard.bkc = mem[depth][20];
	bitboard.bqc = mem[depth][21];
	bitboard.wc = mem[depth][22];
	bitboard.bc = mem[depth][23];
	UNIT0 = mem[depth][24]; 
	UNIT1 = mem[depth][25];
	id0 = mem[depth][26];
	id1 = mem[depth][27];
	id2 = mem[depth][28];
	UNITS = mem[depth][29];
	MOVES = mem[depth][30];
	index = mem[depth][31];
}

//==============================================
// DepthFirstSearch
//==============================================
void Search::DepthFirstSearch()
{
	std::cout << "Starting Search..." << std::endl;
	UNITS = 0x0UL;
	MOVES = 0x0UL;
	depth = 0;

	uint8_t ids[] = {PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING};
	uint8_t idsPrmt[] = {QUEEN, KNIGHT, ROOK, BISHOP};
	index = -1;
	indexPrmt = 0;
	bitboard.Print();

	while (true){

		if (depth == 2){
			depth--;
			Load();
		}

		if (MOVES != 0x0UL){
			bitboard.LS1B(MOVES, UNIT1, i);

			if ((id0 == PAWN) && ((UNIT1 & RANK_8) != 0)){
				if (indexPrmt == 4) MOVES ^= UNIT1;
				else {
					id1 = idsPrmt[indexPrmt];
					indexPrmt++;
				}
			}
			// need to take care of promotions
			MOVES ^= UNIT1; 			
			StoreBitboard();
			bitboard.Move(UNIT0, UNIT1, id0, id1, id2);
			StoreMove();
			UNITS = 0x0UL;
			MOVES = 0x0UL;
			index = -1;
			depth++;
			bitboard.Print();
		}

		if (UNITS != 0){
			bitboard.LS1B(UNITS, UNIT0, i);
			UNITS ^= UNIT0;
			switch (id0){
				case ROOK:
					if (bitboard.turn == WHITE) MOVES = bitboard.MovesWR(UNIT0, i);
					else MOVES = bitboard.MovesBR(UNIT0, i);
					break;
				case KNIGHT:
					if (bitboard.turn == WHITE) MOVES = bitboard.MovesWN(UNIT0);
					else MOVES = bitboard.MovesBN(UNIT0);
					break;
				case BISHOP:
					if (bitboard.turn == WHITE) MOVES = bitboard.MovesWB(UNIT0, i);
					else MOVES = bitboard.MovesBB(UNIT0, i);
					break;
				case QUEEN:
					if (bitboard.turn == WHITE) MOVES = bitboard.MovesWQ(UNIT0, i);
					else MOVES = bitboard.MovesBQ(UNIT0, i);
					break;
				case KING:
					if (bitboard.turn == WHITE) MOVES = bitboard.MovesWK(UNIT0);
					else MOVES = bitboard.MovesBK(UNIT0);
					break;
				case PAWN:
					if (bitboard.turn == WHITE) MOVES = bitboard.MovesWP(UNIT0);
					else MOVES = bitboard.MovesBP(UNIT0);
					break;
			}
		}
		else {
			if (index < 5){
				index++;
				
				id0 = ids[index];
				id1 = ids[index];
				switch (id0){
					case ROOK:
						if (bitboard.turn == WHITE) UNITS = bitboard.WR;
						else UNITS = bitboard.BR;
						break;
					case KNIGHT:
						if (bitboard.turn == WHITE) UNITS = bitboard.WN;
						else UNITS = bitboard.BN;
						break;
					case BISHOP:
						if (bitboard.turn == WHITE) UNITS = bitboard.WB;
						else UNITS = bitboard.BB;
						break;
					case QUEEN:
						if (bitboard.turn == WHITE) UNITS = bitboard.WQ;
						else UNITS = bitboard.BQ;
						break;
					case KING:
						if (bitboard.turn == WHITE) UNITS = bitboard.WK;
						else UNITS = bitboard.BK;
						break;
					case PAWN:
						if (bitboard.turn == WHITE) UNITS = bitboard.WP;
						else UNITS = bitboard.BP;
						break;
				}
			}
			else return;
		}

	}
}

	// uint8_t ids[] = {ROOK KNIGHT, BISHOP, QUEEN, KING, PAWN};
	// uint64_t UNIT0, UNIT1, UNIT2;
	// uint8_t id0, id1, id2;
	// uint64_t MOVES;
	// uint8_t i;

	// int count = 0;
	// int depth = 0;


	// while (1){

	// 	if (MOVES != 0x0UL){
	// 		LS1B(MOVES, UNIT1, i);
	// 		MOVES ^= UNIT1; // remove UNIT1 from moves
	// 		// store everything
	// 		bitboard.Move(UNIT0, UNIT1, UNIT2, id0, id1, id2);
	// 		// reset everything
	// 		count = count
	// 		MOVES == 0x0UL
	// 	}
	// 	if (UNITS != 0x0UL){
	// 		LS1B(UNITS, UNIT0, i);
	// 		switch (id0){
	// 				case ROOK:
	// 					MOVES = MoveWR(UNIT0, i);
	// 					break;
	// 				case KNIGHT:
	// 					MOVES = MoveWN(UNIT0);
	// 					break;
	// 				case BISHOP:
	// 					MOVES = MoveWB(UNIT0, i);
	// 					break;
	// 				case QUEEN:
	// 					MOVES = MoveWQ(UNIT0, i);
	// 					break;
	// 				case KING:
	// 					MOVES = MoveWK(UNIT0);
	// 					break;
	// 				case PAWN:
	// 					MOVES = MoveWP(UNIT0);
	// 					break;
	// 				default:
	// 					UNITS = 0x0UL;
	// 			}
	// 	} else{



	// 	}

	// 	if (UNITS == 0x0UL){
	// 		if (count < 5){
	// 			count++;
	// 			id0 = ids[count];

	// 			switch (id0){
	// 				case ROOK:
	// 					UNITS = WR;
	// 					break;
	// 				case KNIGHT:
	// 					UNITS = WN;
	// 					break;
	// 				case BISHOP:
	// 					UNITS = WB;
	// 					break;
	// 				case QUEEN:
	// 					UNITS = WQ;
	// 					break;
	// 				case KING:
	// 					UNITS = WK;
	// 					break;
	// 				case PAWN:
	// 					UNITS = WP;
	// 					break;
	// 				default:
	// 					UNITS = 0x0UL;
	// 			}
	// 		}

	// 	}



	// }



	// if (id == ROOK){
	// 	UNITS = WR;
	// 	MOVES = MovesWR();
	// }

	// while (1){
	// 	store WR, WB, ...
	// 	store count,
	// 	store MOVES,

	 

	// 	LS1B(MOVES, UNIT1, i);

	// 	MOVES ^= UNIT1;
	// 	Store()


	// 	Move(UNIT0, UNIT1, UNIT2 id0, id1, id2);
	// 	turn = !turn;
	// 	depth++;


	// } 
	// uint8_t id;
