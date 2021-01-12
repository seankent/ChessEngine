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
	files[0] = FILE_A;
	files[1] = FILE_B;
	files[2] = FILE_C;
	files[3] = FILE_D;
	files[4] = FILE_E;
	files[5] = FILE_F;
	files[6] = FILE_G;
}

//==============================================
// Bitboard
//==============================================
Bitboard::Bitboard()
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
	BoardToBitboard(board);
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
	files[0] = FILE_A;
	files[1] = FILE_B;
	files[2] = FILE_C;
	files[3] = FILE_D;
	files[4] = FILE_E;
	files[5] = FILE_F;
	files[6] = FILE_G;
	files[7] = FILE_H;
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
// BitboardToBoard
//==============================================
void Bitboard::BitboardToBoard(char board[8][8])
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
// PrintBoard
//==============================================
void Bitboard::Print(char board[8][8])
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
void Bitboard::PrintMoves(uint8_t moves[256][4], uint8_t M)
{
	char board[8][8];
 	char boardMoves[8][8];
 	BitboardToBoard(board);
 	BitboardToBoard(boardMoves);

	for (uint8_t m = 0; m < M; m++){
		boardMoves[moves[m][1]/8][moves[m][1]%8] = '+';
	}

	for (int i = 0; i < 8; i++){
		if (i != 0) std::cout << std::endl;
		for (int j = 0; j < 16; j++){
			if (j < 8) std::cout << board[i][j];
			else std::cout << boardMoves[i][j - 8];
			if (j == 7) std::cout << "    ";
			else if (j != 15) std::cout << ' ';
		}
	}
	std::cout << std::endl;
}

//==============================================
// PossibleMovesWP()
//==============================================
void Bitboard::PossibleMovesWP(uint8_t moves[256][4], uint8_t & m, uint8_t scoresheet[256][5], uint8_t N)
{
	uint64_t EP_FILE = 0x0000000000000000UL;
	if ((N > 0) && (scoresheet[N - 1][0]%8 == scoresheet[N - 1][1]%8) && (scoresheet[N - 1][0]/8 == scoresheet[N - 1][1]/8 - 2)) EP_FILE = files[scoresheet[N - 1][1]%8];
	
	// 	PAWN_MOVES = (WP << 1) & BP & RANK_5 & ~FILE_A & EP_FILE;
	// 	if (PAWN_MOVES != 0){
	// 		moves[n][2] = 2;
	// 		moves[n][3] = scoresheet[L - 1][3];
	// 		moves[n][0] = 3;
	// 		moves[n][1] = moves[n][3] - 1;
	// 		moves[n][4] = 'e';
	// 		n++;
	// 	}

	// 	PAWN_MOVES = (WP >> 1) & BP & RANK_5 & ~FILE_H & EP_FILE;
	// 	// std::cout << PAWN_MOVES << std::endl;
	// 	// std::cout << std::bitset<64>(WP) << std::endl;
	// 	// std::cout << std::bitset<64>(BP) << std::endl;
	// 	if (PAWN_MOVES != 0){
	// 		moves[n][2] = 2;
	// 		moves[n][3] = scoresheet[L - 1][3];
	// 		moves[n][0] = 3;
	// 		moves[n][1] = moves[n][3] + 1;
	// 		moves[n][4] = 'e';
	// 		n++;
	// 	}
	// } 

	uint64_t PAWN_RIGHT = (WP >> 7) & BLACK_UNITS & ~RANK_8 & ~FILE_A; 			// capture right
	uint64_t PAWN_LEFT = (WP >> 9) & BLACK_UNITS & ~RANK_8 & ~FILE_H; 			// capture left
	uint64_t PAWN_FORWARD_1 = (WP >> 8) & EMPTY & ~RANK_8; 						// move forward 1
	uint64_t PAWN_FORWARD_2 = (WP >> 16) & EMPTY & (EMPTY >> 8) & RANK_4; 		// move forward 2
	uint64_t PAWN_RIGHT_PROMOTION = (WP >> 7) & BLACK_UNITS & RANK_8 & ~FILE_A; 	// capture right (with promotion)
	uint64_t PAWN_LEFT_PROMOTION = (WP >> 9) & BLACK_UNITS & RANK_8 & ~FILE_H; 	// capture left (with promotion)
	uint64_t PAWN_FORWARD_PROMOTION = (WP >> 8) & EMPTY & RANK_8; 				// move forward 1 (with promotion)
	uint64_t PAWN_RIGHT_EP = (WP >> 7) & (BP >> 8) & RANK_6 & ~FILE_A & EP_FILE; // en passant right
	uint64_t PAWN_LEFT_EP = (WP >> 9) & (BP >> 8) & RANK_6 & ~FILE_H & EP_FILE; // en passant left

	for (uint8_t i = 0; i < 64; i++){
		if (((PAWN_RIGHT >> i) & 1) != 0){				// capture right
			moves[m][0] = i - 7;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_PAWN;;
			m++;
		}
		if (((PAWN_LEFT >> i) & 1) != 0){				// capture left
			moves[m][0] = i - 9;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_PAWN;;
			m++;
		}
		if (((PAWN_FORWARD_1 >> i) & 1) != 0){			// move forward 1
			moves[m][0] = i - 8;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;	
			moves[m][3] = WHITE_PAWN;;
			m++;
		}
		if (((PAWN_FORWARD_2 >> i) & 1) != 0){			// move forward 2
			moves[m][0] = i - 16;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_PAWN;;
			m++;
		}
		if (((PAWN_RIGHT_PROMOTION >> i) & 1) != 0){		// capture right (with promotion)
			moves[m][0] = i - 7;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_QUEEN;
			m++;
			moves[m][0] = i - 7;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_KNIGHT;
			m++;	
			moves[m][0] = i - 7;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_ROOK;
			m++;	
			moves[m][0] = i - 7;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_BISHOP;
			m++;		
		}
		if (((PAWN_LEFT_PROMOTION >> i) & 1) != 0){			// capture left (with promotion)
			moves[m][0] = i - 9;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_QUEEN;
			m++;
			moves[m][0] = i - 9;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_KNIGHT;
			m++;	
			moves[m][0] = i - 9;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_ROOK;
			m++;	
			moves[m][0] = i - 9;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_BISHOP;
			m++;		
		}
		if (((PAWN_FORWARD_PROMOTION >> i) & 1) != 0){		// move forward 1 (with promotion)
			moves[m][0] = i - 8;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_QUEEN;
			m++;
			moves[m][0] = i - 8;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_KNIGHT;
			m++;	
			moves[m][0] = i - 8;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_ROOK;
			m++;	
			moves[m][0] = i - 8;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_BISHOP;
			m++;		
		}
		if (((PAWN_RIGHT_EP >> i) & 1) != 0){				// en passant right
			moves[m][0] = i - 7;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_PAWN;;
			m++;
		}
		if (((PAWN_LEFT_EP >> i) & 1) != 0){				// en passant left
			moves[m][0] = i - 9;
			moves[m][1] = i;
			moves[m][2] = WHITE_PAWN;
			moves[m][3] = WHITE_PAWN;;
			m++;
		}
	}
}

