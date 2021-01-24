//==============================================
// include
//==============================================
#include "bitboard.hpp"

//==============================================
// Bitboard
//==============================================
Bitboard::Bitboard(char board[8][8])
{
	BoardToBitboard(board);	
	FILE_A = 0x0101010101010101UL;
	FILE_B = 0x0202020202020202UL;
	FILE_C = 0x0404040404040404UL;
	FILE_D = 0x0808080808080808UL;
	FILE_E = 0x1010101010101010UL;
	FILE_F = 0x2020202020202020UL;
	FILE_G = 0x4040404040404040UL;
	FILE_H = 0x8080808080808080UL;
	RANK_1 = 0x00000000000000ffUL;
	RANK_2 = 0x000000000000ff00UL;
	RANK_3 = 0x0000000000ff0000UL;
	RANK_4 = 0x00000000ff000000UL;
	RANK_5 = 0x000000ff00000000UL;
	RANK_6 = 0x0000ff0000000000UL;
	RANK_7 = 0x00ff000000000000UL;
	RANK_8 = 0xff00000000000000UL;
	DIAGONAL_A8A8 = 0x0100000000000000UL;	// bitboard for the a8-a8 diagonal
	DIAGONAL_A7B8 = 0x0201000000000000UL; 	// bitboard for the a7-b8 diagonal
	DIAGONAL_A6C8 = 0x0402010000000000UL;	// bitboard for the a6-c8 diagonal
	DIAGONAL_A5D8 = 0x0804020100000000UL;	// bitboard for the a5-d8 diagonal
	DIAGONAL_A4E8 = 0x1008040201000000UL;	// bitboard for the a4-e8 diagonal
	DIAGONAL_A3F8 = 0x2010080402010000UL;	// bitboard for the a3-f8 diagonal
	DIAGONAL_A2G8 = 0x4020100804020100UL;	// bitboard for the a2-g8 diagonal
	DIAGONAL_A1H8 = 0x8040201008040201UL;	// bitboard for the a1-h8 diagonal
	DIAGONAL_B1H7 = 0x0080402010080402UL;	// bitboard for the b1-h8 diagonal
	DIAGONAL_C1H6 = 0x0000804020100804UL;	// bitboard for the c1-h8 diagonal
	DIAGONAL_D1H5 = 0x0000008040201008UL;	// bitboard for the d1-h8 diagonal
	DIAGONAL_E1H4 = 0x0000000080402010UL;	// bitboard for the e1-h8 diagonal
	DIAGONAL_F1H3 = 0x0000000000804020UL;	// bitboard for the f1-h8 diagonal
	DIAGONAL_G1H2 = 0x0000000000008040UL;	// bitboard for the g1-h8 diagonal
	DIAGONAL_H1H1 = 0x0000000000000080UL;	// bitboard for the h1-h8 diagonal
	DIAGONAL_A1A1 = 0x0000000000000001UL;	// bitboard for the a1-a1 diagonal
	DIAGONAL_A2B1 = 0x0000000000000102UL; 	// bitboard for the a2-b1 diagonal
	DIAGONAL_A3C1 = 0x0000000000010204UL;	// bitboard for the a3-c1 diagonal
	DIAGONAL_A4D1 = 0x0000000001020408UL;	// bitboard for the a4-d1 diagonal
	DIAGONAL_A5E1 = 0x0000000102040810UL;	// bitboard for the a5-e1 diagonal
	DIAGONAL_A6F1 = 0x0000010204081020UL;	// bitboard for the a6-f1 diagonal
	DIAGONAL_A7G1 = 0x0001020408102040UL;	// bitboard for the a7-g1 diagonal
	DIAGONAL_A8H1 = 0x0102040810204080UL;	// bitboard for the a8-h1 diagonal
	DIAGONAL_B8H2 = 0x0204081020408000UL;	// bitboard for the b8-h2 diagonal
	DIAGONAL_C8H3 = 0x0408102040800000UL;	// bitboard for the c8-h3 diagonal
	DIAGONAL_D8H4 = 0x0810204080000000UL;	// bitboard for the d8-h4 diagonal
	DIAGONAL_E8H5 = 0x1020408000000000UL;	// bitboard for the e8-h5 diagonal
	DIAGONAL_F8H6 = 0x2040800000000000UL;	// bitboard for the f8-h6 diagonal
	DIAGONAL_G8H7 = 0x4080000000000000UL;	// bitboard for the g8-h7 diagonal
	DIAGONAL_H8H8 = 0x8000000000000000UL;	// bitboard for the h8-h8 diagonal
	FILES[0] = FILE_A;
	FILES[1] = FILE_B;
	FILES[2] = FILE_C;
	FILES[3] = FILE_D;
	FILES[4] = FILE_E;
	FILES[5] = FILE_F;
	FILES[6] = FILE_G;
	FILES[7] = FILE_H;
	RANKS[0] = RANK_1;
	RANKS[1] = RANK_2;
	RANKS[2] = RANK_3;
	RANKS[3] = RANK_4;
	RANKS[4] = RANK_5;
	RANKS[5] = RANK_6;
	RANKS[6] = RANK_7;
	RANKS[7] = RANK_8;
	DIAGONALS_UP[0] = DIAGONAL_A8A8;
	DIAGONALS_UP[1] = DIAGONAL_A7B8;
	DIAGONALS_UP[2] = DIAGONAL_A6C8;
	DIAGONALS_UP[3] = DIAGONAL_A5D8;
	DIAGONALS_UP[4] = DIAGONAL_A4E8;
	DIAGONALS_UP[5] = DIAGONAL_A3F8;
	DIAGONALS_UP[6] = DIAGONAL_A2G8;
	DIAGONALS_UP[7] = DIAGONAL_A1H8;
	DIAGONALS_UP[8] = DIAGONAL_B1H7;
	DIAGONALS_UP[9] = DIAGONAL_C1H6;
	DIAGONALS_UP[10] = DIAGONAL_D1H5;
	DIAGONALS_UP[11] = DIAGONAL_E1H4;
	DIAGONALS_UP[12] = DIAGONAL_F1H3;
	DIAGONALS_UP[13] = DIAGONAL_G1H2;
	DIAGONALS_UP[14] = DIAGONAL_H1H1;
	DIAGONALS_DOWN[0] = DIAGONAL_A1A1;
	DIAGONALS_DOWN[1] = DIAGONAL_A2B1;
	DIAGONALS_DOWN[2] = DIAGONAL_A3C1;
	DIAGONALS_DOWN[3] = DIAGONAL_A4D1;
	DIAGONALS_DOWN[4] = DIAGONAL_A5E1;
	DIAGONALS_DOWN[5] = DIAGONAL_A6F1;
	DIAGONALS_DOWN[6] = DIAGONAL_A7G1;
	DIAGONALS_DOWN[7] = DIAGONAL_A8H1;
	DIAGONALS_DOWN[8] = DIAGONAL_B8H2;
	DIAGONALS_DOWN[9] = DIAGONAL_C8H3;
	DIAGONALS_DOWN[10] = DIAGONAL_D8H4;
	DIAGONALS_DOWN[11] = DIAGONAL_E8H5;
	DIAGONALS_DOWN[12] = DIAGONAL_F8H6;
	DIAGONALS_DOWN[13] = DIAGONAL_G8H7;
	DIAGONALS_DOWN[14] = DIAGONAL_H8H8;
	MOVES_N = 0x0000142200221400UL;
	MOVES_K = 0x0000001C141C0000UL;
	WHITE_UNITS = WR | WN | WB | WQ | WK | WP;
	BLACK_UNITS = BR | BN | BB | BQ | BK | BP;
	EMPTY = ~(WHITE_UNITS | BLACK_UNITS);
	FILE_EP = 0x0000000000000000UL;
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
	FILE_A = 0x0101010101010101UL;
	FILE_B = 0x0202020202020202UL;
	FILE_C = 0x0404040404040404UL;
	FILE_D = 0x0808080808080808UL;
	FILE_E = 0x1010101010101010UL;
	FILE_F = 0x2020202020202020UL;
	FILE_G = 0x4040404040404040UL;
	FILE_H = 0x8080808080808080UL;
	RANK_1 = 0x00000000000000ffUL;
	RANK_2 = 0x000000000000ff00UL;
	RANK_3 = 0x0000000000ff0000UL;
	RANK_4 = 0x00000000ff000000UL;
	RANK_5 = 0x000000ff00000000UL;
	RANK_6 = 0x0000ff0000000000UL;
	RANK_7 = 0x00ff000000000000UL;
	RANK_8 = 0xff00000000000000UL;
	DIAGONAL_A8A8 = 0x0100000000000000UL;	// bitboard for the a8-a8 diagonal
	DIAGONAL_A7B8 = 0x0201000000000000UL; 	// bitboard for the a7-b8 diagonal
	DIAGONAL_A6C8 = 0x0402010000000000UL;	// bitboard for the a6-c8 diagonal
	DIAGONAL_A5D8 = 0x0804020100000000UL;	// bitboard for the a5-d8 diagonal
	DIAGONAL_A4E8 = 0x1008040201000000UL;	// bitboard for the a4-e8 diagonal
	DIAGONAL_A3F8 = 0x2010080402010000UL;	// bitboard for the a3-f8 diagonal
	DIAGONAL_A2G8 = 0x4020100804020100UL;	// bitboard for the a2-g8 diagonal
	DIAGONAL_A1H8 = 0x8040201008040201UL;	// bitboard for the a1-h8 diagonal
	DIAGONAL_B1H7 = 0x0080402010080402UL;	// bitboard for the b1-h8 diagonal
	DIAGONAL_C1H6 = 0x0000804020100804UL;	// bitboard for the c1-h8 diagonal
	DIAGONAL_D1H5 = 0x0000008040201008UL;	// bitboard for the d1-h8 diagonal
	DIAGONAL_E1H4 = 0x0000000080402010UL;	// bitboard for the e1-h8 diagonal
	DIAGONAL_F1H3 = 0x0000000000804020UL;	// bitboard for the f1-h8 diagonal
	DIAGONAL_G1H2 = 0x0000000000008040UL;	// bitboard for the g1-h8 diagonal
	DIAGONAL_H1H1 = 0x0000000000000080UL;	// bitboard for the h1-h8 diagonal
	DIAGONAL_A1A1 = 0x0000000000000001UL;	// bitboard for the a1-a1 diagonal
	DIAGONAL_A2B1 = 0x0000000000000102UL; 	// bitboard for the a2-b1 diagonal
	DIAGONAL_A3C1 = 0x0000000000010204UL;	// bitboard for the a3-c1 diagonal
	DIAGONAL_A4D1 = 0x0000000001020408UL;	// bitboard for the a4-d1 diagonal
	DIAGONAL_A5E1 = 0x0000000102040810UL;	// bitboard for the a5-e1 diagonal
	DIAGONAL_A6F1 = 0x0000010204081020UL;	// bitboard for the a6-f1 diagonal
	DIAGONAL_A7G1 = 0x0001020408102040UL;	// bitboard for the a7-g1 diagonal
	DIAGONAL_A8H1 = 0x0102040810204080UL;	// bitboard for the a8-h1 diagonal
	DIAGONAL_B8H2 = 0x0204081020408000UL;	// bitboard for the b8-h2 diagonal
	DIAGONAL_C8H3 = 0x0408102040800000UL;	// bitboard for the c8-h3 diagonal
	DIAGONAL_D8H4 = 0x0810204080000000UL;	// bitboard for the d8-h4 diagonal
	DIAGONAL_E8H5 = 0x1020408000000000UL;	// bitboard for the e8-h5 diagonal
	DIAGONAL_F8H6 = 0x2040800000000000UL;	// bitboard for the f8-h6 diagonal
	DIAGONAL_G8H7 = 0x4080000000000000UL;	// bitboard for the g8-h7 diagonal
	DIAGONAL_H8H8 = 0x8000000000000000UL;	// bitboard for the h8-h8 diagonal
	FILES[0] = FILE_A;
	FILES[1] = FILE_B;
	FILES[2] = FILE_C;
	FILES[3] = FILE_D;
	FILES[4] = FILE_E;
	FILES[5] = FILE_F;
	FILES[6] = FILE_G;
	FILES[7] = FILE_H;
	RANKS[0] = RANK_1;
	RANKS[1] = RANK_2;
	RANKS[2] = RANK_3;
	RANKS[3] = RANK_4;
	RANKS[4] = RANK_5;
	RANKS[5] = RANK_6;
	RANKS[6] = RANK_7;
	RANKS[7] = RANK_8;
	DIAGONALS_UP[0] = DIAGONAL_A8A8;
	DIAGONALS_UP[1] = DIAGONAL_A7B8;
	DIAGONALS_UP[2] = DIAGONAL_A6C8;
	DIAGONALS_UP[3] = DIAGONAL_A5D8;
	DIAGONALS_UP[4] = DIAGONAL_A4E8;
	DIAGONALS_UP[5] = DIAGONAL_A3F8;
	DIAGONALS_UP[6] = DIAGONAL_A2G8;
	DIAGONALS_UP[7] = DIAGONAL_A1H8;
	DIAGONALS_UP[8] = DIAGONAL_B1H7;
	DIAGONALS_UP[9] = DIAGONAL_C1H6;
	DIAGONALS_UP[10] = DIAGONAL_D1H5;
	DIAGONALS_UP[11] = DIAGONAL_E1H4;
	DIAGONALS_UP[12] = DIAGONAL_F1H3;
	DIAGONALS_UP[13] = DIAGONAL_G1H2;
	DIAGONALS_UP[14] = DIAGONAL_H1H1;
	DIAGONALS_DOWN[0] = DIAGONAL_A1A1;
	DIAGONALS_DOWN[1] = DIAGONAL_A2B1;
	DIAGONALS_DOWN[2] = DIAGONAL_A3C1;
	DIAGONALS_DOWN[3] = DIAGONAL_A4D1;
	DIAGONALS_DOWN[4] = DIAGONAL_A5E1;
	DIAGONALS_DOWN[5] = DIAGONAL_A6F1;
	DIAGONALS_DOWN[6] = DIAGONAL_A7G1;
	DIAGONALS_DOWN[7] = DIAGONAL_A8H1;
	DIAGONALS_DOWN[8] = DIAGONAL_B8H2;
	DIAGONALS_DOWN[9] = DIAGONAL_C8H3;
	DIAGONALS_DOWN[10] = DIAGONAL_D8H4;
	DIAGONALS_DOWN[11] = DIAGONAL_E8H5;
	DIAGONALS_DOWN[12] = DIAGONAL_F8H6;
	DIAGONALS_DOWN[13] = DIAGONAL_G8H7;
	DIAGONALS_DOWN[14] = DIAGONAL_H8H8;
	MOVES_N = 0x0000142200221400UL;
	MOVES_K = 0x0000001C141C0000UL;
	WHITE_UNITS = WR | WN | WB | WQ | WK | WP;
	BLACK_UNITS = BR | BN | BB | BQ | BK | BP;
	EMPTY = ~(WHITE_UNITS | BLACK_UNITS);
	FILE_EP = 0x0000000000000000UL;
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
	WR = 0x0000000000000000UL;
	WN = 0x0000000000000000UL;
	WB = 0x0000000000000000UL;
	WQ = 0x0000000000000000UL;
	WK = 0x0000000000000000UL; 
	WP = 0x0000000000000000UL; 
	BR = 0x0000000000000000UL;
	BN = 0x0000000000000000UL;
	BB = 0x0000000000000000UL;
	BQ = 0x0000000000000000UL;
	BK = 0x0000000000000000UL;
	BP = 0x0000000000000000UL;

	for (int i = 0; i < 64; i++){
		switch (board[7 - i/8][i%8]){
			case 'R':
				WR += 0x0000000000000001UL << i;
				break;
			case 'N':
				WN += 0x0000000000000001UL << i;
				break;
			case 'B':
				WB += 0x0000000000000001UL << i;
				break;
			case 'Q':
				WQ += 0x0000000000000001UL << i;
				break;
			case 'K':
				WK += 0x0000000000000001UL << i;
				break;
			case 'P':
				WP += 0x0000000000000001UL << i;
				break;
			case 'r':
				BR += 0x0000000000000001UL << i;
				break;
			case 'n':
				BN += 0x0000000000000001UL << i;
				break;
			case 'b':
				BB += 0x0000000000000001UL << i;
				break;
			case 'q':
				BQ += 0x0000000000000001UL << i;
				break;
			case 'k':
				BK += 0x0000000000000001UL << i;
				break;
			case 'p':
				BP += 0x0000000000000001UL << i;
				break;
			default:
				break;
		}
	}
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
	} else {
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
	} else {
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
	uint64_t FILE = FILES[i & 0x07];
	return (((((~EMPTY & RANK) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & RANK) - (Reverse(UNIT) << 1))) & RANK) |
		   ((((~EMPTY & FILE) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & FILE) - (Reverse(UNIT) << 1))) & FILE)) & ~WHITE_UNITS;	 
}

