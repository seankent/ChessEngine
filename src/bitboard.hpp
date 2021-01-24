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
#define WHITE_ROOK 0b0000
#define WHITE_KNIGHT 0b0001
#define WHITE_BISHOP 0b0010
#define WHITE_QUEEN 0b0011
#define WHITE_KING 0b0100
#define WHITE_PAWN 0b0101
#define BLACK_ROOK 0b0110
#define BLACK_KNIGHT 0b0111
#define BLACK_BISHOP 0b1000
#define BLACK_QUEEN 0b1001
#define BLACK_KING 0b1010
#define BLACK_PAWN 0b1011


//==============================================
// const
//==============================================


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
	uint64_t DIAGONAL_A8A8;	// bitboard for the a8-a8 diagonal
	uint64_t DIAGONAL_A7B8; // bitboard for the a7-b8 diagonal
	uint64_t DIAGONAL_A6C8;	// bitboard for the a6-c8 diagonal
	uint64_t DIAGONAL_A5D8;	// bitboard for the a5-d8 diagonal
	uint64_t DIAGONAL_A4E8;	// bitboard for the a4-e8 diagonal
	uint64_t DIAGONAL_A3F8;	// bitboard for the a3-f8 diagonal
	uint64_t DIAGONAL_A2G8;	// bitboard for the a2-g8 diagonal
	uint64_t DIAGONAL_A1H8;	// bitboard for the a1-h8 diagonal
	uint64_t DIAGONAL_B1H7;	// bitboard for the b1-h8 diagonal
	uint64_t DIAGONAL_C1H6;	// bitboard for the c1-h8 diagonal
	uint64_t DIAGONAL_D1H5;	// bitboard for the d1-h8 diagonal
	uint64_t DIAGONAL_E1H4;	// bitboard for the e1-h8 diagonal
	uint64_t DIAGONAL_F1H3;	// bitboard for the f1-h8 diagonal
	uint64_t DIAGONAL_G1H2;	// bitboard for the g1-h8 diagonal
	uint64_t DIAGONAL_H1H1;	// bitboard for the h1-h8 diagonal

	uint64_t DIAGONAL_A1A1;	// bitboard for the a1-a1 diagonal
	uint64_t DIAGONAL_A2B1; // bitboard for the a2-b1 diagonal
	uint64_t DIAGONAL_A3C1;	// bitboard for the a3-c1 diagonal
	uint64_t DIAGONAL_A4D1;	// bitboard for the a4-d1 diagonal
	uint64_t DIAGONAL_A5E1;	// bitboard for the a5-e1 diagonal
	uint64_t DIAGONAL_A6F1;	// bitboard for the a6-f1 diagonal
	uint64_t DIAGONAL_A7G1;	// bitboard for the a7-g1 diagonal
	uint64_t DIAGONAL_A8H1;	// bitboard for the a8-h1 diagonal
	uint64_t DIAGONAL_B8H2;	// bitboard for the b8-h2 diagonal
	uint64_t DIAGONAL_C8H3;	// bitboard for the c8-h3 diagonal
	uint64_t DIAGONAL_D8H4;	// bitboard for the d8-h4 diagonal
	uint64_t DIAGONAL_E8H5;	// bitboard for the e8-h5 diagonal
	uint64_t DIAGONAL_F8H6;	// bitboard for the f8-h6 diagonal
	uint64_t DIAGONAL_G8H7;	// bitboard for the g8-h7 diagonal
	uint64_t DIAGONAL_H8H8;	// bitboard for the h8-h8 diagonal
	uint64_t FILES[8];
	uint64_t RANKS[8];
	uint64_t DIAGONALS_UP[15];
	uint64_t DIAGONALS_DOWN[15];
	uint64_t WHITE_UNITS; 	// bitboard for all the white units
	uint64_t BLACK_UNITS; 	// bitboard for all the black units
	uint64_t EMPTY;		  	// bitboard for all the empty squares on the board
	uint64_t FILE_EP;		// bitboard for en passant file
	uint8_t moves[256][4];	// array to store possible moves
	char turn;				// indicator for player's turn (0 for white, 1 for black)
	char scoresheet[256][4];// array to record game history
	

	uint64_t MOVES_N;
	uint64_t MOVES_K;
public:
	Bitboard(char board[8][8]);									// bitboard constructor
	Bitboard();													// bitboard constructor
	//void LS1B(uint64_t UNIT, uint64_t LS1, uint8_t i);
	void LS1B(uint64_t U64, uint64_t & LS1B, uint8_t & i);
	uint64_t Reverse(uint64_t U64);
	void BoardToBitboard(char board[8][8]);
	void BitboardToBoard(char board[8][8]);
	void Print(char board[8][8]);
	void Print();

	uint64_t MovesWN(uint64_t UNIT, uint8_t i);
	uint64_t MovesBN(uint64_t UNIT, uint8_t i);
	uint64_t MovesWR(uint64_t UNIT, uint8_t i);
	uint64_t MovesBR(uint64_t UNIT, uint8_t i);
	uint64_t MovesWB(uint64_t UNIT, uint8_t i);
	uint64_t MovesBB(uint64_t UNIT, uint8_t i);
	uint64_t MovesWQ(uint64_t UNIT, uint8_t i);
	uint64_t MovesBQ(uint64_t UNIT, uint8_t i);
	uint64_t MovesWK(uint64_t UNIT, uint8_t i);
	uint64_t MovesBK(uint64_t UNIT, uint8_t i);
	uint64_t MovesWP(uint64_t UNIT);
	uint64_t MovesBP(uint64_t UNIT);
	uint64_t MovesW();
	uint64_t MovesB();

	void PrintBitboard(uint64_t U64);
	void PrintMoves(uint64_t MOVES);
	// void PossibleMovesWP(uint8_t moves[256][4], uint8_t & m, uint8_t scoresheet[256][5], uint8_t N);
	// void PossibleMovesWN(uint8_t moves[256][4], uint8_t & m);
	// void PossibleMovesWR(uint8_t moves[256][4], uint8_t & m);
	// int GetIndex(uint64_t x);
	
	
	
private:
};


#endif