// //==============================================
// // PossibleMovesWP()
// //==============================================
// void Bitboard::PossibleMovesWP(uint8_t moves[256][5], uint8_t & n, uint8_t scoresheet[256][5], uint8_t L)
// {
// 	uint64_t PAWN_MOVES;
// 	uint64_t EP_FILE;

// 	// en passants
// 	if ((L > 0) && (scoresheet[L - 1][1] == scoresheet[L - 1][3]) && (scoresheet[L - 1][0] == scoresheet[L - 1][2] - 2)){
// 		EP_FILE = files[scoresheet[L - 1][3]];
// 		PAWN_MOVES = (WP << 1) & BP & RANK_5 & ~FILE_A & EP_FILE;
// 		if (PAWN_MOVES != 0){
// 			moves[n][2] = 2;
// 			moves[n][3] = scoresheet[L - 1][3];
// 			moves[n][0] = 3;
// 			moves[n][1] = moves[n][3] - 1;
// 			moves[n][4] = 'e';
// 			n++;
// 		}

// 		PAWN_MOVES = (WP >> 1) & BP & RANK_5 & ~FILE_H & EP_FILE;
// 		// std::cout << PAWN_MOVES << std::endl;
// 		// std::cout << std::bitset<64>(WP) << std::endl;
// 		// std::cout << std::bitset<64>(BP) << std::endl;
// 		if (PAWN_MOVES != 0){
// 			moves[n][2] = 2;
// 			moves[n][3] = scoresheet[L - 1][3];
// 			moves[n][0] = 3;
// 			moves[n][1] = moves[n][3] + 1;
// 			moves[n][4] = 'e';
// 			n++;
// 		}
// 	} 