//==============================================
// MovesBR
//==============================================
uint64_t Bitboard::MovesBR(uint64_t UNIT, uint8_t i)
{	
	uint64_t RANK = RANKS[i/8];
	uint64_t FILE = FILES[i & 0x07];
	return (((((~EMPTY & RANK) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & RANK) - (Reverse(UNIT) << 1))) & RANK) |
		   ((((~EMPTY & FILE) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & FILE) - (Reverse(UNIT) << 1))) & FILE)) & ~BLACK_UNITS;
}

//==============================================
// MovesWB
//==============================================
uint64_t Bitboard::MovesWB(uint64_t UNIT, uint8_t i)
{	
	uint64_t DIAGONAL_UP = DIAGONALS_UP[7 - i/8 + (i & 0x07)];
	uint64_t DIAGONAL_DOWN = DIAGONALS_DOWN[i/8 + (i & 0x07)];
	return (((((~EMPTY & DIAGONAL_UP) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & DIAGONAL_UP) - (Reverse(UNIT) << 1))) & DIAGONAL_UP) |
		   ((((~EMPTY & DIAGONAL_DOWN) - (UNIT << 1)) ^ Reverse(Reverse(~EMPTY & DIAGONAL_DOWN) - (Reverse(UNIT) << 1))) & DIAGONAL_DOWN)) & ~WHITE_UNITS;
}

