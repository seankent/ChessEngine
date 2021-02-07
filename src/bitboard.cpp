//==============================================
// include
//==============================================
#include "bitboard.hpp"

//==============================================
// Bitboard
//==============================================
Bitboard::Bitboard(char board[8][8], bool turn)
{
	BoardToBitboard(board);
	this->turn = turn;
	this->wkc = true;
	this->wqc = true;
	this->bkc = true;
	this->bqc = true;
}

//==============================================
// Bitboard
//==============================================
Bitboard::Bitboard()
{
	char board[8][8] = {
		{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
		{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
	};
	BoardToBitboard(board);
	this->turn = WHITE;
	this->wkc = true;
	this->wqc = true;
	this->bkc = true;
	this->bqc = true;
}

//==============================================
// LS1B
// this function extracts the least significant 1 bit
// from a 64-bit unsigned int.
//==============================================
void Bitboard::LS1B(uint64_t U64, uint64_t & LS1B, uint8_t & i)
{
	LS1B = U64 & (~U64 + 1);
	for (i = 0; i < 64; i++){
		if (LS1B & (0x1UL << i)) return;
	}
} 

//==============================================
// Reverse
//==============================================
uint64_t Bitboard::Reverse(uint64_t U64) 
{
	uint64_t REV = 0x0UL;
	for (int i = 0; i < 64; i++){
		REV <<= 1;
		if ((U64 & 1) == 1) 
            REV ^= 1;
        U64 >>= 1;
	}
	return REV;
}

//==============================================
// Update
//==============================================
void Bitboard::Update()
{
	WHITE_UNITS = WR | WN | WB | WQ | WK | WP;
	BLACK_UNITS = BR | BN | BB | BQ | BK | BP;
	EMPTY = ~(WHITE_UNITS | BLACK_UNITS);
	WHITE_ATTACKS = AttacksW();
	BLACK_ATTACKS = AttacksB();
	wc = ((BLACK_ATTACKS & WK) != 0);
	bc = ((WHITE_ATTACKS & BK) != 0);
}

//==============================================
// BoardToBitboard
//==============================================
void Bitboard::BoardToBitboard(char board[8][8])
{
	WR = 0x0UL;
	WN = 0x0UL;
	WB = 0x0UL;
	WQ = 0x0UL;
	WK = 0x0UL; 
	WP = 0x0UL; 
	BR = 0x0UL;
	BN = 0x0UL;
	BB = 0x0UL;
	BQ = 0x0UL;
	BK = 0x0UL;
	BP = 0x0UL;

	for (int i = 0; i < 64; i++){
		switch (board[7 - i/8][i%8]){
			case 'R':
				WR += 0x1UL << i;
				break;
			case 'N':
				WN += 0x1UL << i;
				break;
			case 'B':
				WB += 0x1UL << i;
				break;
			case 'Q':
				WQ += 0x1UL << i;
				break;
			case 'K':
				WK += 0x1UL << i;
				break;
			case 'P':
				WP += 0x1UL << i;
				break;
			case 'r':
				BR += 0x1UL << i;
				break;
			case 'n':
				BN += 0x1UL << i;
				break;
			case 'b':
				BB += 0x1UL << i;
				break;
			case 'q':
				BQ += 0x1UL << i;
				break;
			case 'k':
				BK += 0x1UL << i;
				break;
			case 'p':
				BP += 0x1UL << i;
				break;
			default:
				break;
		}
	}
	Update();
	FILE_EP = 0x0;
}

//==============================================
// BitboardToBoard
//==============================================
void Bitboard::BitboardToBoard(char board[8][8])
{
	for (int i = 0; i < 64; i++)
	{
		board[7 - i/8][i%8] = ' ';
		if (((WR >> i) & 1) == 1) board[7 - i/8][i%8] = 'R';
		if (((WN >> i) & 1) == 1) board[7 - i/8][i%8] = 'N';
		if (((WB >> i) & 1) == 1) board[7 - i/8][i%8] = 'B';
		if (((WQ >> i) & 1) == 1) board[7 - i/8][i%8] = 'Q';
		if (((WK >> i) & 1) == 1) board[7 - i/8][i%8] = 'K';
		if (((WP >> i) & 1) == 1) board[7 - i/8][i%8] = 'P';
		if (((BR >> i) & 1) == 1) board[7 - i/8][i%8] = 'r';
		if (((BN >> i) & 1) == 1) board[7 - i/8][i%8] = 'n';
		if (((BB >> i) & 1) == 1) board[7 - i/8][i%8] = 'b';
		if (((BQ >> i) & 1) == 1) board[7 - i/8][i%8] = 'q';
		if (((BK >> i) & 1) == 1) board[7 - i/8][i%8] = 'k';
		if (((BP >> i) & 1) == 1) board[7 - i/8][i%8] = 'p';
	}
}

//==============================================
// Print
//==============================================
void Bitboard::Print(char board[8][8])
{

	for (int i = 0; i < 8; i++){
		std::cout << "  +---+---+---+---+---+---+---+---+" << std::endl;
		std::cout << (char)('0' + (char)(8 - i)) << ' '; 
		for (int j = 0; j < 8; j++){
			std::cout << "| " << board[i][j] << " ";
			if (j == 7){
				if (i == 0){
					if (turn == WHITE) std::cout << "| Turn: white" << std::endl;
					else std::cout << "| Turn: black" << std::endl;
				} 
				else if (i == 1){
					if (wc | bc) std::cout << "| Status: check" << std::endl;
					else std::cout << "| Status: -" << std::endl;
				}
				else std::cout << "|" << std::endl;
			}
		}
	}
	std::cout << "  +---+---+---+---+---+---+---+---+" << std::endl;
	std::cout << "    a   b   c   d   e   f   g   h" << std::endl;
}

//==============================================
// Print
//==============================================
void Bitboard::Print()
{
	char board[8][8];
	BitboardToBoard(board);
	Print(board);
}

//==============================================
// PrintMoves
//==============================================
void Bitboard::PrintMovess(uint64_t MOVES)
{
	char board[8][8];
 	BitboardToBoard(board);

	for (int i = 0; i < 64; i++){
		if (((MOVES >> i) & 1) == 1) board[7 - i/8][i%8] = 'x';
	}
	Print(board);
}

//==============================================
// PrintBitboard
//==============================================
void Bitboard::PrintBitboard(uint64_t U64)
{
	// for (int i = 0; i < 8; i++){
	// 	if (i != 0) std::cout << std::endl;
	// 	for (int j = 0; j < 8; j++){
	// 		if (((U64 >> (8*(7 - i) + j)) & 1) != 0) std::cout << 1;
	// 		else std::cout << 0;
	// 		std::cout << ' ';
	// 	}
	// }
	// std::cout << std::endl;
	for (int i = 0; i < 8; i++){
		std::cout << std::hex << std::setw(2) << std::setfill('0') << ((U64 >> 56) & 0xff);
		if (i != 7) std::cout << "_";
		U64 <<= 8;
	}
	std::cout << std::endl;
}

//==============================================
// MovesWN
//==============================================
uint64_t Bitboard::MovesWN(uint64_t UNIT)
{	
	uint64_t MOVE0 = (UNIT << 10) & ~FILE_A & ~FILE_B;
	uint64_t MOVE1 = (UNIT << 17) & ~FILE_A;
	uint64_t MOVE2 = (UNIT << 15) & ~FILE_H;
	uint64_t MOVE3 = (UNIT << 6) & ~FILE_G & ~FILE_H;
	uint64_t MOVE4 = (UNIT >> 10) & ~FILE_G & ~FILE_H;
	uint64_t MOVE5 = (UNIT >> 17) & ~FILE_H;
	uint64_t MOVE6 = (UNIT >> 15) & ~FILE_A;
	uint64_t MOVE7 = (UNIT >> 6) & ~FILE_A & ~FILE_B;
	uint64_t MOVES = (MOVE0 | MOVE1 | MOVE2 | MOVE3 | MOVE4 | MOVE5 | MOVE6 | MOVE7) & ~WHITE_UNITS;
	return MOVES;
}

//==============================================
// MovesBN
//==============================================
uint64_t Bitboard::MovesBN(uint64_t UNIT)
{	
	uint64_t MOVE0 = (UNIT << 10) & ~FILE_A & ~FILE_B;
	uint64_t MOVE1 = (UNIT << 17) & ~FILE_A;
	uint64_t MOVE2 = (UNIT << 15) & ~FILE_H;
	uint64_t MOVE3 = (UNIT << 6) & ~FILE_G & ~FILE_H;
	uint64_t MOVE4 = (UNIT >> 10) & ~FILE_G & ~FILE_H;
	uint64_t MOVE5 = (UNIT >> 17) & ~FILE_H;
	uint64_t MOVE6 = (UNIT >> 15) & ~FILE_A;
	uint64_t MOVE7 = (UNIT >> 6) & ~FILE_A & ~FILE_B;
	uint64_t MOVES = (MOVE0 | MOVE1 | MOVE2 | MOVE3 | MOVE4 | MOVE5 | MOVE6 | MOVE7) & ~BLACK_UNITS;
	return MOVES;	
}

//==============================================
// MovesWR
//==============================================
uint64_t Bitboard::MovesWR(uint64_t UNIT, uint8_t i)
{	
	uint64_t RANK = RANKS[i >> 3];
	uint64_t FILE = FILES[i & 0x7];
	uint64_t MOVES_RANK = ((((~EMPTY & RANK) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & RANK) - (Reverse(UNIT) << 1))) & RANK);
	uint64_t MOVES_FILE = ((((~EMPTY & FILE) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & FILE) - (Reverse(UNIT) << 1))) & FILE);
	uint64_t MOVES = (MOVES_RANK | MOVES_FILE) & ~WHITE_UNITS;
	return MOVES;	 
}

