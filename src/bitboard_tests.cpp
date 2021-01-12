//==============================================
// include
//==============================================
#include <iostream>
#include "bitboard.hpp"
#include "bitboard_tests.hpp"

//==============================================
// Test_Bitboard_PossibleMovesWP_0
//==============================================
void Test_Bitboard_PossibleMovesWP_0()
{
	std::cout << "Test 0." << std::endl;
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
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	uint8_t N = 0;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_1
//==============================================
void Test_Bitboard_PossibleMovesWP_1()
{
	std::cout << "Test 1." << std::endl;
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
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	uint8_t N = 0;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_2
//==============================================
void Test_Bitboard_PossibleMovesWP_2()
{
	std::cout << "Test 2." << std::endl;
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
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	uint8_t N = 0;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_3
//==============================================
void Test_Bitboard_PossibleMovesWP_3()
{
	std::cout << "Test 3." << std::endl;
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
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	uint8_t N = 0;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_4
//==============================================
void Test_Bitboard_PossibleMovesWP_4()
{
	std::cout << "Test 4." << std::endl;
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
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	uint8_t N = 0;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_5
//==============================================
void Test_Bitboard_PossibleMovesWP_5()
{
	std::cout << "Test 5." << std::endl;
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
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	uint8_t N = 0;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_6
//==============================================
void Test_Bitboard_PossibleMovesWP_6()
{
	std::cout << "Test 6." << std::endl;
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', 'b', 'P', 'Q', '-'},
		{'-', '-', '-', '-', '-', 'p', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	uint8_t N = 0;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_7
//==============================================
void Test_Bitboard_PossibleMovesWP_7()
{
	std::cout << "Test 7." << std::endl;
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
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	uint8_t N = 0;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_8
//==============================================
void Test_Bitboard_PossibleMovesWP_8()
{
	std::cout << "Test 8." << std::endl;
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
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	uint8_t N = 0;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_9
//==============================================
void Test_Bitboard_PossibleMovesWP_9()
{
	std::cout << "Test 9." << std::endl;
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
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	uint8_t N = 0;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_10
//==============================================
void Test_Bitboard_PossibleMovesWP_10()
{
	std::cout << "Test 10." << std::endl;
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
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	uint8_t N = 0;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_11
//==============================================
void Test_Bitboard_PossibleMovesWP_11()
{
	std::cout << "Test 11." << std::endl;
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', 'p', 'P', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	scoresheet[0][0] = 12;
	scoresheet[0][1] = 28;
	scoresheet[0][2] = BLACK_PAWN;
	scoresheet[0][3] = BLACK_PAWN;
	uint8_t N = 1;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_12
//==============================================
void Test_Bitboard_PossibleMovesWP_12()
{
	std::cout << "Test 12." << std::endl;
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', 'p', 'P', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	scoresheet[0][0] = 20;
	scoresheet[0][1] = 28;
	scoresheet[0][2] = BLACK_PAWN;
	scoresheet[0][3] = BLACK_PAWN;
	uint8_t N = 1;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_13
//==============================================
void Test_Bitboard_PossibleMovesWP_13()
{
	std::cout << "Test 13." << std::endl;
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'P', '-', '-', '-', '-', '-', '-', 'p'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	scoresheet[0][0] = 8;
	scoresheet[0][1] = 24;
	scoresheet[0][2] = BLACK_PAWN;
	scoresheet[0][3] = BLACK_PAWN;
	uint8_t N = 1;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_14
//==============================================
void Test_Bitboard_PossibleMovesWP_14()
{
	std::cout << "Test 14." << std::endl;
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', 'P', 'p', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	scoresheet[0][0] = 9;
	scoresheet[0][1] = 25;
	scoresheet[0][2] = BLACK_PAWN;
	scoresheet[0][3] = BLACK_PAWN;
	uint8_t N = 1;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP_15
//==============================================
void Test_Bitboard_PossibleMovesWP_15()
{
	std::cout << "Test 15." << std::endl;
	char board[8][8] = {
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', 'P', 'p', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
		{'-', '-', '-', '-', '-', '-', '-', '-'},
	};
	Bitboard bitboard(board);
	uint8_t moves[256][4]; 
	uint8_t m = 0;
	uint8_t scoresheet[256][5];
	scoresheet[0][0] = 17;
	scoresheet[0][1] = 25;
	scoresheet[0][2] = BLACK_PAWN;
	scoresheet[0][3] = BLACK_PAWN;
	uint8_t N = 1;
	bitboard.PossibleMovesWP(moves, m, scoresheet, N);
	bitboard.PrintMoves(moves, m);
	std::cout << std::endl;
}

//==============================================
// Test_Bitboard_PossibleMovesWP
//==============================================
void Test_Bitboard_PossibleMovesWP()
{
	Test_Bitboard_PossibleMovesWP_0();
	Test_Bitboard_PossibleMovesWP_1();
	Test_Bitboard_PossibleMovesWP_2();
	Test_Bitboard_PossibleMovesWP_3();
	Test_Bitboard_PossibleMovesWP_4();
	Test_Bitboard_PossibleMovesWP_5();
	Test_Bitboard_PossibleMovesWP_6();
	Test_Bitboard_PossibleMovesWP_7();
	Test_Bitboard_PossibleMovesWP_8();
	Test_Bitboard_PossibleMovesWP_9();
	Test_Bitboard_PossibleMovesWP_10();
	Test_Bitboard_PossibleMovesWP_11();
	Test_Bitboard_PossibleMovesWP_12();
	Test_Bitboard_PossibleMovesWP_13();
	Test_Bitboard_PossibleMovesWP_14();
	Test_Bitboard_PossibleMovesWP_15();
}
