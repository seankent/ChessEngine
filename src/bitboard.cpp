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
	this->wkc = 1;
	this->wqc = 1;
	this->bkc = 1;
	this->bqc = 1;
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
	this->wkc = 1;
	this->wqc = 1;
	this->bkc = 1;
	this->bqc = 1;
}

//==============================================
// LS1B
// this function extracts the least significant 1 bit
// from a 64-bit unsigned int.
//==============================================
void Bitboard::LS1B(uint64_t U64, uint64_t & LS1B, uint8_t & i)
{
	LS1B = U64 & (~U64 + 1);

	const uint8_t DeBruijn[64] = {
		63, 0, 58, 1, 59, 47, 53, 2, 
		60, 39, 48, 27, 54, 33, 42, 3, 
		61, 51, 37, 40, 49, 18, 28, 20, 
		55, 30, 34, 11, 43, 14, 22, 4, 
		62, 57, 46, 52, 38, 26, 32, 41, 
		50, 36, 17, 19, 29, 10, 13, 21, 
		56, 45, 25, 31, 35, 16, 9, 12, 
		44, 24, 15, 8, 23, 7, 6, 5
	};
	i = DeBruijn[(LS1B*0x07EDD5E59A4E28C2UL) >> 58];
} 

//==============================================
// Reverse
//==============================================
uint64_t Bitboard::Reverse(uint64_t U64) 
{
	uint64_t rev = 0;
	for (int i = 0; i < 64; i++){
		rev <<= 1;
		if ((U64 & 1) == 1) 
            rev ^= 1;
        U64 >>= 1;
	}
	return rev;
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
	WHITE_UNITS = WR | WN | WB | WQ | WK | WP;
	BLACK_UNITS = BR | BN | BB | BQ | BK | BP;
	EMPTY = ~(WHITE_UNITS | BLACK_UNITS);
	FILE_EP = 0x0;
	MOVES_W = MovesW(ATTACKS_W);
	MOVES_B = MovesB(ATTACKS_B);
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
			if (j == 7) std::cout << "|" << std::endl;
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
void Bitboard::PrintMoves(uint64_t MOVES)
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
	for (int i = 0; i < 8; i++){
		if (i != 0) std::cout << std::endl;
		for (int j = 0; j < 8; j++){
			if (((U64 >> (8*(7 - i) + j)) & 1) != 0) std::cout << 1;
			else std::cout << 0;
			std::cout << ' ';
		}
	}
	std::cout << std::endl;
}

//==============================================
// MovesWN
//==============================================
uint64_t Bitboard::MovesWN(uint64_t UNIT, uint8_t i)
{	
	if (UNIT == 0x0000000000000000UL) return 0x0000000000000000UL;
	if (i < 27){
		if ((i & 0x07) < 4) return (MOVES_N >> (27 - i)) & ~WHITE_UNITS & ~FILE_G & ~FILE_H;
		else return (MOVES_N >> (27 - i)) & ~WHITE_UNITS & ~FILE_A & ~FILE_B;
	} 
	else {
		if ((i & 0x07) < 4) return (MOVES_N << (i - 27)) & ~WHITE_UNITS & ~FILE_G & ~FILE_H;
		else return (MOVES_N << (i - 27)) & ~WHITE_UNITS & ~FILE_A & ~FILE_B;
	}
}

//==============================================
// MovesBN
//==============================================
uint64_t Bitboard::MovesBN(uint64_t UNIT, uint8_t i)
{	
	if (UNIT == 0x0000000000000000UL) return 0x0000000000000000UL;
	if (i < 27){
		if ((i & 0x07) < 4) return (MOVES_N >> (27 - i)) & ~BLACK_UNITS & ~FILE_G & ~FILE_H;
		else return (MOVES_N >> (27 - i)) & ~BLACK_UNITS & ~FILE_A & ~FILE_B;
	} 
	else {
		if ((i & 0x07) < 4) return (MOVES_N << (i - 27)) & ~BLACK_UNITS & ~FILE_G & ~FILE_H;
		else return (MOVES_N << (i - 27)) & ~BLACK_UNITS & ~FILE_A & ~FILE_B;
	}	
}