//==============================================
// MovesBR
//==============================================
uint64_t Bitboard::MovesBR(uint64_t UNIT, uint8_t i)
{	
	uint64_t RANK = RANKS[i >> 3];
	uint64_t FILE = FILES[i & 0x7];
	uint64_t MOVES_RANK = (((~EMPTY & RANK) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & RANK) - (Reverse(UNIT) << 1))) & RANK;
	uint64_t MOVES_FILE = (((~EMPTY & FILE) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & FILE) - (Reverse(UNIT) << 1))) & FILE;
	uint64_t MOVES = (MOVES_RANK | MOVES_FILE) & ~BLACK_UNITS;
	return MOVES;	
}

//==============================================
// MovesWB
//==============================================
uint64_t Bitboard::MovesWB(uint64_t UNIT, uint8_t i)
{	
	uint64_t DIAGONAL_UP = DIAGONALS_UP[7 - (i >> 3) + (i & 0x7)];
	uint64_t DIAGONAL_DOWN = DIAGONALS_DOWN[(i >> 3) + (i & 0x7)];
	uint64_t MOVES_DIAGONAL_UP = (((~EMPTY & DIAGONAL_UP) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & DIAGONAL_UP) - (Reverse(UNIT) << 1))) & DIAGONAL_UP;
	uint64_t MOVES_DIAGONAL_DOWN = (((~EMPTY & DIAGONAL_DOWN) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & DIAGONAL_DOWN) - (Reverse(UNIT) << 1))) & DIAGONAL_DOWN;
	uint64_t MOVES = (MOVES_DIAGONAL_UP | MOVES_DIAGONAL_DOWN) & ~WHITE_UNITS;
	return MOVES;
}

//==============================================
// MovesBB
//==============================================
uint64_t Bitboard::MovesBB(uint64_t UNIT, uint8_t i)
{	
	uint64_t DIAGONAL_UP = DIAGONALS_UP[7 - (i >> 3) + (i & 0x7)];
	uint64_t DIAGONAL_DOWN = DIAGONALS_DOWN[(i >> 3) + (i & 0x7)];
	uint64_t MOVES_DIAGONAL_UP = (((~EMPTY & DIAGONAL_UP) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & DIAGONAL_UP) - (Reverse(UNIT) << 1))) & DIAGONAL_UP;
	uint64_t MOVES_DIAGONAL_DOWN = (((~EMPTY & DIAGONAL_DOWN) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & DIAGONAL_DOWN) - (Reverse(UNIT) << 1))) & DIAGONAL_DOWN;
	uint64_t MOVES = (MOVES_DIAGONAL_UP | MOVES_DIAGONAL_DOWN) & ~BLACK_UNITS;
	return MOVES;
}