//==============================================
// MovesBB
//==============================================
uint64_t Bitboard::MovesBB(uint64_t UNIT, uint8_t i)
{	
	uint64_t DIAGONAL_UP = DIAGONALS_UP[7 - i/8 + (i & 0x07)];
	uint64_t DIAGONAL_DOWN = DIAGONALS_DOWN[i/8 + (i & 0x07)];
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
	if (UNIT == 0x0000000000000000UL) return 0x0000000000000000UL;
	if (i < 27){
		if ((i & 0x07) < 4) return (MOVES_K >> (27 - i)) & ~WHITE_UNITS & ~FILE_H;
		else return (MOVES_K >> (27 - i)) & ~WHITE_UNITS & ~FILE_A;
	} else {
		if ((i & 0x07) < 4) return (MOVES_K << (i - 27)) & ~WHITE_UNITS & ~FILE_H;
		else return (MOVES_K << (i - 27)) & ~WHITE_UNITS & ~FILE_A;
	}
}

//==============================================
// MovesBK
//==============================================
uint64_t Bitboard::MovesBK(uint64_t UNIT, uint8_t i)
{	
	if (UNIT == 0x0000000000000000UL) return 0x0000000000000000UL;
	if (i < 27){
		if ((i & 0x07) < 4) return (MOVES_K >> (27 - i)) & ~BLACK_UNITS & ~FILE_H;
		else return (MOVES_K >> (27 - i)) & ~BLACK_UNITS & ~FILE_A;
	} else {
		if ((i & 0x07) < 4) return (MOVES_K << (i - 27)) & ~BLACK_UNITS & ~FILE_H;
		else return (MOVES_K << (i - 27)) & ~BLACK_UNITS & ~FILE_A;
	}
}

