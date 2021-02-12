#ifndef BITBOARD_HPP
#define BITBOARD_HPP

//==============================================
// include
//==============================================
#include <iostream>
#include <iomanip>

//==============================================
// define
//==============================================
#define WHITE false
#define BLACK true
#define FILE_A 0x0101010101010101UL 		// bitboard for the a-file
#define FILE_B 0x0202020202020202UL 		// bitboard for the b-file
#define FILE_C 0x0404040404040404UL			// bitboard for the c-file
#define FILE_D 0x0808080808080808UL			// bitboard for the d-file
#define FILE_E 0x1010101010101010UL 		// bitboard for the e-file
#define FILE_F 0x2020202020202020UL 		// bitboard for the f-file
#define FILE_G 0x4040404040404040UL 		// bitboard for the g-file
#define FILE_H 0x8080808080808080UL			// bitboard for the h-file
#define RANK_1 0x00000000000000ffUL 		// bitboard for the 1st rank
#define RANK_2 0x000000000000ff00UL 		// bitboard for the 2nd rank
#define RANK_3 0x0000000000ff0000UL 		// bitboard for the 3rd rank
#define RANK_4 0x00000000ff000000UL 		// bitboard for the 4th rank
#define RANK_5 0x000000ff00000000UL 		// bitboard for the 5th rank
#define RANK_6 0x0000ff0000000000UL 		// bitboard for the 6th rank
#define RANK_7 0x00ff000000000000UL 		// bitboard for the 7th rank
#define RANK_8 0xff00000000000000UL			// bitboard for the 8th rank
#define DIAGONAL_A8A8 0x0100000000000000UL	// bitboard for the a8-a8 diagonal
#define DIAGONAL_A7B8 0x0201000000000000UL 	// bitboard for the a7-b8 diagonal
#define DIAGONAL_A6C8 0x0402010000000000UL	// bitboard for the a6-c8 diagonal
#define DIAGONAL_A5D8 0x0804020100000000UL	// bitboard for the a5-d8 diagonal
#define DIAGONAL_A4E8 0x1008040201000000UL	// bitboard for the a4-e8 diagonal
#define DIAGONAL_A3F8 0x2010080402010000UL	// bitboard for the a3-f8 diagonal
#define DIAGONAL_A2G8 0x4020100804020100UL	// bitboard for the a2-g8 diagonal
#define DIAGONAL_A1H8 0x8040201008040201UL	// bitboard for the a1-h8 diagonal
#define DIAGONAL_B1H7 0x0080402010080402UL	// bitboard for the b1-h8 diagonal
#define DIAGONAL_C1H6 0x0000804020100804UL	// bitboard for the c1-h8 diagonal
#define DIAGONAL_D1H5 0x0000008040201008UL	// bitboard for the d1-h8 diagonal
#define DIAGONAL_E1H4 0x0000000080402010UL	// bitboard for the e1-h8 diagonal
#define DIAGONAL_F1H3 0x0000000000804020UL	// bitboard for the f1-h8 diagonal
#define DIAGONAL_G1H2 0x0000000000008040UL	// bitboard for the g1-h8 diagonal
#define DIAGONAL_H1H1 0x0000000000000080UL	// bitboard for the h1-h8 diagonal
#define DIAGONAL_A1A1 0x0000000000000001UL	// bitboard for the a1-a1 diagonal
#define DIAGONAL_A2B1 0x0000000000000102UL 	// bitboard for the a2-b1 diagonal
#define DIAGONAL_A3C1 0x0000000000010204UL	// bitboard for the a3-c1 diagonal
#define DIAGONAL_A4D1 0x0000000001020408UL	// bitboard for the a4-d1 diagonal
#define DIAGONAL_A5E1 0x0000000102040810UL	// bitboard for the a5-e1 diagonal
#define DIAGONAL_A6F1 0x0000010204081020UL	// bitboard for the a6-f1 diagonal
#define DIAGONAL_A7G1 0x0001020408102040UL	// bitboard for the a7-g1 diagonal
#define DIAGONAL_A8H1 0x0102040810204080UL	// bitboard for the a8-h1 diagonal
#define DIAGONAL_B8H2 0x0204081020408000UL	// bitboard for the b8-h2 diagonal
#define DIAGONAL_C8H3 0x0408102040800000UL	// bitboard for the c8-h3 diagonal
#define DIAGONAL_D8H4 0x0810204080000000UL	// bitboard for the d8-h4 diagonal
#define DIAGONAL_E8H5 0x1020408000000000UL	// bitboard for the e8-h5 diagonal
#define DIAGONAL_F8H6 0x2040800000000000UL	// bitboard for the f8-h6 diagonal
#define DIAGONAL_G8H7 0x4080000000000000UL	// bitboard for the g8-h7 diagonal
#define DIAGONAL_H8H8 0x8000000000000000UL	// bitboard for the h8-h8 diagonal