//==============================================
// MovesWQ
//==============================================
uint64_t Bitboard::MovesWQ(uint64_t UNIT, uint8_t i)
{	
	return MovesWR(UNIT, i) | MovesWB(UNIT, i);
}

//==============================================
// MovesBQ
//==============================================
uint64_t Bitboard::MovesBQ(uint64_t UNIT, uint8_t i)
{	
	return MovesBR(UNIT, i) | MovesBB(UNIT, i);
}

//==============================================
// MovesWK
//==============================================
uint64_t Bitboard::MovesWK(uint64_t UNIT)
{	
	uint64_t MOVE0 = (UNIT << 1) & ~FILE_A;
	uint64_t MOVE1 = (UNIT << 9) & ~FILE_A;
	uint64_t MOVE2 = UNIT << 8;
	uint64_t MOVE3 = (UNIT << 7) & ~FILE_H;
	uint64_t MOVE4 = (UNIT >> 1) & ~FILE_H;
	uint64_t MOVE5 = (UNIT >> 9) & ~FILE_H;
	uint64_t MOVE6 = UNIT >> 8;
	uint64_t MOVE7 = (UNIT >> 7) & ~FILE_A;
	uint64_t KINGSIDE_CASTLE = 0x0UL;
	uint64_t QUEENSIDE_CASTLE = 0x0UL;
	if (wkc && ((UNIT & 0x0000000000000010UL) != 0) && ((WR & 0x0000000000000080UL) != 0) && ((~EMPTY & 0x0000000000000060UL) == 0) && ((BLACK_ATTACKS & 0x0000000000000070UL) == 0)) KINGSIDE_CASTLE = 0x0000000000000040UL;
	if (wqc && ((UNIT & 0x0000000000000010UL) != 0) && ((WR & 0x0000000000000001UL) != 0) && ((~EMPTY & 0x000000000000000EUL) == 0) && ((BLACK_ATTACKS & 0x000000000000001CUL) == 0)) QUEENSIDE_CASTLE = 0x0000000000000004UL;
	uint64_t MOVES = (MOVE0 | MOVE1 | MOVE2 | MOVE3 | MOVE4 | MOVE5 | MOVE6 | MOVE7 | KINGSIDE_CASTLE | QUEENSIDE_CASTLE) & ~WHITE_UNITS;
	return MOVES;
}

//==============================================
// MovesBK
//==============================================
uint64_t Bitboard::MovesBK(uint64_t UNIT)
{	
	uint64_t MOVE0 = (UNIT << 1) & ~FILE_A;
	uint64_t MOVE1 = (UNIT << 9) & ~FILE_A;
	uint64_t MOVE2 = UNIT << 8;
	uint64_t MOVE3 = (UNIT << 7) & ~FILE_H;
	uint64_t MOVE4 = (UNIT >> 1) & ~FILE_H;
	uint64_t MOVE5 = (UNIT >> 9) & ~FILE_H;
	uint64_t MOVE6 = UNIT >> 8;
	uint64_t MOVE7 = (UNIT >> 7) & ~FILE_A;
	uint64_t KINGSIDE_CASTLE = 0x0UL;
	uint64_t QUEENSIDE_CASTLE = 0x0UL;
	if (bkc && ((UNIT & 0x1000000000000000UL) != 0) && ((BR & 0x8000000000000000UL) != 0) && ((~EMPTY & 0x6000000000000000UL) == 0) && ((WHITE_ATTACKS & 0x7000000000000000UL) == 0)) KINGSIDE_CASTLE = 0x4000000000000000UL;
	if (bqc && ((UNIT & 0x1000000000000000UL) != 0) && ((BR & 0x0100000000000000UL) != 0) && ((~EMPTY & 0x0E00000000000000UL) == 0) && ((WHITE_ATTACKS & 0x1C00000000000000UL) == 0)) QUEENSIDE_CASTLE = 0x0400000000000000UL;
	uint64_t MOVES = (MOVE0 | MOVE1 | MOVE2 | MOVE3 | MOVE4 | MOVE5 | MOVE6 | MOVE7 | KINGSIDE_CASTLE | QUEENSIDE_CASTLE) & ~BLACK_UNITS;
	return MOVES;
}

//==============================================
// MovesWP
//==============================================
uint64_t Bitboard::MovesWP(uint64_t UNIT)
{	
	uint64_t MOVE_RIGHT = (UNIT << 9) & BLACK_UNITS & ~FILE_A; 						// capture right
	uint64_t MOVE_LEFT = (UNIT << 7) & BLACK_UNITS & ~FILE_H; 						// capture left
	uint64_t MOVE_FORWARD_1 = (UNIT << 8) & EMPTY; 									// move forward 1
	uint64_t MOVE_FORWARD_2 = (UNIT << 16) & EMPTY & (EMPTY << 8) & RANK_4; 		// move forward 2
	uint64_t MOVE_RIGHT_EP = (UNIT << 9) & (BP << 8) & RANK_6 & ~FILE_A & FILE_EP; 	// en passant right
	uint64_t MOVE_LEFT_EP = (UNIT << 7) & (BP << 8) & RANK_6 & ~FILE_H & FILE_EP; 	// en passant left
	uint64_t MOVES = MOVE_RIGHT | MOVE_LEFT | MOVE_FORWARD_1 | MOVE_FORWARD_2 | MOVE_RIGHT_EP | MOVE_LEFT_EP;
	return MOVES;
}