//==============================================
// MovesWP
//==============================================
uint64_t Bitboard::MovesWP(uint64_t UNIT)
{	
	if (UNIT == 0x0000000000000000UL) return 0x0000000000000000UL;
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
	if (UNIT == 0x0000000000000000UL) return 0x0000000000000000UL;
	uint64_t PAWN_RIGHT = (UNIT >> 7) & WHITE_UNITS & ~FILE_A; 						// capture right
	uint64_t PAWN_LEFT = (UNIT >> 9) & WHITE_UNITS & ~FILE_H; 						// capture left
	uint64_t PAWN_FORWARD_1 = (UNIT >> 8) & EMPTY; 									// move forward 1
	uint64_t PAWN_FORWARD_2 = (UNIT >> 16) & EMPTY & (EMPTY >> 8) & RANK_5; 		// move forward 2
	uint64_t PAWN_RIGHT_EP = (UNIT >> 7) & (WP >> 8) & RANK_3 & ~FILE_A & FILE_EP; 	// en passant right
	uint64_t PAWN_LEFT_EP = (UNIT >> 9) & (WP >> 8) & RANK_3 & ~FILE_H & FILE_EP; 	// en passant left
	return PAWN_RIGHT | PAWN_LEFT | PAWN_FORWARD_1 | PAWN_FORWARD_2 | PAWN_RIGHT_EP | PAWN_LEFT_EP;
}

