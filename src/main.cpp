#include <iostream>
#include <vector>

// unsigned long int x = 1;


// //==============================================
// // define
// //==============================================
// #define FILE_A 0x0101010101010101UL
// #define FILE_B 0x0202020202020202UL
// #define FILE_C 0x0404040404040404UL
// #define FILE_D 0x0808080808080808UL
// #define FILE_E 0x1010101010101010UL
// #define FILE_F 0x2020202020202020UL
// #define FILE_G 0x4040404040404040UL
// #define FILE_H 0x8080808080808080UL

//==============================================
// global const
//==============================================
const char start_board[8][8] = {
	{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
	{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
	{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
};

const char empty_board[8][8] = {
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
	{'-', '-', '-', '-', '-', '-', '-', '-'},
};



//==============================================
// Bitboard
//==============================================
class Bitboards
{
public:

	uint64_t WR, WN, WB, WQ, WK, WP, BR, BN, BB, BQ, BK, BP;
	uint64_t FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H;
	uint64_t RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8;
	uint64_t WHITE_UNITS, BLACK_UNITS, EMPTY;
public:
	Bitboards();
	Bitboards(char board[8][8]);
	void BoardToBitboards(char board[8][8]);
	void BitboardsToBoard(char board[8][8]);
	void PossibleMovesWP(uint8_t moves[256][5], uint8_t & n);
	void PrintMoves(uint8_t moves[256][5], uint8_t N);
	void PrintBoard(char board[8][8]);
	void Print();
private:
};

//==============================================
// PossibleMovesWP()
//==============================================
void Bitboards::PossibleMovesWP(uint8_t moves[256][5], uint8_t & n)
{
	uint64_t PAWN_MOVES;
	PAWN_MOVES = (WP >> 7) & BLACK_UNITS & ~RANK_8 & ~FILE_A; // capture right
	for (int i = 0; i < 64; i++){
		if (((PAWN_MOVES >> i) & 1) == 1){
			moves[n][2] = i/8;
			moves[n][3] = i%8;
			moves[n][0] = moves[n][2] + 1;
			moves[n][1] = moves[n][2] - 1;
			n++;		
		}
	}
	PAWN_MOVES = (WP >> 9) & BLACK_UNITS & ~RANK_8 & ~FILE_H; // capture left
	for (int i = 0; i < 64; i++){
		if (((PAWN_MOVES >> i) & 1) == 1){
			moves[n][2] = i/8;
			moves[n][3] = i%8;
			moves[n][0] = moves[n][2] + 1;
			moves[n][1] = moves[n][2] + 1;
			n++;		
		}
	}
	PAWN_MOVES = (WP >> 8) & EMPTY & ~RANK_8; // move forward 1
	for (int i = 0; i < 64; i++){
		if (((PAWN_MOVES >> i) & 1) == 1){
			moves[n][2] = i/8;
			moves[n][3] = i%8;
			moves[n][0] = moves[n][2] + 1;
			moves[n][1] = moves[n][2];
			n++;		
		}
	}
	PAWN_MOVES = (WP >> 16) & EMPTY & (EMPTY >> 8) & RANK_4; // move forward 2
	for (int i = 0; i < 64; i++){
		if (((PAWN_MOVES >> i) & 1) == 1){
			moves[n][2] = i/8;
			moves[n][3] = i%8;
			moves[n][0] = moves[n][2] + 2;
			moves[n][1] = moves[n][2];
			n++;		
		}
	}
	PAWN_MOVES = (WP >> 16) & EMPTY & (EMPTY >> 8) & RANK_4; // move forward 2
	for (int i = 0; i < 64; i++){
		if (((PAWN_MOVES >> i) & 1) == 1){
			moves[n][2] = i/8;
			moves[n][3] = i%8;
			moves[n][0] = moves[n][2] + 2;
			moves[n][1] = moves[n][2];
			n++;		
		}
	}
	// Promotions
	char promotion_pieces[] = {'q', 'n', 'r', 'b'};
	PAWN_MOVES = (WP >> 7) & BLACK_UNITS & RANK_8 & ~FILE_A; // capture right
	for (int i = 0; i < 64; i++){
		if (((PAWN_MOVES >> i) & 1) == 1){
			for (int j = 0; j < 4; j++){
				moves[n][2] = i/8;
				moves[n][3] = i%8;
				moves[n][0] = moves[n][2] + 1;
				moves[n][1] = moves[n][2] - 1;
				moves[n][4] = promotion_pieces[j];
				n++;	
			}
		}
	}
	PAWN_MOVES = (WP >> 9) & BLACK_UNITS & RANK_8 & ~FILE_H; // capture left
	for (int i = 0; i < 64; i++){
		if (((PAWN_MOVES >> i) & 1) == 1){
			for (int j = 0; j < 4; j++){
				moves[n][2] = i/8;
				moves[n][3] = i%8;
				moves[n][0] = moves[n][2] + 1;
				moves[n][1] = moves[n][2] - 1;
				moves[n][4] = promotion_pieces[j];
				n++;	
			}
		}
	}
	PAWN_MOVES = (WP >> 8) & EMPTY & RANK_8; // move forward 1
	for (int i = 0; i < 64; i++){
		if (((PAWN_MOVES >> i) & 1) == 1){
			for (int j = 0; j < 4; j++){
				moves[n][2] = i/8;
				moves[n][3] = i%8;
				moves[n][0] = moves[n][2] + 1;
				moves[n][1] = moves[n][2] - 1;
				moves[n][4] = promotion_pieces[j];
				n++;	
			}
		}
	}
}

//==============================================
// Bitboard
//==============================================
Bitboards::Bitboards(char board[8][8])
{
	BoardToBitboards(board);	
	FILE_A = 0x0101010101010101UL;
	FILE_B = 0x0202020202020202UL;
	FILE_C = 0x0404040404040404UL;
	FILE_D = 0x0808080808080808UL;
	FILE_E = 0x1010101010101010UL;
	FILE_F = 0x2020202020202020UL;
	FILE_G = 0x4040404040404040UL;
	FILE_H = 0x8080808080808080UL;
	RANK_1 = 0xff00000000000000UL;
	RANK_2 = 0x00ff000000000000UL;
	RANK_3 = 0x0000ff0000000000UL;
	RANK_4 = 0x000000ff00000000UL;
	RANK_5 = 0x00000000ff000000UL;
	RANK_6 = 0x0000000000ff0000UL;
	RANK_7 = 0x000000000000ff00UL;
	RANK_8 = 0x00000000000000ffUL;
	WHITE_UNITS = WR | WN | WB | WQ | WP;
	BLACK_UNITS = BR | BN | BB | BQ | BP;
	EMPTY = ~(WHITE_UNITS | BLACK_UNITS | WK | BK);
}

//==============================================
// Bitboard
//==============================================
Bitboards::Bitboards()
{
	char board[8][8] = {
		{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
		{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
	};
	BoardToBitboards(board);
	FILE_A = 0x0101010101010101UL;
	FILE_B = 0x0202020202020202UL;
	FILE_C = 0x0404040404040404UL;
	FILE_D = 0x0808080808080808UL;
	FILE_E = 0x1010101010101010UL;
	FILE_F = 0x2020202020202020UL;
	FILE_G = 0x4040404040404040UL;
	FILE_H = 0x8080808080808080UL;	
	RANK_1 = 0xff00000000000000UL;
	RANK_2 = 0x00ff000000000000UL;
	RANK_3 = 0x0000ff0000000000UL;
	RANK_4 = 0x000000ff00000000UL;
	RANK_5 = 0x00000000ff000000UL;
	RANK_6 = 0x0000000000ff0000UL;
	RANK_7 = 0x000000000000ff00UL;
	RANK_8 = 0x00000000000000ffUL;	
	WHITE_UNITS = WR | WN | WB | WQ | WP;
	BLACK_UNITS = BR | BN | BB | BQ | BP;
	EMPTY = ~(WHITE_UNITS | BLACK_UNITS | WK | BK);	
}

//==============================================
// BoardToBitboards
//==============================================
void Bitboards::BoardToBitboards(char board[8][8])
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
		switch (board[i/8][i%8]){
			case 'r':
				WR += 0x0000000000000001UL << i;
				break;
			case 'n':
				WN += 0x0000000000000001UL << i;
				break;
			case 'b':
				WB += 0x0000000000000001UL << i;
				break;
			case 'q':
				WQ += 0x0000000000000001UL << i;
				break;
			case 'k':
				WK += 0x0000000000000001UL << i;
				break;
			case 'p':
				WP += 0x0000000000000001UL << i;
				break;
			case 'R':
				BR += 0x0000000000000001UL << i;
				break;
			case 'N':
				BN += 0x0000000000000001UL << i;
				break;
			case 'B':
				BB += 0x0000000000000001UL << i;
				break;
			case 'Q':
				BQ += 0x0000000000000001UL << i;
				break;
			case 'K':
				BK += 0x0000000000000001UL << i;
				break;
			case 'P':
				BP += 0x0000000000000001UL << i;
				break;
			default:
				break;
		}
	}
}

//==============================================
// Print()
//==============================================
void Bitboards::Print()
{
	char board[8][8];
	BitboardsToBoard(board);
	PrintBoard(board);
}

//==============================================
// PrintBoard()
//==============================================
void Bitboards::PrintBoard(char board[8][8])
{
	for (int i = 0; i < 8; i++){
		if (i != 0) std::cout << std::endl;
		for (int j = 0; j < 8; j++){
			std::cout << board[i][j];
			if (j != 7) std::cout << ' ';
		}
	}
	std::cout << std::endl;
}

//==============================================
// BitboardsToBoard
//==============================================
void Bitboards::BitboardsToBoard(char board[8][8])
{
	for (int i = 0; i < 64; i++)
	{
		board[i/8][i%8] = '-';
		if (((WR >> i) & 1) == 1)board[i/8][i%8] = 'r';
		if (((WN >> i) & 1) == 1) board[i/8][i%8] = 'n';
		if (((WB >> i) & 1) == 1) board[i/8][i%8] = 'b';
		if (((WQ >> i) & 1) == 1) board[i/8][i%8] = 'q';
		if (((WK >> i) & 1) == 1) board[i/8][i%8] = 'k';
		if (((WP >> i) & 1) == 1) board[i/8][i%8] = 'p';
		if (((BR >> i) & 1) == 1) board[i/8][i%8] = 'R';
		if (((BN >> i) & 1) == 1) board[i/8][i%8] = 'N';
		if (((BB >> i) & 1) == 1) board[i/8][i%8] = 'B';
		if (((BQ >> i) & 1) == 1) board[i/8][i%8] = 'Q';
		if (((BK >> i) & 1) == 1) board[i/8][i%8] = 'K';
		if (((BP >> i) & 1) == 1) board[i/8][i%8] = 'P';
	}
}


//==============================================
// PrintMoves
//==============================================
void Bitboards::PrintMoves(uint8_t moves[256][5], uint8_t N)
{
	char board[8][8];
	BitboardsToBoard(board);
	for (uint8_t n = 0; n < N; n++){
		board[moves[n][2]][moves[n][3]] = '+';
	}
	PrintBoard(board);
}

//==============================================
// Test_Bitboards_PossibleMovesWP_0
//==============================================
void Test_Bitboards_PossibleMovesWP_0()
{
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'p', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboards bitboards(board);
	uint8_t moves[256][5] = {0}; 
	uint8_t n = 0;
	bitboards.PossibleMovesWP(moves, n);
	bitboards.PrintMoves(moves, n);
}

//==============================================
// Test_Bitboards_PossibleMovesWP_1
//==============================================
void Test_Bitboards_PossibleMovesWP_1()
{
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', 'P', '-', '-', '-', '-', '-', '-'},
		{'p', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboards bitboards(board);
	uint8_t moves[256][5] = {0}; 
	uint8_t n = 0;
	bitboards.PossibleMovesWP(moves, n);
	bitboards.PrintMoves(moves, n);
}

//==============================================
// Test_Bitboards_PossibleMovesWP_2
//==============================================
void Test_Bitboards_PossibleMovesWP_2()
{
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', 'p'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboards bitboards(board);
	uint8_t moves[256][5] = {0}; 
	uint8_t n = 0;
	bitboards.PossibleMovesWP(moves, n);
	bitboards.PrintMoves(moves, n);
}

//==============================================
// Test_Bitboards_PossibleMovesWP_3
//==============================================
void Test_Bitboards_PossibleMovesWP_3()
{
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', 'p', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboards bitboards(board);
	uint8_t moves[256][5] = {0}; 
	uint8_t n = 0;
	bitboards.PossibleMovesWP(moves, n);
	bitboards.PrintMoves(moves, n);
}

//==============================================
// Test_Bitboards_PossibleMovesWP_4
//==============================================
void Test_Bitboards_PossibleMovesWP_4()
{
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', 'P', '-', '-'},
		{'-', '-', '-', '-', '-', 'p', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboards bitboards(board);
	uint8_t moves[256][5] = {0}; 
	uint8_t n = 0;
	bitboards.PossibleMovesWP(moves, n);
	bitboards.PrintMoves(moves, n);
}

//==============================================
// Test_Bitboards_PossibleMovesWP_5
//==============================================
void Test_Bitboards_PossibleMovesWP_5()
{
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', 'N', 'P', 'Q', '-'},
		{'-', '-', '-', '-', '-', 'p', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboards bitboards(board);
	uint8_t moves[256][5] = {0}; 
	uint8_t n = 0;
	bitboards.PossibleMovesWP(moves, n);
	bitboards.PrintMoves(moves, n);
}

//==============================================
// Test_Bitboards_PossibleMovesWP_6
//==============================================
void Test_Bitboards_PossibleMovesWP_6()
{
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', 'N', 'P', 'Q', '-'},
		{'-', '-', '-', '-', '-', 'p', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboards bitboards(board);
	uint8_t moves[256][5] = {0}; 
	uint8_t n = 0;
	bitboards.PossibleMovesWP(moves, n);
	bitboards.PrintMoves(moves, n);
}

//==============================================
// Test_Bitboards_PossibleMovesWP_7
//==============================================
void Test_Bitboards_PossibleMovesWP_7()
{
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', 'n', 'P', 'b', '-'},
		{'-', '-', '-', '-', '-', 'p', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboards bitboards(board);
	uint8_t moves[256][5] = {0}; 
	uint8_t n = 0;
	bitboards.PossibleMovesWP(moves, n);
	bitboards.PrintMoves(moves, n);
}

//==============================================
// Test_Bitboards_PossibleMovesWP_8
//==============================================
void Test_Bitboards_PossibleMovesWP_8()
{
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', 'p', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboards bitboards(board);
	uint8_t moves[256][5] = {0}; 
	uint8_t n = 0;
	bitboards.PossibleMovesWP(moves, n);
	bitboards.PrintMoves(moves, n);
}

//==============================================
// Test_Bitboards_PossibleMovesWP_9
//==============================================
void Test_Bitboards_PossibleMovesWP_9()
{
	char board[8][8] = {
		{'-', '-', 'K', '-', '-', '-', '-', '-'},
		{'-', '-', '-', 'p', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboards bitboards(board);
	uint8_t moves[256][5] = {0}; 
	uint8_t n = 0;
	bitboards.PossibleMovesWP(moves, n);
	bitboards.PrintMoves(moves, n);
}

//==============================================
// Test_Bitboards_PossibleMovesWP_10
//==============================================
void Test_Bitboards_PossibleMovesWP_10()
{
	char board[8][8] = {
		{'-', '-', 'B', '-', '-', '-', '-', '-'},
		{'-', '-', '-', 'p', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboards bitboards(board);
	uint8_t moves[256][5] = {0}; 
	uint8_t n = 0;
	bitboards.PossibleMovesWP(moves, n);
	bitboards.PrintMoves(moves, n);
}

//==============================================
// Test_Bitboards_PossibleMovesWP
//==============================================
void Test_Bitboards_PossibleMovesWP()
{
	std::cout << "Test 0." << std::endl;
	Test_Bitboards_PossibleMovesWP_0();
	std::cout << "Test 1." << std::endl;
	Test_Bitboards_PossibleMovesWP_1();
	std::cout << "Test 2." << std::endl;
	Test_Bitboards_PossibleMovesWP_2();
	std::cout << "Test 3." << std::endl;
	Test_Bitboards_PossibleMovesWP_3();
	std::cout << "Test 4." << std::endl;
	Test_Bitboards_PossibleMovesWP_4();
	std::cout << "Test 5." << std::endl;
	Test_Bitboards_PossibleMovesWP_5();
	std::cout << "Test 6." << std::endl;
	Test_Bitboards_PossibleMovesWP_6();
	std::cout << "Test 7." << std::endl;
	Test_Bitboards_PossibleMovesWP_7();
	std::cout << "Test 8." << std::endl;
	Test_Bitboards_PossibleMovesWP_8();
	std::cout << "Test 9." << std::endl;
	Test_Bitboards_PossibleMovesWP_9();
	std::cout << "Test 10." << std::endl;
	Test_Bitboards_PossibleMovesWP_10();

}



// //==============================================
// // possibleMoves
// //==============================================
// void possibleMoves(unsigned long int * bitboards)
// {
// 	WR = bitboards[0]
// 	WN = bitboards[1]
// 	WB = bitboards[2]
// 	WQ = bitboards[3]
// 	WK = bitboards[4]
// 	WP = bitboards[5]
// 	BR = bitboards[6]
// 	BN = bitboards[7]
// 	BB = bitboards[8]
// 	BQ = bitboards[9]
// 	BK = bitboards[10]
// 	BP = bitboards[11]
// 	unsigned long int black_units = BR | BN | BB | BQ | BP;
// 	unsigned long int white_units = BR | BN | BB | BQ | BP;
// }

//==============================================
// main
//==============================================
int main(void)
{
	//Bitboards bitboards;
	//bitboards.BP = bitboards.RANK_1;
	//bitboards.Print();
	Test_Bitboards_PossibleMovesWP();

	return 0;
}