//==============================================
// MovesBP
//==============================================
uint64_t Bitboard::MovesBP(uint64_t UNIT)
{	
	uint64_t MOVE_RIGHT = (UNIT >> 7) & WHITE_UNITS & ~FILE_A; 						// capture right
	uint64_t MOVE_LEFT = (UNIT >> 9) & WHITE_UNITS & ~FILE_H; 						// capture left
	uint64_t MOVE_FORWARD_1 = (UNIT >> 8) & EMPTY; 									// move forward 1
	uint64_t MOVE_FORWARD_2 = (UNIT >> 16) & EMPTY & (EMPTY >> 8) & RANK_5; 		// move forward 2
	uint64_t MOVE_RIGHT_EP = (UNIT >> 7) & (WP >> 8) & RANK_3 & ~FILE_A & FILE_EP; 	// en passant right
	uint64_t MOVE_LEFT_EP = (UNIT >> 9) & (WP >> 8) & RANK_3 & ~FILE_H & FILE_EP; 	// en passant left
	uint64_t MOVES = MOVE_RIGHT | MOVE_LEFT | MOVE_FORWARD_1 | MOVE_FORWARD_2 | MOVE_RIGHT_EP | MOVE_LEFT_EP;
	return MOVES;
}

//==============================================
// AttacksW
//==============================================
uint64_t Bitboard::AttacksW()
{		
	uint64_t ATTACKS = 0x0UL;
	uint64_t UNIT;
	uint8_t i;
	uint64_t WR = this->WR;		// make copy of WR
	uint64_t WB = this->WB;		// make copy of WB
	uint64_t WQ = this->WQ;		// make copy of WQ

	while (WR != 0x0UL){
		LS1B(WR, UNIT, i);
		ATTACKS |= MovesWR(UNIT, i);
		WR ^= UNIT;
	}
	while (WB != 0x0UL){
		LS1B(WB, UNIT, i);
		ATTACKS |= MovesWB(UNIT, i);
		WB ^= UNIT;
	}
	while (WQ != 0x0UL){
		LS1B(WQ, UNIT, i);
		ATTACKS |= MovesWQ(UNIT, i);
		WQ ^= UNIT;
	}
	ATTACKS |= MovesWN(WN);
	ATTACKS |= MovesWK(WK);
	ATTACKS |= ((WP << 7) & ~FILE_H) | ((WP << 9) & ~FILE_A);
	return ATTACKS;
}

//==============================================
// AttacksB
//==============================================
uint64_t Bitboard::AttacksB()
{		
	uint64_t ATTACKS = 0x0UL;
	uint64_t UNIT;
	uint8_t i;
	uint64_t BR = this->BR;		// make copy of WR
	uint64_t BB = this->BB;		// make copy of WB
	uint64_t BQ = this->BQ;		// make copy of WQ

	while (BR != 0x0UL){
		LS1B(BR, UNIT, i);
		ATTACKS |= MovesBR(UNIT, i);
		BR ^= UNIT;
	}
	while (BB != 0x0UL){
		LS1B(BB, UNIT, i);
		ATTACKS |= MovesBB(UNIT, i);
		BB ^= UNIT;
	}
	while (BQ != 0x0UL){
		LS1B(BQ, UNIT, i);
		ATTACKS |= MovesBQ(UNIT, i);
		BQ ^= UNIT;
	}
	ATTACKS |= MovesBN(BN);
	ATTACKS |= MovesBK(BK);
	ATTACKS |= ((BP >> 7) & ~FILE_A) | ((BP >> 9) & ~FILE_H);
	return ATTACKS;
}

//==============================================
// Move
//==============================================
void Bitboard::Move(uint64_t UNIT0, uint64_t UNIT1, uint8_t id0, uint8_t id1)
{
	if (turn == WHITE){
		switch (id0){
			case ROOK:
				WR ^= UNIT0;
				if ((WR & 0x0000000000000080UL) == 0) wkc = false;
				if ((WR & 0x0000000000000001UL) == 0) wqc = false;
				break;
			case KNIGHT:
				WN ^= UNIT0;
				break;
			case BISHOP:
				WB ^= UNIT0;
				break;
			case QUEEN:
				WQ ^= UNIT0;
				break;
			case KING:
				WK ^= UNIT0;
				wkc = false;
				wqc = false;
				if ((UNIT0 >> 2) == UNIT1){
					WR ^= 0x0000000000000001UL;
					WR |= 0x0000000000000008UL;
				}
				else if ((UNIT0 << 2) == UNIT1){
					WR ^= 0x0000000000000080UL;
					WR |= 0x0000000000000020UL;
				}
				break;
			case PAWN:
				WP ^= UNIT0;
				break;
		}

		switch (id1){
			case ROOK:
				WR |= UNIT1;
				break;
			case KNIGHT:
				WN |= UNIT1;
				break;
			case BISHOP:
				WB |= UNIT1;
				break;
			case QUEEN:
				WQ |= UNIT1;
				break;
			case KING:
				WK |= UNIT1;
				break;
			case PAWN:
				WP |= UNIT1;
				if (UNIT1 & FILE_EP & RANK_6){ BP ^= (UNIT1 >> 8);
				}
				break;
		}

		if ((UNIT1 & BR) != 0) BR ^= UNIT1;
		else if ((UNIT1 & BN) != 0) BN ^= UNIT1;
		else if ((UNIT1 & BB) != 0) BB ^= UNIT1;
		else if ((UNIT1 & BQ) != 0) BQ ^= UNIT1;
		else if ((UNIT1 & BK) != 0) BK ^= UNIT1;
		else if ((UNIT1 & BP) != 0) BP ^= UNIT1;

		if ((id0 == PAWN) && ((UNIT0 << 16) == UNIT1)){
			uint8_t i;
			for (i = 0; i < 64; i++){
				if ((0x1UL << i) == UNIT0) break;
			}
			FILE_EP = FILES[i & 0x7];
		} 
		else FILE_EP = 0x0UL;
	}
	else {
		switch (id0){
			case ROOK:
				BR ^= UNIT0;
				if ((BR & 0x8000000000000000UL) == 0) bkc = false;
				if ((BR & 0x0100000000000000UL) == 0) bqc = false;
				break;
			case KNIGHT:
				BN ^= UNIT0;
				break;
			case BISHOP:
				BB ^= UNIT0;
				break;
			case QUEEN:
				BQ ^= UNIT0;
				break;
			case KING:
				BK ^= UNIT0;
				bkc = false;
				bqc = false;
				if ((UNIT0 >> 2) == UNIT1){
					BR ^= 0x0100000000000000UL;
					BR |= 0x0800000000000000UL;
				}
				if ((UNIT0 << 2) == UNIT1){
					BR ^= 0x8000000000000000UL;
					BR |= 0x2000000000000000UL;
				}
				break;
			case PAWN:
				BP ^= UNIT0;
				break;
		}

		switch (id1){
			case ROOK:
				BR |= UNIT1;
				break;
			case KNIGHT:
				BN |= UNIT1;
				break;
			case BISHOP:
				BB |= UNIT1;
				break;
			case QUEEN:
				BQ |= UNIT1;
				break;
			case KING:
				BK |= UNIT1;
				break;
			case PAWN:
				BP |= UNIT1;
				if (UNIT1 & FILE_EP & RANK_3) WP ^= (UNIT1 << 8);;
				break;
		}

		if ((UNIT1 & WR) != 0) WR ^= UNIT1;
		else if ((UNIT1 & WN) != 0) WN ^= UNIT1;
		else if ((UNIT1 & WB) != 0) WB ^= UNIT1;
		else if ((UNIT1 & WQ) != 0) WQ ^= UNIT1;
		else if ((UNIT1 & WK) != 0) WK ^= UNIT1;
		else if ((UNIT1 & WP) != 0) WP ^= UNIT1;

		if ((id0 == PAWN) && ((UNIT0 >> 16) == UNIT1)){
			uint8_t i;
			for (i = 0; i < 64; i++){
				if ((0x1UL << i) == UNIT0) break;
			}
			FILE_EP = FILES[i & 0x7];
		} 
		else FILE_EP = 0x0UL;
	}

	Update();
	turn = !turn;
}