//==============================================
// MovesBP
//==============================================
uint64_t Bitboard::MovesW()
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
	// WR = 0xff;
	// std::cout << std::bitset<64>(WR) << std::endl;
	// std::cout << std::bitset<64>(this->WR) << std::endl;
	//while ()
	return MOVES;
}


//==============================================
// PossibleMovesWP()
//==============================================
// void Bitboard::PossibleMovesWP(uint8_t moves[256][4], uint8_t & m, uint8_t scoresheet[256][5], uint8_t N)
// {
// 	uint64_t FILE_EP = 0x0000000000000000UL;
// 	if ((N > 0) && (scoresheet[N - 1][0]%8 == scoresheet[N - 1][1]%8) && (scoresheet[N - 1][0]/8 == scoresheet[N - 1][1]/8 - 2)) FILE_EP = FILES[scoresheet[N - 1][1]%8];

// 	uint64_t PAWN_RIGHT = (WP << 9) & BLACK_UNITS & ~RANK_8 & ~FILE_A; 			// capture right
// 	uint64_t PAWN_LEFT = (WP << 7) & BLACK_UNITS & ~RANK_8 & ~FILE_H; 			// capture left
// 	uint64_t PAWN_FORWARD_1 = (WP << 8) & EMPTY & ~RANK_8; 						// move forward 1
// 	uint64_t PAWN_FORWARD_2 = (WP << 16) & EMPTY & (EMPTY << 8) & RANK_4; 		// move forward 2
// 	uint64_t PAWN_RIGHT_PROMOTION = (WP << 9) & BLACK_UNITS & RANK_8 & ~FILE_A; 	// capture right (with promotion)
// 	uint64_t PAWN_LEFT_PROMOTION = (WP << 7) & BLACK_UNITS & RANK_8 & ~FILE_H; 	// capture left (with promotion)
// 	uint64_t PAWN_FORWARD_PROMOTION = (WP << 8) & EMPTY & RANK_8; 				// move forward 1 (with promotion)
// 	uint64_t PAWN_RIGHT_EP = (WP << 9) & (BP << 8) & RANK_6 & ~FILE_A & FILE_EP; // en passant right
// 	uint64_t PAWN_LEFT_EP = (WP << 7) & (BP << 8) & RANK_6 & ~FILE_H & FILE_EP; // en passant left

