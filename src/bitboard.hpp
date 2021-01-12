#ifndef BITBOARD_H
#define BITBOARD_H

//==============================================
// include
//==============================================
#include <iostream>

//==============================================
// define
//==============================================
//#define PROMOTION_PIECES {'q', 'n', 'r', 'b'};
#define WHITE_ROOK 0b0000;
#define WHITE_KNIGHT 0b0001;
#define WHITE_BISHOP 0b0010;
#define WHITE_QUEEN 0b0011;
#define WHITE_KING 0b0100;
#define WHITE_PAWN 0b0101;
#define BLACK_ROOK 0b0110;
#define BLACK_KNIGHT 0b0111;
#define BLACK_BISHOP 0b1000;
#define BLACK_QUEEN 0b1001;
#define BLACK_KING 0b1010;
#define BLACK_PAWN 0b1011;


//==============================================
// Bitboard
//==============================================
class Bitboard
{
public:

	uint64_t WR;			// bitboard for the white rooks
	uint64_t WN; 			// bitboard for the white knights
	uint64_t WB; 			// bitboard for the white bishops
	uint64_t WQ; 			// bitboard for the white queens
	uint64_t WK; 			// bitboard for the white king
	uint64_t WP; 			// bitboard for the white pawns
	uint64_t BR; 			// bitboard for the black rooks
	uint64_t BN; 			// bitboard for the black knights
	uint64_t BB; 			// bitboard for the black bishops
	uint64_t BQ; 			// bitboard for the black queens
	uint64_t BK; 			// bitboard for the black king
	uint64_t BP;			// bitboard for the black pawns			
	uint64_t FILE_A; 		// bitboard for the a-file
	uint64_t FILE_B; 		// bitboard for the b-file
	uint64_t FILE_C;		// bitboard for the c-file
	uint64_t FILE_D; 		// bitboard for the d-file
	uint64_t FILE_E; 		// bitboard for the e-file
	uint64_t FILE_F; 		// bitboard for the f-file
	uint64_t FILE_G; 		// bitboard for the g-file
	uint64_t FILE_H;		// bitboard for the h-file
	uint64_t RANK_1; 		// bitboard for the 1st rank
	uint64_t RANK_2; 		// bitboard for the 2nd rank
	uint64_t RANK_3; 		// bitboard for the 3rd rank
	uint64_t RANK_4; 		// bitboard for the 4th rank
	uint64_t RANK_5; 		// bitboard for the 5th rank
	uint64_t RANK_6; 		// bitboard for the 6th rank
	uint64_t RANK_7; 		// bitboard for the 7th rank
	uint64_t RANK_8;		// bitboard for the 8th rank
	uint64_t WHITE_UNITS; 	// bitboard for all the white units (excluding the white king)
	uint64_t BLACK_UNITS; 	// bitboard for all the black units (excluding the black king)
	uint64_t EMPTY;		  	// bitboard for all the empty squares on the board
	uint8_t moves[256][4];	// array to store possible moves
	char turn;				// indicator for player's turn (0 for white, 1 for black)
	char scoresheet[256][4];// array to record game history
	uint64_t files[8];
public:
	Bitboard(char board[8][8]);									// bitboard constructor
	Bitboard();													// bitboard constructor
	void BoardToBitboard(char board[8][8]);
	void BitboardToBoard(char board[8][8]);
	void Print(char board[8][8]);
	void Print();
	void PrintMoves(uint8_t moves[256][4], uint8_t M);
	void PossibleMovesWP(uint8_t moves[256][4], uint8_t & m, uint8_t scoresheet[256][5], uint8_t N);
	
	
private:
};


#endif