#include <iostream>
#include "bitboard.hpp"
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
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', 'p', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', 'P', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// };
	// // // Test_Move();
	// // //std::cout << "this message \f weeee" << std::endl;
	// Game game(board, BLACK);
	// // // Game game;
	// game.Run();

	//Bitboard bitboard(board, BLACK);
	Bitboard bitboard;
	//bitboard.turn = true;
	Search search(bitboard);
	search.DepthFirstSearch(5);

	//bitboard.Print();
	//foo();
	// uint64_t LS1B;
	// uint8_t i;
	// bitboard.LS1B(0x0, LS1B, i);
	// std::cout << std::bitset<64>(LS1B) << std::endl;
	// std::cout << (int)i << std::endl;
	return 0;
}