// 	for (uint8_t i = 0; i < 64; i++){
// 		if (((PAWN_RIGHT >> i) & 1) != 0){				// capture right
// 			moves[m][0] = i - 9;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_PAWN;
// 			m++;
// 		}
// 		if (((PAWN_LEFT >> i) & 1) != 0){				// capture left
// 			moves[m][0] = i - 7;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_PAWN;
// 			m++;
// 		}
// 		if (((PAWN_FORWARD_1 >> i) & 1) != 0){			// move forward 1
// 			moves[m][0] = i - 8;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;	
// 			moves[m][3] = WHITE_PAWN;
// 			m++;
// 		}
// 		if (((PAWN_FORWARD_2 >> i) & 1) != 0){			// move forward 2
// 			moves[m][0] = i - 16;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_PAWN;
// 			m++;
// 		}
// 		if (((PAWN_RIGHT_PROMOTION >> i) & 1) != 0){		// capture right (with promotion)
// 			moves[m][0] = i - 9;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_QUEEN;
// 			m++;
// 			moves[m][0] = i - 9;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_KNIGHT;
// 			m++;	
// 			moves[m][0] = i - 9;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_ROOK;
// 			m++;	
// 			moves[m][0] = i - 9;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_BISHOP;
// 			m++;		
// 		}
// 		if (((PAWN_LEFT_PROMOTION >> i) & 1) != 0){			// capture left (with promotion)
// 			moves[m][0] = i - 7;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_QUEEN;
// 			m++;
// 			moves[m][0] = i - 7;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_KNIGHT;
// 			m++;	
// 			moves[m][0] = i - 7;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_ROOK;
// 			m++;	
// 			moves[m][0] = i - 7;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_BISHOP;
// 			m++;		
// 		}
// 		if (((PAWN_FORWARD_PROMOTION >> i) & 1) != 0){		// move forward 1 (with promotion)
// 			moves[m][0] = i - 8;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_QUEEN;
// 			m++;
// 			moves[m][0] = i - 8;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_KNIGHT;
// 			m++;	
// 			moves[m][0] = i - 8;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_ROOK;
// 			m++;	
// 			moves[m][0] = i - 8;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_BISHOP;
// 			m++;		
// 		}
// 		if (((PAWN_RIGHT_EP >> i) & 1) != 0){				// en passant right
// 			moves[m][0] = i - 9;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_PAWN;
// 			m++;
// 		}
// 		if (((PAWN_LEFT_EP >> i) & 1) != 0){				// en passant left
// 			moves[m][0] = i - 7;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_PAWN;
// 			moves[m][3] = WHITE_PAWN;
// 			m++;
// 		}
// 	}
// }