// //==============================================
// // Move
// //==============================================
// void Bitboard::Move(uint64_t UNIT0, uint64_t UNIT1, uint8_t id0, uint8_t id1, uint8_t & id2)
// {
// 	if (turn == WHITE){
// 		switch (id0){
// 			case ROOK:
// 				WR ^= UNIT0;
// 				if ((WR & 0x0000000000000080UL) == 0) wkc = false;
// 				if ((WR & 0x0000000000000001UL) == 0) wqc = false;
// 				break;
// 			case KNIGHT:
// 				WN ^= UNIT0;
// 				break;
// 			case BISHOP:
// 				WB ^= UNIT0;
// 				break;
// 			case QUEEN:
// 				WQ ^= UNIT0;
// 				break;
// 			case KING:
// 				WK ^= UNIT0;
// 				wkc = false;
// 				wqc = false;
// 				if ((UNIT0 >> 2) == UNIT1){
// 					WR ^= 0x0000000000000001UL;
// 					WR |= 0x0000000000000008UL;
// 				}
// 				else if ((UNIT0 << 2) == UNIT1){
// 					WR ^= 0x0000000000000080UL;
// 					WR |= 0x0000000000000020UL;
// 				}
// 				break;
// 			case PAWN:
// 				WP ^= UNIT0;
// 				break;
// 		}

// 		switch (id1){
// 			case ROOK:
// 				WR |= UNIT1;
// 				break;
// 			case KNIGHT:
// 				WN |= UNIT1;
// 				break;
// 			case BISHOP:
// 				WB |= UNIT1;
// 				break;
// 			case QUEEN:
// 				WQ |= UNIT1;
// 				break;
// 			case KING:
// 				WK |= UNIT1;
// 				break;
// 			case PAWN:
// 				WP |= UNIT1;
// 				if (UNIT1 & FILE_EP & RANK_6) BP ^= (UNIT1 >> 8);
// 				break;
// 		}

// 		if ((UNIT1 & BR) != 0){
// 			BR ^= UNIT1;
// 			id2 = ROOK;
// 		}
// 		else if ((UNIT1 & BN) != 0){
// 			BN ^= UNIT1;
// 			id2 = KNIGHT;
// 		}
// 		else if ((UNIT1 & BB) != 0){
// 			BB ^= UNIT1;
// 			id2 = BISHOP;
// 		}
// 		else if ((UNIT1 & BQ) != 0){
// 			BQ ^= UNIT1;
// 			id2 = QUEEN;
// 		}
// 		else if ((UNIT1 & BK) != 0){
// 			BK ^= UNIT1;
// 			id2 = KING;
// 		}
// 		else if ((UNIT1 & BP) != 0){ 
// 			BP ^= UNIT1;
// 			id2 = PAWN;
// 		}

// 		if ((id0 == PAWN) && ((UNIT0 << 16) == UNIT1)){
// 			uint8_t i;
// 			for (i = 0; i < 64; i++){
// 				if ((0x1UL << i) == UNIT0) break;
// 			}
// 			FILE_EP = FILES[i & 0x7];
// 		} 
// 		else FILE_EP = 0x0UL;
// 	}
// 	else {
// 		switch (id0){
// 			case ROOK:
// 				BR ^= UNIT0;
// 				if ((BR & 0x8000000000000000UL) == 0) bkc = false;
// 				if ((BR & 0x0100000000000000UL) == 0) bqc = false;
// 				break;
// 			case KNIGHT:
// 				BN ^= UNIT0;
// 				break;
// 			case BISHOP:
// 				BB ^= UNIT0;
// 				break;
// 			case QUEEN:
// 				BQ ^= UNIT0;
// 				break;
// 			case KING:
// 				BK ^= UNIT0;
// 				bkc = false;
// 				bqc = false;
// 				if ((UNIT0 >> 2) == UNIT1){
// 					BR ^= 0x0100000000000000UL;
// 					BR |= 0x0800000000000000UL;
// 				}
// 				if ((UNIT0 << 2) == UNIT1){
// 					BR ^= 0x8000000000000000UL;
// 					BR |= 0x2000000000000000UL;
// 				}
// 				break;
// 			case PAWN:
// 				BP ^= UNIT0;
// 				break;
// 		}