// 	PAWN_MOVES = (WP >> 7) & BLACK_UNITS & ~RANK_8 & ~FILE_A; // capture right
// 	for (int i = 0; i < 64; i++){
// 		if (((PAWN_MOVES >> i) & 1) == 1){
// 			moves[n][2] = i/8;
// 			moves[n][3] = i%8;
// 			moves[n][0] = moves[n][2] + 1;
// 			moves[n][1] = moves[n][3] - 1;
// 			moves[n][4] = 0;
// 			n++;		
// 		}
// 	}
// 	PAWN_MOVES = (WP >> 9) & BLACK_UNITS & ~RANK_8 & ~FILE_H; // capture left
// 	for (int i = 0; i < 64; i++){
// 		if (((PAWN_MOVES >> i) & 1) == 1){
// 			moves[n][2] = i/8;
// 			moves[n][3] = i%8;
// 			moves[n][0] = moves[n][2] + 1;
// 			moves[n][1] = moves[n][3] + 1;
// 			moves[n][4] = 0;
// 			n++;		
// 		}
// 	}
// 	PAWN_MOVES = (WP >> 8) & EMPTY & ~RANK_8; // move forward 1
// 	for (int i = 0; i < 64; i++){
// 		if (((PAWN_MOVES >> i) & 1) == 1){
// 			moves[n][2] = i/8;
// 			moves[n][3] = i%8;
// 			moves[n][0] = moves[n][2] + 1;
// 			moves[n][1] = moves[n][3];
// 			moves[n][4] = 0;
// 			n++;		
// 		}
// 	}
// 	PAWN_MOVES = (WP >> 16) & EMPTY & (EMPTY >> 8) & RANK_4; // move forward 2
// 	for (int i = 0; i < 64; i++){
// 		if (((PAWN_MOVES >> i) & 1) == 1){
// 			moves[n][2] = i/8;
// 			moves[n][3] = i%8;
// 			moves[n][0] = moves[n][2] + 2;
// 			moves[n][1] = moves[n][3];
// 			moves[n][4] = 0;
// 			n++;		
// 		}
// 	}
// 	PAWN_MOVES = (WP >> 16) & EMPTY & (EMPTY >> 8) & RANK_4; // move forward 2
// 	for (int i = 0; i < 64; i++){
// 		if (((PAWN_MOVES >> i) & 1) == 1){
// 			moves[n][2] = i/8;
// 			moves[n][3] = i%8;
// 			moves[n][0] = moves[n][2] + 2;
// 			moves[n][1] = moves[n][3];
// 			moves[n][4] = 0;
// 			n++;		
// 		}
// 	}
	
// 	// pawn promotions
// 	char promotion_pieces[] = {'q', 'n', 'r', 'b'};
// 	PAWN_MOVES = (WP >> 7) & BLACK_UNITS & RANK_8 & ~FILE_A; // capture right
// 	for (int i = 0; i < 64; i++){
// 		if (((PAWN_MOVES >> i) & 1) == 1){
// 			for (int j = 0; j < 4; j++){
// 				moves[n][2] = i/8;
// 				moves[n][3] = i%8;
// 				moves[n][0] = moves[n][2] + 1;
// 				moves[n][1] = moves[n][3] - 1;
// 				moves[n][4] = promotion_pieces[j];
// 				n++;	
// 			}
// 		}
// 	}
// 	PAWN_MOVES = (WP >> 9) & BLACK_UNITS & RANK_8 & ~FILE_H; // capture left
// 	for (int i = 0; i < 64; i++){
// 		if (((PAWN_MOVES >> i) & 1) == 1){
// 			for (int j = 0; j < 4; j++){
// 				moves[n][2] = i/8;
// 				moves[n][3] = i%8;
// 				moves[n][0] = moves[n][2] + 1;
// 				moves[n][1] = moves[n][3] - 1;
// 				moves[n][4] = promotion_pieces[j];
// 				n++;	
// 			}
// 		}
// 	}
// 	PAWN_MOVES = (WP >> 8) & EMPTY & RANK_8; // move forward 1
// 	for (int i = 0; i < 64; i++){
// 		if (((PAWN_MOVES >> i) & 1) == 1){
// 			for (int j = 0; j < 4; j++){
// 				moves[n][2] = i/8;
// 				moves[n][3] = i%8;
// 				moves[n][0] = moves[n][2] + 1;
// 				moves[n][1] = moves[n][3] - 1;
// 				moves[n][4] = promotion_pieces[j];
// 				n++;	
// 			}
// 		}
// 	}

// }