//==============================================
// MovesWR
//==============================================
uint64_t Bitboard::MovesWR(uint64_t UNIT, uint8_t i)
{	
	uint64_t RANK = RANKS[i/8];
	uint64_t FILE = FILES[i & 0x7];
	return (((((~EMPTY & RANK) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & RANK) - (Reverse(UNIT) << 1))) & RANK) |
		   ((((~EMPTY & FILE) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & FILE) - (Reverse(UNIT) << 1))) & FILE)) & ~WHITE_UNITS;	 
}

//==============================================
// MovesBR
//==============================================
uint64_t Bitboard::MovesBR(uint64_t UNIT, uint8_t i)
{	
	uint64_t RANK = RANKS[i/8];
	uint64_t FILE = FILES[i & 0x7];
	return (((((~EMPTY & RANK) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & RANK) - (Reverse(UNIT) << 1))) & RANK) |
		   ((((~EMPTY & FILE) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & FILE) - (Reverse(UNIT) << 1))) & FILE)) & ~BLACK_UNITS;
}

//==============================================
// MovesWB
//==============================================
uint64_t Bitboard::MovesWB(uint64_t UNIT, uint8_t i)
{	
	uint64_t DIAGONAL_UP = DIAGONALS_UP[7 - i/8 + (i & 0x7)];
	uint64_t DIAGONAL_DOWN = DIAGONALS_DOWN[i/8 + (i & 0x7)];
	return (((((~EMPTY & DIAGONAL_UP) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & DIAGONAL_UP) - (Reverse(UNIT) << 1))) & DIAGONAL_UP) |
		   ((((~EMPTY & DIAGONAL_DOWN) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & DIAGONAL_DOWN) - (Reverse(UNIT) << 1))) & DIAGONAL_DOWN)) & ~WHITE_UNITS;
}

//==============================================
// MovesBB
//==============================================
uint64_t Bitboard::MovesBB(uint64_t UNIT, uint8_t i)
{	
	uint64_t DIAGONAL_UP = DIAGONALS_UP[7 - i/8 + (i & 0x7)];
	uint64_t DIAGONAL_DOWN = DIAGONALS_DOWN[i/8 + (i & 0x7)];
	return (((((~EMPTY & DIAGONAL_UP) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & DIAGONAL_UP) - (Reverse(UNIT) << 1))) & DIAGONAL_UP) |
		   ((((~EMPTY & DIAGONAL_DOWN) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & DIAGONAL_DOWN) - (Reverse(UNIT) << 1))) & DIAGONAL_DOWN)) & ~BLACK_UNITS;
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
uint64_t Bitboard::MovesWK(uint64_t UNIT, uint8_t i)
{	
	if (UNIT == 0) return 0;
	uint64_t MOVES;
	if (i < 27){
		if ((i & 0x07) < 4) MOVES = (MOVES_K >> (27 - i)) & ~WHITE_UNITS & ~FILE_H;
		else MOVES =  (MOVES_K >> (27 - i)) & ~WHITE_UNITS & ~FILE_A;
	} 
	else {
		if ((i & 0x07) < 4) MOVES =  (MOVES_K << (i - 27)) & ~WHITE_UNITS & ~FILE_H;
		else MOVES =  (MOVES_K << (i - 27)) & ~WHITE_UNITS & ~FILE_A;
	}
	if (wqc && ((UNIT & 0x0000000000000010UL) != 0) && ((WR & 0x0000000000000001UL) != 0) && ((~EMPTY & 0x000000000000000EUL) == 0) && ((ATTACKS_B & 0x000000000000001CUL) == 0)) MOVES |= UNIT >> 2;			// queenside castle
	if (wkc && ((UNIT & 0x0000000000000010UL) != 0) && ((WR & 0x0000000000000080UL) != 0) && ((~EMPTY & 0x0000000000000060UL) == 0) && ((ATTACKS_B & 0x0000000000000070UL) == 0)) MOVES |= UNIT << 2;			// kingside castle
	return MOVES;
}

