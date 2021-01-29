//==============================================
// include
//==============================================
#include "test_bitboard.hpp"

//==============================================
// Test_MovesWN_0
//==============================================
void Test_MovesWN_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'N', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WN, UNIT, i);
	uint64_t MOVES = bitboard.MovesWN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWN_1
//==============================================
void Test_MovesWN_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'N', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WN, UNIT, i);
	uint64_t MOVES = bitboard.MovesWN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWN_2
//==============================================
void Test_MovesWN_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', 'N', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WN, UNIT, i);
	uint64_t MOVES = bitboard.MovesWN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWN_3
//==============================================
void Test_MovesWN_3()
{
	std::cout << "Test 3:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'N', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WN, UNIT, i);
	uint64_t MOVES = bitboard.MovesWN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWN_4
//==============================================
void Test_MovesWN_4()
{
	std::cout << "Test 4:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'N', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WN, UNIT, i);
	uint64_t MOVES = bitboard.MovesWN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWN_5
//==============================================
void Test_MovesWN_5()
{
	std::cout << "Test 5:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'N'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WN, UNIT, i);
	uint64_t MOVES = bitboard.MovesWN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWN_6
//==============================================
void Test_MovesWN_6()
{
	std::cout << "Test 6:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'Q', ' ', 'b', ' ', ' ', ' '},
		{' ', 'q', ' ', ' ', ' ', 'B', ' ', ' '},
		{' ', ' ', ' ', 'N', ' ', ' ', ' ', ' '},
		{' ', 'r', ' ', ' ', ' ', 'P', ' ', ' '},
		{' ', ' ', 'R', ' ', 'p', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WN, UNIT, i);
	uint64_t MOVES = bitboard.MovesWN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWN
//==============================================
void Test_MovesWN()
{
	Test_MovesWN_0();
	Test_MovesWN_1();
	Test_MovesWN_2();
	Test_MovesWN_3();
	Test_MovesWN_4();
	Test_MovesWN_5();
	Test_MovesWN_6();
}

//==============================================
// Test_MovesBN_0
//==============================================
void Test_MovesBN_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', 'n', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BN, UNIT, i);
	uint64_t MOVES = bitboard.MovesBN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBN_1
//==============================================
void Test_MovesBN_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'n', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BN, UNIT, i);
	uint64_t MOVES = bitboard.MovesBN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBN_2
//==============================================
void Test_MovesBN_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', 'n', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BN, UNIT, i);
	uint64_t MOVES = bitboard.MovesBN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBN_3
//==============================================
void Test_MovesBN_3()
{
	std::cout << "Test 3:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'n', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BN, UNIT, i);
	uint64_t MOVES = bitboard.MovesBN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBN_4
//==============================================
void Test_MovesBN_4()
{
	std::cout << "Test 4:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'n', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BN, UNIT, i);
	uint64_t MOVES = bitboard.MovesBN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBN_5
//==============================================
void Test_MovesBN_5()
{
	std::cout << "Test 5:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'n'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BN, UNIT, i);
	uint64_t MOVES = bitboard.MovesBN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBN_6
//==============================================
void Test_MovesBN_6()
{
	std::cout << "Test 6:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'Q', ' ', 'b', ' ', ' ', ' '},
		{' ', 'q', ' ', ' ', ' ', 'B', ' ', ' '},
		{' ', ' ', ' ', 'n', ' ', ' ', ' ', ' '},
		{' ', 'r', ' ', ' ', ' ', 'P', ' ', ' '},
		{' ', ' ', 'R', ' ', 'p', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BN, UNIT, i);
	uint64_t MOVES = bitboard.MovesBN(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBN
//==============================================
void Test_MovesBN()
{
	Test_MovesBN_0();
	Test_MovesBN_1();
	Test_MovesBN_2();
	Test_MovesBN_3();
	Test_MovesBN_4();
	Test_MovesBN_5();
	Test_MovesBN_6();
}

//==============================================
// Test_MovesWR_0
//==============================================
void Test_MovesWR_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'R', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WR, UNIT, i);
	uint64_t MOVES = bitboard.MovesWR(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWR_1
//==============================================
void Test_MovesWR_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'R', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WR, UNIT, i);
	uint64_t MOVES = bitboard.MovesWR(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWR_2
//==============================================
void Test_MovesWR_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', 'q', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'Q', ' ', ' ', 'R', 'B', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', 'b', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WR, UNIT, i);
	uint64_t MOVES = bitboard.MovesWR(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWR
//==============================================
void Test_MovesWR()
{
	Test_MovesWR_0();
	Test_MovesWR_1();
	Test_MovesWR_2();
}

//==============================================
// Test_MovesBR_0
//==============================================
void Test_MovesBR_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'r'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BR, UNIT, i);
	uint64_t MOVES = bitboard.MovesBR(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBR_1
//==============================================
void Test_MovesBR_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'r', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BR, UNIT, i);
	uint64_t MOVES = bitboard.MovesBR(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBR_2
//==============================================
void Test_MovesBR_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', 'q', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'Q', ' ', ' ', 'r', 'B', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', 'b', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BR, UNIT, i);
	uint64_t MOVES = bitboard.MovesBR(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBR
//==============================================
void Test_MovesBR()
{
	Test_MovesBR_0();
	Test_MovesBR_1();
	Test_MovesBR_2();
}

//==============================================
// Test_MovesWB_0
//==============================================
void Test_MovesWB_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'B', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WB, UNIT, i);
	uint64_t MOVES = bitboard.MovesWB(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWB_1
//==============================================
void Test_MovesWB_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'B', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WB, UNIT, i);
	uint64_t MOVES = bitboard.MovesWB(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWB_2
//==============================================
void Test_MovesWB_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', 'Q', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'q'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', 'B', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', 'N', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'n', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WB, UNIT, i);
	uint64_t MOVES = bitboard.MovesWB(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWB
//==============================================
void Test_MovesWB()
{
	Test_MovesWB_0();
	Test_MovesWB_1();
	Test_MovesWB_2();
}

//==============================================
// Test_MovesBB_0
//==============================================
void Test_MovesBB_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', 'b', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BB, UNIT, i);
	uint64_t MOVES = bitboard.MovesBB(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBB_1
//==============================================
void Test_MovesBB_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'b', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BB, UNIT, i);
	uint64_t MOVES = bitboard.MovesBB(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBB_2
//==============================================
void Test_MovesBB_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', 'Q', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'q'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', 'b', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', 'N', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'n', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BB, UNIT, i);
	uint64_t MOVES = bitboard.MovesBB(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBB
//==============================================
void Test_MovesBB()
{
	Test_MovesBB_0();
	Test_MovesBB_1();
	Test_MovesBB_2();
}

//==============================================
// Test_MovesWQ_0
//==============================================
void Test_MovesWQ_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WQ, UNIT, i);
	uint64_t MOVES = bitboard.MovesWQ(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWQ_1
//==============================================
void Test_MovesWQ_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WQ, UNIT, i);
	uint64_t MOVES = bitboard.MovesWQ(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWQ_2
//==============================================
void Test_MovesWQ_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'k', ' ', ' ', 'N', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'r', ' ', ' ', ' ', ' ', 'Q', 'R'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', 'b', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WQ, UNIT, i);
	uint64_t MOVES = bitboard.MovesWQ(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWQ
//==============================================
void Test_MovesWQ()
{
	Test_MovesWQ_0();
	Test_MovesWQ_1();
	Test_MovesWQ_2();
}

//==============================================
// Test_MovesBQ_0
//==============================================
void Test_MovesBQ_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', 'q', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BQ, UNIT, i);
	uint64_t MOVES = bitboard.MovesBQ(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBQ_1
//==============================================
void Test_MovesBQ_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'q', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BQ, UNIT, i);
	uint64_t MOVES = bitboard.MovesBQ(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBQ_2
//==============================================
void Test_MovesBQ_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'B', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'N', ' ', ' ', ' ', ' ', 'q', 'n'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', 'K', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BQ, UNIT, i);
	uint64_t MOVES = bitboard.MovesBQ(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBQ
//==============================================
void Test_MovesBQ()
{
	Test_MovesBQ_0();
	Test_MovesBQ_1();
	Test_MovesBQ_2();
}

//==============================================
// Test_MovesWK_0
//==============================================
void Test_MovesWK_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', 'K', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WK, UNIT, i);
	uint64_t MOVES = bitboard.MovesWK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWK_1
//==============================================
void Test_MovesWK_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', 'K', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WK, UNIT, i);
	uint64_t MOVES = bitboard.MovesWK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWK_2
//==============================================
void Test_MovesWK_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'r', 'R', 'q', ' ', ' ', ' ', ' '},
		{' ', 'N', 'K', 'Q', ' ', ' ', ' ', ' '},
		{' ', 'n', 'B', 'b', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WK, UNIT, i);
	uint64_t MOVES = bitboard.MovesWK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWK_3
//==============================================
void Test_MovesWK_3()
{
	std::cout << "Test 3:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', 'K', ' ', ' ', 'R'},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WK, UNIT, i);
	uint64_t MOVES = bitboard.MovesWK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWK_4
//==============================================
void Test_MovesWK_4()
{
	std::cout << "Test 4:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'R', ' ', ' ', ' ', 'K', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WK, UNIT, i);
	uint64_t MOVES = bitboard.MovesWK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWK_5
//==============================================
void Test_MovesWK_5()
{
	std::cout << "Test 5:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'b', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'R', ' ', ' ', ' ', 'K', ' ', ' ', 'R'},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WK, UNIT, i);
	uint64_t MOVES = bitboard.MovesWK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWK_6
//==============================================
void Test_MovesWK_6()
{
	std::cout << "Test 6:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'R', ' ', ' ', ' ', 'K', ' ', 'N', 'R'},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WK, UNIT, i);
	uint64_t MOVES = bitboard.MovesWK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWK
//==============================================
void Test_MovesWK()
{
	Test_MovesWK_0();
	Test_MovesWK_1();
	Test_MovesWK_2();
	Test_MovesWK_3();
	Test_MovesWK_4();
	Test_MovesWK_5();
	Test_MovesWK_6();
}

//==============================================
// Test_MovesBK_0
//==============================================
void Test_MovesBK_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', 'k', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BK, UNIT, i);
	uint64_t MOVES = bitboard.MovesBK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBK_1
//==============================================
void Test_MovesBK_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', 'k', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BK, UNIT, i);
	uint64_t MOVES = bitboard.MovesBK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBK_2
//==============================================
void Test_MovesBK_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'r', 'R', 'q', ' ', ' ', ' ', ' '},
		{' ', 'N', 'k', 'Q', ' ', ' ', ' ', ' '},
		{' ', 'n', 'B', 'b', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BK, UNIT, i);
	uint64_t MOVES = bitboard.MovesBK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBK_3
//==============================================
void Test_MovesBK_3()
{
	std::cout << "Test 3:" << std::endl;
	char board[8][8] = {
		{'r', ' ', ' ', ' ', 'k', ' ', ' ', 'r'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BK, UNIT, i);
	uint64_t MOVES = bitboard.MovesBK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBK_4
//==============================================
void Test_MovesBK_4()
{
	std::cout << "Test 4:" << std::endl;
	char board[8][8] = {
		{'r', ' ', ' ', ' ', 'k', ' ', ' ', 'r'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', 'Q', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BK, UNIT, i);
	uint64_t MOVES = bitboard.MovesBK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBK_5
//==============================================
void Test_MovesBK_5()
{
	std::cout << "Test 5:" << std::endl;
	char board[8][8] = {
		{'r', ' ', ' ', ' ', 'k', ' ', ' ', 'r'},
		{' ', ' ', 'P', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BK, UNIT, i);
	uint64_t MOVES = bitboard.MovesBK(UNIT, i);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBK
//==============================================
void Test_MovesBK()
{
	Test_MovesBK_0();
	Test_MovesBK_1();
	Test_MovesBK_2();
	Test_MovesBK_3();
	Test_MovesBK_4();
	Test_MovesBK_5();
}

//==============================================
// Test_MovesWP_0
//==============================================
void Test_MovesWP_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'P', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WP, UNIT, i);
	uint64_t MOVES = bitboard.MovesWP(UNIT);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWP_1
//==============================================
void Test_MovesWP_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'P', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WP, UNIT, i);
	uint64_t MOVES = bitboard.MovesWP(UNIT);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWP_2
//==============================================
void Test_MovesWP_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'p', ' ', ' ', ' ', ' ', ' ', 'p'},
		{'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WP, UNIT, i);
	uint64_t MOVES = bitboard.MovesWP(UNIT);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWP_3
//==============================================
void Test_MovesWP_3()
{
	std::cout << "Test 3:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'p', ' ', ' ', ' ', ' ', ' ', 'p', 'p'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'P'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WP, UNIT, i);
	uint64_t MOVES = bitboard.MovesWP(UNIT);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWP_4
//==============================================
void Test_MovesWP_4()
{
	std::cout << "Test 4:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'P', 'p', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WP, UNIT, i);
	bitboard.FILE_EP = FILE_C;
	uint64_t MOVES = bitboard.MovesWP(UNIT);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWP_5
//==============================================
void Test_MovesWP_5()
{
	std::cout << "Test 5:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'p', 'P', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.WP, UNIT, i);
	bitboard.FILE_EP = FILE_B;
	uint64_t MOVES = bitboard.MovesWP(UNIT);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesWP
//==============================================
void Test_MovesWP()
{
	Test_MovesWP_0();
	Test_MovesWP_1();
	Test_MovesWP_2();
	Test_MovesWP_3();
	Test_MovesWP_4();
	Test_MovesWP_5();
}

//==============================================
// Test_MovesBP_0
//==============================================
void Test_MovesBP_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', 'p', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BP, UNIT, i);
	uint64_t MOVES = bitboard.MovesBP(UNIT);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBP_1
//==============================================
void Test_MovesBP_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', 'p', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', 'P', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BP, UNIT, i);
	uint64_t MOVES = bitboard.MovesBP(UNIT);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBP_2
//==============================================
void Test_MovesBP_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'p', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'P'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BP, UNIT, i);
	uint64_t MOVES = bitboard.MovesBP(UNIT);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBP_3
//==============================================
void Test_MovesBP_3()
{
	std::cout << "Test 3:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'p', 'P', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'P'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.FILE_EP = FILE_B;
	bitboard.LS1B(bitboard.BP, UNIT, i);
	uint64_t MOVES = bitboard.MovesBP(UNIT);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBP_4
//==============================================
void Test_MovesBP_4()
{
	std::cout << "Test 4:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', 'P', 'p'},
		{'P', ' ', ' ', ' ', ' ', ' ', ' ', 'P'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.FILE_EP = FILE_G;
	bitboard.LS1B(bitboard.BP, UNIT, i);
	uint64_t MOVES = bitboard.MovesBP(UNIT);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBP_5
//==============================================
void Test_MovesBP_5()
{
	std::cout << "Test 5:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'p', ' ', ' ', ' ', ' ', ' '},
		{' ', 'R', ' ', 'B', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t UNIT;
	uint8_t i;
	bitboard.LS1B(bitboard.BP, UNIT, i);
	uint64_t MOVES = bitboard.MovesBP(UNIT);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesBP
//==============================================
void Test_MovesBP()
{
	Test_MovesBP_0();
	Test_MovesBP_1();
	Test_MovesBP_2();
	Test_MovesBP_3();
	Test_MovesBP_4();
	Test_MovesBP_5();
}


//==============================================
// Test_MovesW_0
//==============================================
void Test_MovesW_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t MOVES = bitboard.MovesB(bitboard.ATTACKS_W);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesW_1
//==============================================
void Test_MovesW_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'R', ' ', ' ', ' ', ' ', ' ', ' ', 'R'},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t MOVES = bitboard.MovesB(bitboard.ATTACKS_W);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesW_2
//==============================================
void Test_MovesW_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'N', ' ', ' ', ' ', ' ', 'N', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t MOVES = bitboard.MovesB(bitboard.ATTACKS_W);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesW_3
//==============================================
void Test_MovesW_3()
{
	std::cout << "Test 3:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'B', ' ', ' ', 'B', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t MOVES = bitboard.MovesB(bitboard.ATTACKS_W);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesW_4
//==============================================
void Test_MovesW_4()
{
	std::cout << "Test 4:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', 'Q', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t MOVES = bitboard.MovesB(bitboard.ATTACKS_W);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesW_5
//==============================================
void Test_MovesW_5()
{
	std::cout << "Test 5:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', 'K', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', 'K', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint64_t MOVES = bitboard.MovesB(bitboard.ATTACKS_W);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesW
//==============================================
void Test_MovesW()
{
	Test_MovesW_0();
	Test_MovesW_1();
	Test_MovesW_2();
	Test_MovesW_3();
	Test_MovesW_4();
	Test_MovesW_5();
}


//==============================================
// Test_MovesB_0
//==============================================
void Test_MovesB_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t MOVES = bitboard.MovesB(bitboard.ATTACKS_B);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesB_1
//==============================================
void Test_MovesB_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{'r', ' ', ' ', ' ', ' ', ' ', ' ', 'r'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t MOVES = bitboard.MovesB(bitboard.ATTACKS_B);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesB_2
//==============================================
void Test_MovesB_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', 'n', ' ', ' ', ' ', ' ', 'n', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t MOVES = bitboard.MovesB(bitboard.ATTACKS_B);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesB_3
//==============================================
void Test_MovesB_3()
{
	std::cout << "Test 3:" << std::endl;
	char board[8][8] = {
		{' ', ' ', 'b', ' ', ' ', 'b', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board,BLACK);
	uint64_t MOVES = bitboard.MovesB(bitboard.ATTACKS_B);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesB_4
//==============================================
void Test_MovesB_4()
{
	std::cout << "Test 4:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', 'q', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', 'q', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t MOVES = bitboard.MovesB(bitboard.ATTACKS_B);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesB_5
//==============================================
void Test_MovesB_5()
{
	std::cout << "Test 5:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', 'k', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'k', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint64_t MOVES = bitboard.MovesB(bitboard.ATTACKS_B);
	bitboard.PrintMoves(MOVES);
}

//==============================================
// Test_MovesB
//==============================================
void Test_MovesB()
{
	Test_MovesB_0();
	Test_MovesB_1();
	Test_MovesB_2();
	Test_MovesB_3();
	Test_MovesB_4();
	Test_MovesB_5();
}

//==============================================
// Test_Move_0
//==============================================
void Test_Move_0()
{
	std::cout << "Test 0:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'R', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint8_t i0 = 0;
	uint8_t i1 = 16;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_1
//==============================================
void Test_Move_1()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'N', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint8_t i0 = 1;
	uint8_t i1 = 18;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_2
//==============================================
void Test_Move_2()
{
	std::cout << "Test 2:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'B', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint8_t i0 = 2;
	uint8_t i1 = 38;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_3
//==============================================
void Test_Move_3()
{
	std::cout << "Test 3:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint8_t i0 = 3;
	uint8_t i1 = 59;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_4
//==============================================
void Test_Move_4()
{
	std::cout << "Test 4:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', 'K', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint8_t i0 = 4;
	uint8_t i1 = 12;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_5
//==============================================
void Test_Move_5()
{
	std::cout << "Test 5:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint8_t i0 = 8;
	uint8_t i1 = 24;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
		bitboard.PrintBitboard(bitboard.FILE_EP);
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_6
//==============================================
void Test_Move_6()
{
	std::cout << "Test 6:" << std::endl;
	char board[8][8] = {
		{'r', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint8_t i0 = 56;
	uint8_t i1 = 48;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_7
//==============================================
void Test_Move_7()
{
	std::cout << "Test 7:" << std::endl;
	char board[8][8] = {
		{' ', 'n', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint8_t i0 = 57;
	uint8_t i1 = 42;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_8
//==============================================
void Test_Move_8()
{
	std::cout << "Test 8:" << std::endl;
	char board[8][8] = {
		{' ', ' ', 'b', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint8_t i0 = 58;
	uint8_t i1 = 40;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_9
//==============================================
void Test_Move_9()
{
	std::cout << "Test 9:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', 'q', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint8_t i0 = 59;
	uint8_t i1 = 3;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_10
//==============================================
void Test_Move_10()
{
	std::cout << "Test 1:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', 'k', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint8_t i0 = 60;
	uint8_t i1 = 52;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_11
//==============================================
void Test_Move_11()
{
	std::cout << "Test 11:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'p', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	uint8_t i0 = 50;
	uint8_t i1 = 34;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
		bitboard.PrintBitboard(bitboard.FILE_EP);
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_12
//==============================================
void Test_Move_12()
{
	std::cout << "Test 12:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'q', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'R', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	uint8_t i0 = 0;
	uint8_t i1 = 32;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_13
//==============================================
void Test_Move_13()
{
	std::cout << "Test 13:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', 'P', 'p', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	bitboard.FILE_EP = FILE_B;
	uint8_t i0 = 26;
	uint8_t i1 = 17;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_14
//==============================================
void Test_Move_14()
{
	std::cout << "Test 14:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', 'P', 'p'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	bitboard.FILE_EP = FILE_H;
	uint8_t i0 = 38;
	uint8_t i1 = 47;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_15
//==============================================
void Test_Move_15()
{
	std::cout << "Test 15:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'P', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	bitboard.FILE_EP = FILE_H;
	uint8_t i0 = 48;
	uint8_t i1 = 56;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, QUEEN);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_16
//==============================================
void Test_Move_16()
{
	std::cout << "Test 16:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', 'p', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, BLACK);
	bitboard.FILE_EP = FILE_H;
	uint8_t i0 = 10;
	uint8_t i1 = 3;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, KNIGHT);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move_17
//==============================================
void Test_Move_17()
{
	std::cout << "Test 17:" << std::endl;
	char board[8][8] = {
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'R', ' ', ' ', ' ', 'K', ' ', ' ', ' '},
	};
	Bitboard bitboard(board, WHITE);
	bitboard.FILE_EP = FILE_H;
	uint8_t i0 = 4;
	uint8_t i1 = 2;
	uint64_t UNIT0 = 0x1UL << i0;
	uint64_t UNIT1 = 0x1UL << i1;
	bool legal = bitboard.Move(UNIT0, UNIT1, NONE);
	if (legal){
		bitboard.Print();
	} 
	else {
		std::cout << "illegal" << std::endl;
	}
}

//==============================================
// Test_Move
//==============================================
void Test_Move()
{
	Test_Move_0();
	Test_Move_1();
	Test_Move_2();
	Test_Move_3();
	Test_Move_4();
	Test_Move_5();
	Test_Move_6();
	Test_Move_7();
	Test_Move_8();
	Test_Move_9();
	Test_Move_10();
	Test_Move_11();
	Test_Move_12();
	Test_Move_13();
	Test_Move_14();
	Test_Move_15();
	Test_Move_16();
	Test_Move_17();
}
