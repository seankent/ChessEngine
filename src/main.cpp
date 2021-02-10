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
	std::cout << "hi";
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
	// char board[8][8] = {
	// 	{' ', ' ', ' ', ' ', 'r', ' ', 'k', ' '},
	// 	{' ', ' ', ' ', ' ', 'r', 'p', 'p', 'p'},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'N'},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', 'P', 'P', 'P'},
	// 	{'R', ' ', ' ', ' ', ' ', ' ', 'K', ' '},
	// };
	// char board[8][8] = {
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// };
	// char board[8][8] = {
	// 	{' ', ' ', ' ', ' ', ' ', ' ', 'k', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', 'r', 'P', ' '},
	// 	{' ', ' ', 'p', ' ', 'R', 'n', ' ', 'K'},
	// 	{' ', ' ', ' ', 'p', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', 'P', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', 'P', 'B', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// };
	// char board[8][8] = {
	// 	{' ', ' ', ' ', 'r', ' ', ' ', 'k', ' '},
	// 	{' ', ' ', ' ', ' ', 'q', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', 'p', ' '},
	// 	{' ', ' ', ' ', 'b', ' ', ' ', 'N', ' '},
	// 	{' ', ' ', ' ', ' ', 'B', ' ', ' ', 'Q'},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', 'P', 'P'},
	// 	{' ', ' ', ' ', ' ', ' ', 'R', 'K', ' '},
	// };
	// std::cout << "hi";

	// char board[8][8] = {
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', 'P', ' ', 'P', ' ', 'P', ' '},
	// 	{' ', ' ', ' ', 'P', 'k', 'P', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', 'K', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// 	{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
	// };


	// //Bitboard bitboard(board, WHITE);
	Bitboard bitboard;
	Search search(bitboard);
	// search.bitboard.Print();
	search.Minimax(5);

	// uint64_t UNIT0, UNIT1;
	// uint8_t id0, id1;
	// while (1){
	// 	search.Minimax(5);
	// 	UNIT0 = search.BEST0;
	// 	UNIT1 = search.BEST1;
	// 	id0 = search.ID0;
	// 	id1 = search.ID1;
	// 	if (UNIT0 == 0x0UL) break;
	// 	search.bitboard.Move(UNIT0, UNIT1, id0, id1);
	// 	search.bitboard.Print();
	// }
	// // // Test_Move();
	// // //std::cout << "this message \f weeee" << std::endl;
	// Game game(board, BLACK);
	// // // Game game;
	// game.Run();

	// Bitboard bitboard;
	// Search search(bitboard);
	// search.DepthFirstSearch(5);

	// Bitboard bitboard(board, BLACK);
	// bitboard.Print();
	// //std::cout << "Turn: " << bitboard.turn << std::endl;
	// Search search(bitboard);
	// uint64_t UNIT0, UNIT1;
	// uint8_t id0, id1;
	// search.Minimax(4);
	// UNIT0 = search.BEST0;
	// UNIT1 = search.BEST1;
	// id0 = search.ID0;
	// id1 = search.ID1;
	// //std::cout << "UNIT0: ";
	// //bitboard.PrintBitboard(UNIT0);
	// //std::cout << "UNIT1: ";
	// //bitboard.PrintBitboard(UNIT1);
	// search.bitboard.Move(UNIT0, UNIT1, id0, id1);
	// //std::cout << "Turn: " << bitboard.turn << std::endl;
	// search.bitboard.Print();
	// // std::cout << "UNIT0: ";
	// // bitboard.PrintBitboard(UNIT0);
	// // std::cout << "UNIT1: ";
	// // bitboard.PrintBitboard(UNIT1);
	// // std::cout << "Turn: " << bitboard.turn << std::endl;
	// search.Minimax(1);
	// UNIT0 = search.BEST0;
	// UNIT1 = search.BEST1;
	// id0 = search.ID0;
	// id1 = search.ID1;
	// search.bitboard.Move(UNIT0, UNIT1, id0, id1);
	// search.bitboard.Print();

	// search.Minimax(4);
	// UNIT0 = search.BEST0;
	// UNIT1 = search.BEST1;
	// id0 = search.ID0;
	// id1 = search.ID1;
	// search.bitboard.Move(UNIT0, UNIT1, id0, id1);
	// search.bitboard.Print();


	return 0;
}