//==============================================
// MovesBK
//==============================================
uint64_t Bitboard::MovesBK(uint64_t UNIT, uint8_t i)
{	
	if (UNIT == 0) return 0;
	uint64_t MOVES;
	if (i < 27){
		if ((i & 0x07) < 4) MOVES = (MOVES_K >> (27 - i)) & ~BLACK_UNITS & ~FILE_H;
		else MOVES = (MOVES_K >> (27 - i)) & ~BLACK_UNITS & ~FILE_A;
	} 
	else {
		if ((i & 0x07) < 4) MOVES = (MOVES_K << (i - 27)) & ~BLACK_UNITS & ~FILE_H;
		else MOVES = (MOVES_K << (i - 27)) & ~BLACK_UNITS & ~FILE_A;
	}
	if (bqc && ((UNIT & 0x1000000000000000UL) != 0) && ((BR & 0x0100000000000000UL) != 0) && ((~EMPTY & 0x0E00000000000000UL) == 0) && ((ATTACKS_W & 0x1C00000000000000UL) == 0)) MOVES |= UNIT >> 2;			// queenside castle
	if (bkc && ((UNIT & 0x1000000000000000UL) != 0) && ((BR & 0x8000000000000000UL) != 0) && ((~EMPTY & 0x6000000000000000UL) == 0) && ((ATTACKS_W & 0x7000000000000000UL) == 0)) MOVES |= UNIT << 2;			// kingside castle
	return MOVES;
}

//==============================================
// MovesWP
//==============================================
uint64_t Bitboard::MovesWP(uint64_t UNIT)
{	
	if (UNIT == 0) return 0;
	uint64_t PAWN_RIGHT = (UNIT << 9) & BLACK_UNITS & ~FILE_A; 						// capture right
	uint64_t PAWN_LEFT = (UNIT << 7) & BLACK_UNITS & ~FILE_H; 						// capture left
	uint64_t PAWN_FORWARD_1 = (UNIT << 8) & EMPTY; 									// move forward 1
	uint64_t PAWN_FORWARD_2 = (UNIT << 16) & EMPTY & (EMPTY << 8) & RANK_4; 		// move forward 2
	uint64_t PAWN_RIGHT_EP = (UNIT << 9) & (BP << 8) & RANK_6 & ~FILE_A & FILE_EP; 	// en passant right
	uint64_t PAWN_LEFT_EP = (UNIT << 7) & (BP << 8) & RANK_6 & ~FILE_H & FILE_EP; 	// en passant left
	return PAWN_RIGHT | PAWN_LEFT | PAWN_FORWARD_1 | PAWN_FORWARD_2 | PAWN_RIGHT_EP | PAWN_LEFT_EP;
}

//==============================================
// MovesBP
//==============================================
uint64_t Bitboard::MovesBP(uint64_t UNIT)
{	
	if (UNIT == 0) return 0;
	uint64_t PAWN_RIGHT = (UNIT >> 7) & WHITE_UNITS & ~FILE_A; 						// capture right
	uint64_t PAWN_LEFT = (UNIT >> 9) & WHITE_UNITS & ~FILE_H; 						// capture left
	uint64_t PAWN_FORWARD_1 = (UNIT >> 8) & EMPTY; 									// move forward 1
	uint64_t PAWN_FORWARD_2 = (UNIT >> 16) & EMPTY & (EMPTY >> 8) & RANK_5; 		// move forward 2
	uint64_t PAWN_RIGHT_EP = (UNIT >> 7) & (WP >> 8) & RANK_3 & ~FILE_A & FILE_EP; 	// en passant right
	uint64_t PAWN_LEFT_EP = (UNIT >> 9) & (WP >> 8) & RANK_3 & ~FILE_H & FILE_EP; 	// en passant left
	return PAWN_RIGHT | PAWN_LEFT | PAWN_FORWARD_1 | PAWN_FORWARD_2 | PAWN_RIGHT_EP | PAWN_LEFT_EP;
}

