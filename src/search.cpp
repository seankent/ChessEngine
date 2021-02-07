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
// Store
//==============================================
void Search::Store()
{
	mem[d][0] = bitboard.WR;
	mem[d][1] = bitboard.WN;
	mem[d][2] = bitboard.WB;
	mem[d][3] = bitboard.WQ; 
	mem[d][4] = bitboard.WK;
	mem[d][5] = bitboard.WP; 
	mem[d][6] = bitboard.BR;
	mem[d][7] = bitboard.BN; 
	mem[d][8] = bitboard.BB;
	mem[d][9] = bitboard.BQ; 
	mem[d][10] = bitboard.BK;
	mem[d][11] = bitboard.BP; 
	mem[d][12] = bitboard.WHITE_UNITS;
	mem[d][13] = bitboard.BLACK_UNITS; 
	mem[d][14] = bitboard.EMPTY;
	mem[d][15] = bitboard.WHITE_ATTACKS; 
	mem[d][16] = bitboard.BLACK_ATTACKS;
	mem[d][17] = bitboard.FILE_EP;
	mem[d][18] = bitboard.turn;
	mem[d][19] = bitboard.wkc;
	mem[d][20] = bitboard.wqc;
	mem[d][21] = bitboard.bkc;
	mem[d][22] = bitboard.bqc;
	mem[d][23] = bitboard.wc;
	mem[d][24] = bitboard.bc;
	mem[d][25] = UNIT0; 
	mem[d][26] = UNIT1;
	mem[d][27] = id0;
	mem[d][28] = id1;
	mem[d][29] = UNITS;
	mem[d][30] = MOVES;
	mem[d][31] = index;
	mem[d][32] = indexPrmt;
	mem[d][33] = value;
	mem[d][34] = BEST0;
	mem[d][35] = BEST1;
	mem[d][36] = ID0;
	mem[d][37] = ID1;
}

//==============================================
// Load
//==============================================
void Search::Load()
{
	bitboard.WR = mem[d][0];
	bitboard.WN = mem[d][1];
	bitboard.WB = mem[d][2];
	bitboard.WQ = mem[d][3]; 
	bitboard.WK = mem[d][4];
	bitboard.WP = mem[d][5]; 
	bitboard.BR = mem[d][6];
	bitboard.BN = mem[d][7]; 
	bitboard.BB = mem[d][8];
	bitboard.BQ = mem[d][9]; 
	bitboard.BK = mem[d][10];
	bitboard.BP = mem[d][11]; 
	bitboard.WHITE_UNITS = mem[d][12];
	bitboard.BLACK_UNITS = mem[d][13]; 
	bitboard.EMPTY = mem[d][14];
	bitboard.WHITE_ATTACKS = mem[d][15]; 
	bitboard.BLACK_ATTACKS = mem[d][16];
	bitboard.FILE_EP = mem[d][17];
	bitboard.turn = mem[d][18];
	bitboard.wkc = mem[d][19];
	bitboard.wqc = mem[d][20];
	bitboard.bkc = mem[d][21];
	bitboard.bqc = mem[d][22];
	bitboard.wc = mem[d][23];
	bitboard.bc = mem[d][24];
	UNIT0 = mem[d][25]; 
	UNIT1 = mem[d][26];
	id0 = mem[d][27];
	id1 = mem[d][28];
	UNITS = mem[d][29];
	MOVES = mem[d][30];
	index = mem[d][31];
	indexPrmt = mem[d][32];

	//std::cout << "turn " << (value > mem[d][33] << std::endl;
	if (((bitboard.turn == WHITE) && (value > (int)mem[d][33])) || ((bitboard.turn == BLACK) && (value < (int)mem[d][33]))){
		BEST0 = UNIT0;
		BEST1 = UNIT1;
		ID0 = id0;
		ID1 = id1;
	}
	else {
		value = mem[d][33];
		BEST0 = mem[d][34];
		BEST1 = mem[d][35];
		ID0 = mem[d][36];
		ID1 = mem[d][37];
	}
}

// //==============================================
// // Eval
// //==============================================
// void Eval()
// {
// 	value = Evaluate(bitboard);
// 	std::cout << value << std::endl;
// 	if (player == WHITE){
// 		if (value > valueBest){
// 			valueBest = value;
// 			UNIT0Best = mem[0][25];
// 			UNIT1Best = mem[0][26];
// 			id0Best = mem[0][27];
// 			id1Best = mem[0][28];
// 		}
// 	}
// 	else {
// 		if (value < valueBest){
// 			valueBest = value;
// 			UNIT0Best = mem[0][25];
// 			UNIT1Best = mem[0][26];
// 			id0Best = mem[0][27];
// 			id1Best = mem[0][28];
// 		}
// 	}
// }