// //==============================================
// // PossibleMovesWN()
// //==============================================
// void Bitboard::PossibleMovesWN(uint8_t moves[256][4], uint8_t & m)
// {
// 	uint64_t KNIGHT_0 = (WN << 6) & ~WHITE_UNITS & ~FILE_G & ~FILE_H;
// 	uint64_t KNIGHT_1 = (WN << 15) & ~WHITE_UNITS & ~FILE_H;
// 	uint64_t KNIGHT_2 = (WN << 17) & ~WHITE_UNITS & ~FILE_A;
// 	uint64_t KNIGHT_3 = (WN << 10) & ~WHITE_UNITS & ~FILE_A & ~FILE_B;
// 	uint64_t KNIGHT_4 = (WN >> 6) & ~WHITE_UNITS & ~FILE_A & ~FILE_B;
// 	uint64_t KNIGHT_5 = (WN >> 15) & ~WHITE_UNITS & ~FILE_A;
// 	uint64_t KNIGHT_6 = (WN >> 17) & ~WHITE_UNITS & ~FILE_H;
// 	uint64_t KNIGHT_7 = (WN >> 10) & ~WHITE_UNITS & ~FILE_G & ~FILE_H;

// 	for (uint8_t i = 0; i < 64; i++){
// 		if (((KNIGHT_0 >> i) & 1) != 0){				// capture right
// 			moves[m][0] = i - 6;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_KNIGHT;
// 			moves[m][3] = WHITE_KNIGHT;
// 			m++;
// 		}
// 		if (((KNIGHT_1 >> i) & 1) != 0){				// capture right
// 			moves[m][0] = i - 15;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_KNIGHT;
// 			moves[m][3] = WHITE_KNIGHT;
// 			m++;
// 		}
// 		if (((KNIGHT_2 >> i) & 1) != 0){				// capture right
// 			moves[m][0] = i - 17;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_KNIGHT;
// 			moves[m][3] = WHITE_KNIGHT;
// 			m++;
// 		}
// 		if (((KNIGHT_3 >> i) & 1) != 0){				// capture right
// 			moves[m][0] = i - 10;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_KNIGHT;
// 			moves[m][3] = WHITE_KNIGHT;
// 			m++;
// 		}
// 		if (((KNIGHT_4 >> i) & 1) != 0){				// capture right
// 			moves[m][0] = i + 6;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_KNIGHT;
// 			moves[m][3] = WHITE_KNIGHT;
// 			m++;
// 		}
// 		if (((KNIGHT_5 >> i) & 1) != 0){				// capture right
// 			moves[m][0] = i + 15;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_KNIGHT;
// 			moves[m][3] = WHITE_KNIGHT;
// 			m++;
// 		}
// 		if (((KNIGHT_6 >> i) & 1) != 0){				// capture right
// 			moves[m][0] = i + 17;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_KNIGHT;
// 			moves[m][3] = WHITE_KNIGHT;
// 			m++;
// 		}
// 		if (((KNIGHT_7 >> i) & 1) != 0){				// capture right
// 			moves[m][0] = i + 10;
// 			moves[m][1] = i;
// 			moves[m][2] = WHITE_KNIGHT;
// 			moves[m][3] = WHITE_KNIGHT;
// 			m++;
// 		}
// 	}
// }