//==============================================
// MovesW
//==============================================
uint64_t Bitboard::MovesW(uint64_t & ATTACKS)
{		
	uint64_t WR = this->WR;		// make copy of WR
	uint64_t WN = this->WN;		// make copy of WN
	uint64_t WB = this->WB;		// make copy of WB
	uint64_t WQ = this->WQ;		// make copy of WQ
	uint64_t WK = this->WK;		// make copy of WK
	uint64_t WP = this->WP;		// make copy of WP

	uint64_t MOVES;
	uint64_t UNIT;
	uint8_t i;
	MOVES = MovesWP(WP);

	while (WR != 0){
		LS1B(WR, UNIT, i);
		MOVES |= MovesWR(UNIT, i);
		WR ^= UNIT;
	}
	while (WN != 0){
		LS1B(WN, UNIT, i);
		MOVES |= MovesWN(UNIT, i);
		WN ^= UNIT;
	}
	while (WB != 0){
		LS1B(WB, UNIT, i);
		MOVES |= MovesWB(UNIT, i);
		WB ^= UNIT;
	}
	while (WQ != 0){
		LS1B(WQ, UNIT, i);
		MOVES |= MovesWQ(UNIT, i);
		WQ ^= UNIT;
	}
	while (WK != 0){
		LS1B(WK, UNIT, i);
		MOVES |= MovesWK(UNIT, i);
		WK ^= UNIT;
	}
	ATTACKS = MOVES | ((WP << 9) & ~FILE_A) | ((WP << 7) & ~FILE_H);
	MOVES |= MovesWP(WP);
	return MOVES;
}

//==============================================
// MovesB
//==============================================
uint64_t Bitboard::MovesB(uint64_t & ATTACKS)
{		
	uint64_t BR = this->BR;		// make copy of WR
	uint64_t BN = this->BN;		// make copy of WN
	uint64_t BB = this->BB;		// make copy of WB
	uint64_t BQ = this->BQ;		// make copy of WQ
	uint64_t BK = this->BK;		// make copy of WK
	uint64_t BP = this->BP;		// make copy of WP

	uint64_t MOVES = 0x0UL;
	uint64_t UNIT;
	uint8_t i;

	while (BR != 0){
		LS1B(BR, UNIT, i);
		MOVES |= MovesBR(UNIT, i);
		BR ^= UNIT;
	}
	while (BN != 0){
		LS1B(BN, UNIT, i);
		MOVES |= MovesBN(UNIT, i);
		BN ^= UNIT;
	}
	while (BB != 0){
		LS1B(BB, UNIT, i);
		MOVES |= MovesBB(UNIT, i);
		BB ^= UNIT;
	}
	while (BQ != 0){
		LS1B(BQ, UNIT, i);
		MOVES |= MovesBQ(UNIT, i);
		BQ ^= UNIT;
	}
	while (BK != 0){
		LS1B(BK, UNIT, i);
		MOVES |= MovesBK(UNIT, i);
		BK ^= UNIT;
	}

	ATTACKS = MOVES | ((BP >> 7) & ~FILE_A) | ((BP >> 9) & ~FILE_H);
	MOVES |= MovesBP(BP);
	return MOVES;
}