//==============================================
// enum
//==============================================
enum
{
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING,
	PAWN
};

//==============================================
// const
//==============================================
const uint64_t FILES[] = {FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H};
const uint64_t RANKS[] = {RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8};
const uint64_t DIAGONALS_UP[] = {DIAGONAL_A8A8, DIAGONAL_A7B8, DIAGONAL_A6C8, DIAGONAL_A5D8, DIAGONAL_A4E8, DIAGONAL_A3F8, DIAGONAL_A2G8, DIAGONAL_A1H8, DIAGONAL_B1H7, DIAGONAL_C1H6, DIAGONAL_D1H5, DIAGONAL_E1H4, DIAGONAL_F1H3, DIAGONAL_G1H2, DIAGONAL_H1H1};
const uint64_t DIAGONALS_DOWN[] = {DIAGONAL_A1A1, DIAGONAL_A2B1, DIAGONAL_A3C1, DIAGONAL_A4D1, DIAGONAL_A5E1, DIAGONAL_A6F1, DIAGONAL_A7G1, DIAGONAL_A8H1, DIAGONAL_B8H2, DIAGONAL_C8H3, DIAGONAL_D8H4, DIAGONAL_E8H5, DIAGONAL_F8H6, DIAGONAL_G8H7, DIAGONAL_H8H8};


//==============================================
// Bitboard
//==============================================
class Bitboard
{
public:
	uint64_t WR;				// bitboard for the white rooks
	uint64_t WN; 				// bitboard for the white knights
	uint64_t WB; 				// bitboard for the white bishops
	uint64_t WQ; 				// bitboard for the white queens
	uint64_t WK; 				// bitboard for the white king
	uint64_t WP; 				// bitboard for the white pawns
	uint64_t BR; 				// bitboard for the black rooks
	uint64_t BN; 				// bitboard for the black knights
	uint64_t BB; 				// bitboard for the black bishops
	uint64_t BQ; 				// bitboard for the black queens
	uint64_t BK; 				// bitboard for the black king
	uint64_t BP;				// bitboard for the black pawns			
	uint64_t WHITE_UNITS; 		// bitboard for all the white units
	uint64_t BLACK_UNITS; 		// bitboard for all the black units
	uint64_t EMPTY;		  		// bitboard for all the empty squares on the board (bits are set if the square is empty)
	uint64_t WHITE_ATTACKS; 	// bitboard for all the squares white is attacking
	uint64_t BLACK_ATTACKS;		// bitboard for all the squares black is attacking
	uint64_t FILE_EP;			// bitboard for the en passant file
public:
	bool turn;					// WHITE or BLACK
	bool wkc, wqc, bkc, bqc;	// these variables keep track of castling rights
	bool wc, bc;				// these variables indicate if white or black is in check

public:
	Bitboard(char board[8][8], bool turn);		// Bitboard constructor
	Bitboard();									// Bitboard constructor
	void BoardToBitboard(char board[8][8]);
	void BitboardToBoard(char board[8][8]);
	void Update();
	uint64_t LS1B(uint64_t U64, uint8_t & i);
	uint64_t Reverse(uint64_t U64);
	void Print(char board[8][8]);
	void Print();
	void PrintBitboard(uint64_t U64);
	void PrintMoves(uint64_t MOVES);
	uint64_t MovesWN(uint64_t UNIT);
	uint64_t MovesBN(uint64_t UNIT);
	uint64_t MovesWR(uint64_t UNIT, uint8_t i);
	uint64_t MovesBR(uint64_t UNIT, uint8_t i);
	uint64_t MovesWB(uint64_t UNIT, uint8_t i);
	uint64_t MovesBB(uint64_t UNIT, uint8_t i);
	uint64_t MovesWQ(uint64_t UNIT, uint8_t i);
	uint64_t MovesBQ(uint64_t UNIT, uint8_t i);
	uint64_t MovesWK(uint64_t UNIT);
	uint64_t MovesBK(uint64_t UNIT);
	uint64_t MovesWP(uint64_t UNIT);
	uint64_t MovesBP(uint64_t UNIT);
	uint64_t AttacksW();
	uint64_t AttacksB();
	void Move(uint64_t UNIT0, uint64_t UNIT1, uint8_t id0, uint8_t id1);
	// bool Move(uint64_t UNIT0, uint64_t UNIT1, uint8_t peice);
	// void Undo();
};

#endif