// //==============================================
// // PossibleMovesWR()
// //==============================================
// void Bitboard::PossibleMovesWR(uint8_t moves[256][4], uint8_t & m)
// {
// 	//std::cout << std::bitset<4>(Reverse(0b0010)) << std::endl;
// 	// uint64_t ROOK = WR & (~WR + 1);
// 	// int i = GetIndex(ROOK);
// 	// uint64_t RANK = RANKS[i/8];
// 	// uint64_t FILE = FILES[i%8];

// 	// //MASK = 
// 	// //uint64_t ROOK_HORIZONTAL = ((~EMPTY & FILE) ^ (~EMPTY - (ROOK << 1))) & ~WHITE_UNITS;
	
// 	// uint64_t ROOK_HORIZONTAL = (((~EMPTY & RANK) - (ROOK << 1)) ^ Reverse(Reverse(~EMPTY & RANK) - (Reverse(ROOK) << 1))) & RANK & ~WHITE_UNITS;
// 	// uint64_t ROOK_VERTICAL = (((~EMPTY & FILE) - (ROOK << 1)) ^ Reverse(Reverse(~EMPTY & FILE) - (Reverse(ROOK) << 1))) & FILE & ~WHITE_UNITS;
// 	// uint64_t ROOK_MOVES = ROOK_HORIZONTAL | ROOK_VERTICAL;

// 	// // PrintBitboard(ROOK);
// 	// // std::cout << std::endl;
// 	// PrintBitboard(ROOK_MOVES);

// 	// std::cout << std::endl;
// 	// PrintBitboard(~EMPTY);
	
	
// 	// for (uint8_t i = 0; i < 64; i++){
// 	// 	if (((ROOK_RIGHT >> i) & 1) != 0){				// capture right
// 	// 		moves[m][0] = i - 6;
// 	// 		moves[m][1] = i;
// 	// 		moves[m][2] = WHITE_KNIGHT;
// 	// 		moves[m][3] = WHITE_KNIGHT;
// 	// 		m++;
// 	// 	}
// 	// }
// }