// //==============================================
// // UpdateValue
// //==============================================
// void Search::UpdateValue()
// {
// 	if 
// 	if (player == WHITE){
// 		if (value > valueBest){
// 			valueBest = value;
// 			UNIT0Best = mem[0][25];
// 			UNIT1Best = mem[0][26];
// 			id0Best = mem[0][27];
// 			id1Best = mem[0][28];
// 		}
// 	}
// 	else {
// 		if (value < valueBest){
// 			valueBest = value;
// 			UNIT0Best = mem[0][25];
// 			UNIT1Best = mem[0][26];
// 			id0Best = mem[0][27];
// 			id1Best = mem[0][28];

// }

//==============================================
// DepthFirstSearch
//==============================================
void Search::DepthFirstSearch(uint8_t D)
{
	std::cout << "Starting Search..." << std::endl;
	UNITS = 0x0UL;
	MOVES = 0x0UL;
	BEST0 = 0x0UL;
	BEST1 = 0x0UL;
	d = 0;
	index = 0;
	indexPrmt = 0;
	count = 0;

	//bitboard.Print();

	while (true){
		if ((d == D) || (d == MAX_DEPTH)){
			d--;
			Load();
		}
		else if (MOVES != 0x0UL){
			bitboard.LS1B(MOVES, UNIT1, i);
			if ((id0 == PAWN) && (((UNIT1 & RANK_1) != 0) || ((UNIT1 & RANK_8) != 0))){
				id1 = idsPrmt[indexPrmt];
				if (indexPrmt == 3) MOVES ^= UNIT1;
				indexPrmt++;
			}
			else {
				MOVES ^= UNIT1;
			}
			Store();
			bitboard.Move(UNIT0, UNIT1, id0, id1);

			// check if move is valid
			if ((bitboard.turn == WHITE && bitboard.bc) || (bitboard.turn == BLACK && bitboard.wc)){
				Load();
				continue;
			}

			UNITS = 0x0UL;
			MOVES = 0x0UL;
			index = 0;
			d++;
			count++;
			//bitboard.Print();
		}
		else if (UNITS != 0){
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
				default:
					MOVES = 0x0UL;
			}
		}
		else if (index < 6){
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
				default:
					UNITS = 0x0UL;
			}
			index++;
		}
		else if (d != 0){
			d--;
			Load();
		}
		else{
			std::cout << "count: " << (int)count << std::endl;
			return;
		}

	}
}



//==============================================
// Minimax
//==============================================
void Search::Minimax(uint8_t D)
{
	std::cout << "Starting Search..." << std::endl;
	UNITS = 0x0UL;
	MOVES = 0x0UL;
	d = 0;
	index = 0;
	indexPrmt = 0;
	count = 0;
	if (bitboard.turn == WHITE) value = -INFINITY;
	else value = INFINITY;

	while (true){
		if ((d == D) || (d == MAX_DEPTH)){
			d--;
			// Evaluate position
			value = Evaluate(bitboard);
			Load();
		}
		else if (MOVES != 0x0UL){
			bitboard.LS1B(MOVES, UNIT1, i);
			if ((id0 == PAWN) && (((UNIT1 & RANK_1) != 0) || ((UNIT1 & RANK_8) != 0))){
				id1 = idsPrmt[indexPrmt];
				if (indexPrmt == 3) MOVES ^= UNIT1;
				indexPrmt++;
			}
			else {
				MOVES ^= UNIT1;
			}
			Store();
			bitboard.Move(UNIT0, UNIT1, id0, id1);
			if (bitboard.turn == WHITE && bitboard.bc){
				value = INFINITY;
				Load();
				continue;
			}
			else if (bitboard.turn == BLACK && bitboard.wc){
				value = -INFINITY;
				Load();
				continue;
			}

			if (bitboard.turn == WHITE) value = -INFINITY;
			else value = INFINITY;
			UNITS = 0x0UL;
			MOVES = 0x0UL;
			index = 0;
			d++;
			count++;
			//bitboard.Print();
		}
		else if (UNITS != 0){
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
				default:
					MOVES = 0x0UL;
			}
		}
		else if (index < 6){
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
				default:
					UNITS = 0x0UL;
			}
			index++;
		}
		else if (d != 0){
			if ((bitboard.turn == WHITE) && (value == -INFINITY) && bitboard.wc == false) value = 0;
			else if ((bitboard.turn == BLACK) && (value == INFINITY) && bitboard.bc == false) value = 0;
			d--;
			Load();

		}
		else{
			std::cout << "count: " << (int)count << std::endl;
			return;
		}

	}
}

//==============================================
// AlphaBeta
//==============================================
void Search::AlphaBeta(uint8_t D)
{
	
}