//==============================================
// Move
//==============================================
bool Bitboard::Move(uint8_t i0, uint8_t i1, uint8_t piece)
{
	uint64_t UNIT_0 = 0x1UL << i0;
	uint64_t UNIT_1 = 0x1UL << i1;
	uint64_t MOVES;
	if (turn == WHITE){
		if ((UNIT_0 & WP) != 0){
			MOVES = MovesWP(UNIT_0);
			if ((UNIT_1 & MOVES) == 0) return 0;
			if ((UNIT_1 & RANK_8) != 0){	// pawn promotion
				switch (piece){
					case ROOK:
						WP ^= UNIT_0;
						WR |= UNIT_1;
						break;
					case KNIGHT:
						WP ^= UNIT_0;
						WN |= UNIT_1;
						break;
					case BISHOP:
						WP ^= UNIT_0;
						WB |= UNIT_1;
						break;
					case QUEEN:
						WP ^= UNIT_0;
						WQ |= UNIT_1;
						break;
					default:
						return 0;
				}
			} 
			else {
				WP ^= UNIT_0;
				WP |= UNIT_1;
			}
			if (UNIT_1 & FILE_EP & RANK_6) BP ^= (UNIT_1 >> 8);
			if (UNIT_0 << 16 == UNIT_1) FILE_EP = FILES[i0 & 0x7];
			else FILE_EP = 0x0;
		}
		else if ((UNIT_0 & WR) != 0){
			MOVES = MovesWR(UNIT_0, i0);
			if ((UNIT_1 & MOVES) == 0) return 0;			
			WR ^= UNIT_0;
			WR |= UNIT_1;
			FILE_EP = 0x0;
			if ((WR & 0x0000000000000001UL) == 0) wqc = 0;
			if ((WR & 0x0000000000000080UL) == 0) wkc = 0;
		} 
		else if ((UNIT_0 & WN) != 0){
			MOVES = MovesWN(UNIT_0, i0);
			if ((UNIT_1 & MOVES) == 0) return 0;			
			WN ^= UNIT_0;
			WN |= UNIT_1;
			FILE_EP = 0x0;
		} 
		else if ((UNIT_0 & WB) != 0){
			MOVES = MovesWB(UNIT_0, i0);
			if ((UNIT_1 & MOVES) == 0) return 0;	
			WB ^= UNIT_0;
			WB |= UNIT_1;
			FILE_EP = 0x0;
		}
		else if ((UNIT_0 & WQ) != 0){
			MOVES = MovesWQ(UNIT_0, i0);
			if ((UNIT_1 & MOVES) == 0) return 0;			
			WQ ^= UNIT_0;
			WQ |= UNIT_1;
			FILE_EP = 0x0;
		}
		else if ((UNIT_0 & WK) != 0){
			MOVES = MovesWK(UNIT_0, i0);
			if ((UNIT_1 & MOVES) == 0) return 0;			
			WK ^= UNIT_0;
			WK |= UNIT_1;
			if ((UNIT_0 >> 2) == UNIT_1){
				WR ^= 0x0000000000000001UL;
				WR |= 0x0000000000000008UL;
			}
			if ((UNIT_0 << 2) == UNIT_1){
				WR ^= 0x0000000000000080UL;
				WR |= 0x0000000000000020UL;
			}
			wqc = 0;
			wkc = 0;
			FILE_EP = 0x0;
		}
		else {
			return 0;
		}
		if ((UNIT_1 & BP) != 0) BP ^= UNIT_1;
		else if ((UNIT_1 & BR) != 0) BR ^= UNIT_1;
		else if ((UNIT_1 & BN) != 0) BN ^= UNIT_1;
		else if ((UNIT_1 & BB) != 0) BB ^= UNIT_1;
		else if ((UNIT_1 & BQ) != 0) BQ ^= UNIT_1;
		else if ((UNIT_1 & BK) != 0) BK ^= UNIT_1;
		turn = BLACK;
	} 
	else {
		if ((UNIT_0 & BP) != 0){
			MOVES = MovesBP(UNIT_0);
			if ((UNIT_1 & MOVES) == 0) return 0;
			if ((UNIT_1 & RANK_1) != 0){	// pawn promotion
				switch (piece){
					case ROOK:
						BP ^= UNIT_0;
						BR |= UNIT_1;
						break;
					case KNIGHT:
						BP ^= UNIT_0;
						BN |= UNIT_1;
						break;
					case BISHOP:
						BP ^= UNIT_0;
						BB |= UNIT_1;
						break;
					case QUEEN:
						BP ^= UNIT_0;
						BQ |= UNIT_1;
						break;
					default:
						return 0;
				}
			} 
			else {
				BP ^= UNIT_0;
				BP |= UNIT_1;
			}		
			if (UNIT_1 & FILE_EP & RANK_3) WP ^= (UNIT_1 << 8);
			if (UNIT_0 >> 16 == UNIT_1) FILE_EP = FILES[i0 & 0x7];
			else FILE_EP = 0x0;
		}
		else if ((UNIT_0 & BR) != 0){
			MOVES = MovesBR(UNIT_0, i0);
			if ((UNIT_1 & MOVES) == 0) return 0;			
			BR ^= UNIT_0;
			BR |= UNIT_1;
			FILE_EP = 0x0;
			if ((BR & 0x0100000000000000UL) == 0) bqc = 0;
			if ((BR & 0x8000000000000000UL) == 0) bkc = 0;
		} 
		else if ((UNIT_0 & BN) != 0){
			MOVES = MovesBN(UNIT_0, i0);
			if ((UNIT_1 & MOVES) == 0) return 0;			
			BN ^= UNIT_0;
			BN |= UNIT_1;
			FILE_EP = 0x0;
		} 
		else if ((UNIT_0 & BB) != 0){
			MOVES = MovesBB(UNIT_0, i0);
			if ((UNIT_1 & MOVES) == 0) return 0;			
			BB ^= UNIT_0;
			BB |= UNIT_1;
			FILE_EP = 0x0;
		}
		else if ((UNIT_0 & BQ) != 0){
			MOVES = MovesBQ(UNIT_0, i0);
			if ((UNIT_1 & MOVES) == 0) return 0;			
			BQ ^= UNIT_0;
			BQ |= UNIT_1;
			FILE_EP = 0x0;
		}
		else if ((UNIT_0 & BK) != 0){
			MOVES = MovesBK(UNIT_0, i0);
			if ((UNIT_1 & MOVES) == 0) return 0;			
			BK ^= UNIT_0;
			BK |= UNIT_1;
			if ((UNIT_0 >> 2) == UNIT_1){
				BR ^= 0x0100000000000000UL;
				BR |= 0x0800000000000000UL;
			}
			if ((UNIT_0 << 2) == UNIT_1){
				BR ^= 0x8000000000000000UL;
				BR |= 0x2000000000000000UL;
			}
			bqc = 0;
			bkc = 0;
			FILE_EP = 0x0;
		}
		else {
			return 0;
		}
		if ((UNIT_1 & WP) != 0) WP ^= UNIT_1;
		else if ((UNIT_1 & WR) != 0) WR ^= UNIT_1;
		else if ((UNIT_1 & WN) != 0) WN ^= UNIT_1;
		else if ((UNIT_1 & WB) != 0) WB ^= UNIT_1;
		else if ((UNIT_1 & WQ) != 0) WQ ^= UNIT_1;
		else if ((UNIT_1 & WK) != 0) WK ^= UNIT_1;
		turn = WHITE;
	}
	WHITE_UNITS = WR | WN | WB | WQ | WK | WP;
	BLACK_UNITS = BR | BN | BB | BQ | BK | BP;
	EMPTY = ~(WHITE_UNITS | BLACK_UNITS);
	MOVES_W = MovesW(ATTACKS_W);
	MOVES_B = MovesB(ATTACKS_B);
	return 1;
}







