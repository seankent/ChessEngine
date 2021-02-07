#include <iostream>
#include "bitboard.hpp"
#include "evaluate.hpp"
#include "search.hpp"
#include "game.hpp"
#include "test_bitboard.hpp"

//==============================================
// main
//==============================================
int main(void)
{
	// Test_MovesWN();
	// Test_MovesBN();
	// Test_MovesWR();
	// Test_MovesBR();
	// Test_MovesWB();
	// Test_MovesBB();
	// Test_MovesWQ();
	// Test_MovesBQ();
	// Test_MovesWK();
	// Test_MovesBK();
	// Test_MoveWP();
	// Test_MoveBP();
	// Test_MovesW();
	// char board[8][8] = {
	// 	{' ', ' ', ' ', ' ', 'r', ' ', 'k', ' '},
	// 	{' ', ' ', ' ', ' ', 'r', 'p', 'p', 'p'},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', 'P', 'P', 'P'},
	// 	{'R', ' ', ' ', ' ', ' ', ' ', 'K', ' '},
	// };
	char board[8][8] = {
		{' ', ' ', ' ', ' ', 'r', ' ', 'k', ' '},
		{' ', ' ', ' ', ' ', ' ', 'p', 'p', 'p'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'N'},
		{' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', 'P', 'P', 'P'},
		{' ', ' ', ' ', ' ', ' ', ' ', 'K', ' '},
	};
	// // // Test_Move();
	// // //std::cout << "this message \f weeee" << std::endl;
	// Game game(board, BLACK);
	// // // Game game;
	// game.Run();

	Bitboard bitboard(board, WHITE);
	Search search(bitboard);
	search.Minimax(4);
	uint64_t UNIT0 = search.BEST0;
	uint64_t UNIT1 = search.BEST1;
	uint8_t id0 = search.ID0;
	uint8_t id1 = search.ID1;
	bitboard.Move(UNIT0, UNIT1, id0, id1);
	bitboard.Print();

	return 0;
}