// 		switch (id1){
// 			case ROOK:
// 				BR |= UNIT1;
// 				break;
// 			case KNIGHT:
// 				BN |= UNIT1;
// 				break;
// 			case BISHOP:
// 				BB |= UNIT1;
// 				break;
// 			case QUEEN:
// 				BQ |= UNIT1;
// 				break;
// 			case KING:
// 				BK |= UNIT1;
// 				break;
// 			case PAWN:
// 				BP |= UNIT1;
// 				if (UNIT1 & FILE_EP & RANK_3) WP ^= (UNIT1 << 8);;
// 				break;
// 		}

// 		if ((UNIT1 & WR) != 0){
// 			WR ^= UNIT1;
// 			id2 = ROOK;
// 		}
// 		else if ((UNIT1 & WN) != 0){
// 			WN ^= UNIT1;
// 			id2 = KNIGHT;
// 		}
// 		else if ((UNIT1 & WB) != 0){
// 			WB ^= UNIT1;
// 			id2 = BISHOP;
// 		}
// 		else if ((UNIT1 & WQ) != 0){
// 			WQ ^= UNIT1;
// 			id2 = QUEEN;
// 		}
// 		else if ((UNIT1 & WK) != 0){
// 			WK ^= UNIT1;
// 			id2 = KING;
// 		}
// 		else if ((UNIT1 & WP) != 0){ 
// 			WP ^= UNIT1;
// 			id2 = PAWN;
// 		}

// 		if ((id0 == PAWN) && ((UNIT0 >> 16) == UNIT1)){
// 			uint8_t i;
// 			for (i = 0; i < 64; i++){
// 				if ((0x1UL << i) == UNIT0) break;
// 			}
// 			FILE_EP = FILES[i & 0x7];
// 		} 
// 		else FILE_EP = 0x0UL;
// 	}

// 	Update();
// 	turn = !turn;
// }

// //==============================================
// // Moves
// //==============================================
// bool Bitboard::Move(uint64_t UNIT0, uint64_t UNIT1, uint8_t piece)
// {
// 	if (n > 256) return false;

// 	uint64_t MOVES;

// 	moves[n][0] = UNIT0;
// 	moves[n][1] = UNIT1;
// 	moves[n][2] = 0x0UL;
// 	moves[n][3] = NONE;
// 	moves[n][4] = NONE;
// 	moves[n][5] = NONE;
// 	moves[n][6] = FILE_EP;
// 	moves[n][7] = wkc;		
// 	moves[n][8] = wqc;
// 	moves[n][9] = bkc;
// 	moves[n][10] = bqc;
// 	uint8_t i0, i1;
// 	LS1B(UNIT0, UNIT0, i0);
// 	LS1B(UNIT1, UNIT1, i1);

// 	if (turn == WHITE){
// 		if ((UNIT0 & WP) != 0){
// 			MOVES = MovesWP(UNIT0);
// 			if ((UNIT1 & MOVES) == 0) return false;
// 			moves[n][3] = PAWN;
// 			moves[n][4] = PAWN;
// 			if ((UNIT1 & RANK_8) != 0){	// pawn promotion
// 				switch (piece){
// 					case ROOK:
// 						WP ^= UNIT0;
// 						WR |= UNIT1;
// 						moves[n][4] = ROOK;
// 						break;
// 					case KNIGHT:
// 						WP ^= UNIT0;
// 						WN |= UNIT1;
// 						moves[n][4] = KNIGHT;
// 						break;
// 					case BISHOP:
// 						WP ^= UNIT0;
// 						WB |= UNIT1;
// 						moves[n][4] = BISHOP;
// 						break;
// 					case QUEEN:
// 						WP ^= UNIT0;
// 						WQ |= UNIT1;
// 						moves[n][4] = QUEEN;
// 						break;
// 					default:
// 						return 0;
// 				}
// 			} 
// 			else {
// 				WP ^= UNIT0;
// 				WP |= UNIT1;
// 			}
// 			if (UNIT1 & FILE_EP & RANK_6){
// 				BP ^= (UNIT1 >> 8);
// 				moves[n][2] = (UNIT1 >> 8);
// 				moves[n][5] = PAWN;
// 			}
// 			if (UNIT0 << 16 == UNIT1) FILE_EP = FILES[i0 & 0x7];
// 			else FILE_EP = 0x0;
// 		}
// 		else if ((UNIT0 & WR) != 0){
// 			MOVES = MovesWR(UNIT0, i0);
// 			if ((UNIT1 & MOVES) == 0) return false;
// 			moves[n][3] = ROOK;
// 			moves[n][4] = ROOK;			
// 			WR ^= UNIT0;
// 			WR |= UNIT1;
// 			FILE_EP = 0x0;
// 			if ((WR & 0x0000000000000001UL) == 0) wqc = 0;
// 			if ((WR & 0x0000000000000080UL) == 0) wkc = 0;
// 		} 
// 		else if ((UNIT0 & WN) != 0){
// 			MOVES = MovesWN(UNIT0);
// 			if ((UNIT1 & MOVES) == 0) return false;
// 			moves[n][3] = KNIGHT;
// 			moves[n][4] = KNIGHT;			
// 			WN ^= UNIT0;
// 			WN |= UNIT1;
// 			FILE_EP = 0x0;
// 		} 
// 		else if ((UNIT0 & WB) != 0){
// 			MOVES = MovesWB(UNIT0, i0);
// 			if ((UNIT1 & MOVES) == 0) return false;
// 			moves[n][3] = BISHOP;
// 			moves[n][4] = BISHOP;
// 			WB ^= UNIT0;
// 			WB |= UNIT1;
// 			FILE_EP = 0x0;
// 		}
// 		else if ((UNIT0 & WQ) != 0){
// 			MOVES = MovesWQ(UNIT0, i0);
// 			if ((UNIT1 & MOVES) == 0) return false;	
// 			moves[n][3] = QUEEN;
// 			moves[n][4] = QUEEN;		
// 			WQ ^= UNIT0;
// 			WQ |= UNIT1;
// 			FILE_EP = 0x0;
// 		}
// 		else if ((UNIT0 & WK) != 0){
// 			MOVES = MovesWK(UNIT0);
// 			if ((UNIT1 & MOVES) == 0) return false;
// 			moves[n][3] = KING;
// 			moves[n][4] = KING;		
// 			WK ^= UNIT0;
// 			WK |= UNIT1;
// 			if ((UNIT0 >> 2) == UNIT1){
// 				WR ^= 0x0000000000000001UL;
// 				WR |= 0x0000000000000008UL;
// 			}
// 			if ((UNIT0 << 2) == UNIT1){
// 				WR ^= 0x0000000000000080UL;
// 				WR |= 0x0000000000000020UL;
// 			}
// 			wqc = 0;
// 			wkc = 0;
// 			FILE_EP = 0x0;
// 		}
// 		else {
// 			return false;
// 		}

// 		if ((UNIT1 & BP) != 0){ 
// 			BP ^= UNIT1;
// 			moves[n][2] = UNIT1;
// 			moves[n][5] = PAWN;
// 		}
// 		else if ((UNIT1 & BR) != 0){
// 			BR ^= UNIT1;
// 			moves[n][2] = UNIT1;
// 			moves[n][5] = ROOK;
// 		}
// 		else if ((UNIT1 & BN) != 0){
// 			BN ^= UNIT1;
// 			moves[n][2] = UNIT1;
// 			moves[n][5] = KNIGHT;
// 		}
// 		else if ((UNIT1 & BB) != 0){
// 			BB ^= UNIT1;
// 			moves[n][2] = UNIT1;
// 			moves[n][5] = BISHOP;
// 		}
// 		else if ((UNIT1 & BQ) != 0){
// 			BQ ^= UNIT1;
// 			moves[n][2] = UNIT1;
// 			moves[n][5] = QUEEN;
// 		}
// 		else if ((UNIT1 & BK) != 0){
// 			BK ^= UNIT1;
// 			moves[n][2] = UNIT1;
// 			moves[n][5] = KING;
// 		}
// 		turn = BLACK;
// 		n++;
// 	} 
// 	else {
// 		if ((UNIT0 & BP) != 0){
// 			MOVES = MovesBP(UNIT0);
// 			if ((UNIT1 & MOVES) == 0) return false;
// 			moves[n][3] = PAWN;
// 			moves[n][4] = PAWN;
// 			if ((UNIT1 & RANK_1) != 0){	// pawn promotion
// 				switch (piece){
// 					case ROOK:
// 						BP ^= UNIT0;
// 						BR |= UNIT1;
// 						moves[n][4] = ROOK;
// 						break;
// 					case KNIGHT:
// 						BP ^= UNIT0;
// 						BN |= UNIT1;
// 						moves[n][4] = KNIGHT;
// 						break;
// 					case BISHOP:
// 						BP ^= UNIT0;
// 						BB |= UNIT1;
// 						moves[n][4] = BISHOP;
// 						break;
// 					case QUEEN:
// 						BP ^= UNIT0;
// 						BQ |= UNIT1;
// 						moves[n][4] = QUEEN;
// 						break;
// 					default:
// 						return 0;
// 				}
// 			} 
// 			else {
// 				BP ^= UNIT0;
// 				BP |= UNIT1;
// 			}		
// 			if (UNIT1 & FILE_EP & RANK_3){
// 				WP ^= (UNIT1 << 8);
// 				moves[n][2] = (UNIT1 << 8);
// 				moves[n][5] = PAWN;
// 			} 
// 			if (UNIT0 >> 16 == UNIT1) FILE_EP = FILES[i0 & 0x7];
// 			else FILE_EP = 0x0;
// 		}
// 		else if ((UNIT0 & BR) != 0){
// 			MOVES = MovesBR(UNIT0, i0);
// 			if ((UNIT1 & MOVES) == 0) return false;
// 			moves[n][3] = ROOK;
// 			moves[n][4] = ROOK;			
// 			BR ^= UNIT0;
// 			BR |= UNIT1;
// 			FILE_EP = 0x0;
// 			if ((BR & 0x0100000000000000UL) == 0) bqc = 0;
// 			if ((BR & 0x8000000000000000UL) == 0) bkc = 0;
// 		} 
// 		else if ((UNIT0 & BN) != 0){
// 			MOVES = MovesBN(UNIT0);
// 			if ((UNIT1 & MOVES) == 0) return false;
// 			moves[n][3] = KNIGHT;
// 			moves[n][4] = KNIGHT;			
// 			BN ^= UNIT0;
// 			BN |= UNIT1;
// 			FILE_EP = 0x0;
// 		} 
// 		else if ((UNIT0 & BB) != 0){
// 			MOVES = MovesBB(UNIT0, i0);
// 			if ((UNIT1 & MOVES) == 0) return false;
// 			moves[n][3] = BISHOP;
// 			moves[n][4] = BISHOP;			
// 			BB ^= UNIT0;
// 			BB |= UNIT1;
// 			FILE_EP = 0x0;
// 		}
// 		else if ((UNIT0 & BQ) != 0){
// 			MOVES = MovesBQ(UNIT0, i0);
// 			if ((UNIT1 & MOVES) == 0) return false;
// 			moves[n][3] = QUEEN;
// 			moves[n][4] = QUEEN;			
// 			BQ ^= UNIT0;
// 			BQ |= UNIT1;
// 			FILE_EP = 0x0;
// 		}
// 		else if ((UNIT0 & BK) != 0){
// 			MOVES = MovesBK(UNIT0);
// 			if ((UNIT1 & MOVES) == 0) return false;
// 			moves[n][3] = KING;
// 			moves[n][4] = KING;			
// 			BK ^= UNIT0;
// 			BK |= UNIT1;
// 			if ((UNIT0 >> 2) == UNIT1){
// 				BR ^= 0x0100000000000000UL;
// 				BR |= 0x0800000000000000UL;
// 			}
// 			if ((UNIT0 << 2) == UNIT1){
// 				BR ^= 0x8000000000000000UL;
// 				BR |= 0x2000000000000000UL;
// 			}
// 			bqc = 0;
// 			bkc = 0;
// 			FILE_EP = 0x0;
// 		}
// 		else {
// 			return false;
// 		}

// 		if ((UNIT1 & WP) != 0){
// 			WP ^= UNIT1;
// 			moves[n][2] = UNIT1;
// 			moves[n][5] = PAWN;
// 		}
// 		else if ((UNIT1 & WR) != 0){
// 			WR ^= UNIT1;
// 			moves[n][2] = UNIT1;
// 			moves[n][5] = ROOK;
// 		}
// 		else if ((UNIT1 & WN) != 0){
// 			WN ^= UNIT1;
// 			moves[n][2] = UNIT1;
// 			moves[n][5] = KNIGHT;
// 		}
// 		else if ((UNIT1 & WB) != 0){
// 			WB ^= UNIT1;
// 			moves[n][2] = UNIT1;
// 			moves[n][5] = BISHOP;
// 		}
// 		else if ((UNIT1 & WQ) != 0){
// 			WQ ^= UNIT1;
// 			moves[n][2] = UNIT1;
// 			moves[n][5] = QUEEN;
// 		}
// 		else if ((UNIT1 & WK) != 0){
// 			WK ^= UNIT1;
// 			moves[n][2] = UNIT1;
// 			moves[n][5] = KING;
// 		}
// 		turn = WHITE;
// 		n++;
// 	}
// 	if (Update()){
// 		return true;
// 	}
// 	else {
// 		Undo();
// 		return false;
// 	}
// }

// //==============================================
// // Undo
// //==============================================
// void Bitboard::Undo()
// {
// 	if (n == 0) return;
// 	n--;

// 	uint64_t UNIT0 = moves[n][0];
// 	uint64_t UNIT1 = moves[n][1];
// 	uint64_t UNIT2 = moves[n][2];
// 	FILE_EP = moves[n][6];
// 	wkc = moves[n][7];
// 	wqc = moves[n][8];
// 	bkc = moves[n][9];
// 	bqc = moves[n][10];

// 	if (turn == WHITE){
// 		switch (moves[n][3]){
// 			case ROOK:
// 				BR |= UNIT0;
// 				break;
// 			case KNIGHT:
// 				BN |= UNIT0;
// 				break;
// 			case BISHOP:
// 				BB |= UNIT0;
// 				break;
// 			case QUEEN:
// 				BQ |= UNIT0;
// 				break;
// 			case KING:
// 				BK |= UNIT0;
// 				break;
// 			case PAWN:
// 				BP |= UNIT0;
// 				break;
// 			default:
// 				break;
// 		}
// 		switch (moves[n][4]){
// 			case ROOK:
// 				BR ^= UNIT1;
// 				break;
// 			case KNIGHT:
// 				BN ^= UNIT1;
// 				break;
// 			case BISHOP:
// 				BB ^= UNIT1;
// 				break;
// 			case QUEEN:
// 				BQ ^= UNIT1;
// 				break;
// 			case KING:
// 				BK ^= UNIT1;
// 				break;
// 			case PAWN:
// 				BP ^= UNIT1;
// 				break;
// 			default:
// 				break;
// 		}
// 		switch (moves[n][5]){
// 			case ROOK:
// 				WR |= UNIT2;
// 				break;
// 			case KNIGHT:
// 				WN |= UNIT2;
// 				break;
// 			case BISHOP:
// 				WB |= UNIT2;
// 				break;
// 			case QUEEN:
// 				WQ |= UNIT2;
// 				break;
// 			case KING:
// 				WK |= UNIT2;
// 				break;
// 			case PAWN:
// 				WP |= UNIT2;
// 				break;
// 			default:
// 				break;
// 		}

// 		if ((moves[n][3] == KING) && (moves[n][4] == KING)){
// 			if ((UNIT0 >> 2) == UNIT1){
// 				BR |= 0x0100000000000000UL;
// 				BR ^= 0x0800000000000000UL;
// 			}
// 			else if ((UNIT0 << 2) == UNIT1){
// 				BR |= 0x8000000000000000UL;
// 				BR ^= 0x2000000000000000UL;
// 			}
// 		}
// 		turn = BLACK;
// 	}
// 	else {
// 		switch (moves[n][3]){
// 			case ROOK:
// 				WR |= UNIT0;
// 				break;
// 			case KNIGHT:
// 				WN |= UNIT0;
// 				break;
// 			case BISHOP:
// 				WB |= UNIT0;
// 				break;
// 			case QUEEN:
// 				WQ |= UNIT0;
// 				break;
// 			case KING:
// 				WK |= UNIT0;
// 				break;
// 			case PAWN:	
// 				WP |= UNIT0;
// 				break;
// 			default:
// 				break;
// 		}
// 		switch (moves[n][4]){
// 			case ROOK:
// 				WR ^= UNIT1;
// 				break;
// 			case KNIGHT:
// 				WN ^= UNIT1;
// 				break;
// 			case BISHOP:
// 				WB ^= UNIT1;
// 				break;
// 			case QUEEN:
// 				WQ ^= UNIT1;
// 				break;
// 			case KING:
// 				WK ^= UNIT1;
// 				break;
// 			case PAWN:
// 				WP ^= UNIT1;
// 				break;
// 			default:
// 				break;
// 		}
// 		switch (moves[n][5]){
// 			case ROOK:
// 				BR |= UNIT2;
// 				break;
// 			case KNIGHT:
// 				BN |= UNIT2;
// 				break;
// 			case BISHOP:
// 				BB |= UNIT2;
// 				break;
// 			case QUEEN:
// 				BQ |= UNIT2;
// 				break;
// 			case KING:
// 				BK |= UNIT2;
// 				break;
// 			case PAWN:
// 				BP |= UNIT2;
// 				break;
// 			default:
// 				break;
// 		}

// 		if ((moves[n][3] == KING) && (moves[n][4] == KING)){
// 			if ((UNIT0 >> 2) == UNIT1){
// 				WR |= 0x0000000000000001UL;
// 				WR ^= 0x0000000000000008UL;

// 			}
// 			else if ((UNIT0 << 2)== UNIT1){
// 				WR |= 0x0000000000000080UL;
// 				WR ^= 0x0000000000000020UL;
// 			}
// 		}
// 		turn = WHITE;
// 	}
// 	Update();
// }







