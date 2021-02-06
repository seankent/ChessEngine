//==============================================
// include
//==============================================
#include "game.hpp"

//==============================================
// Game
//==============================================
Game::Game()
	: bitboard()
{
	// bitboard.Print();
	// std::cout << "\x1b[A";
	// std::cout << "Hello" << std::endl;
}


//==============================================
// Game
//==============================================
Game::Game(char board[8][8], bool turn)
	: bitboard(board, turn)
{
	// bitboard.Print();
	// std::cout << "\x1b[A";
	// std::cout << "Hello" << std::endl;
}


//==============================================
// Run
//==============================================
void Game::Run()
{
	uint8_t i0, i1;
	uint64_t UNIT0, UNIT1;
	while (1){
		bitboard.Print();
		std::cout << "->     \b\b\b\b\b";
		std::cin >> cmd;

		if (cmd == "done") break;
		else if (cmd == "undo") bitboard.Undo();
		else if (cmd == "0-0"){
			if (bitboard.turn == 0) bitboard.Move(0x0000000000000010UL , 0x0000000000000040UL , NONE);
			else bitboard.Move(0x1000000000000000UL, 0x4000000000000000UL, NONE);
		}
		else if (cmd == "0-0-0"){
			if (bitboard.turn == 0) bitboard.Move(0x0000000000000010UL, 0x0000000000000004UL, NONE);
			else bitboard.Move(0x1000000000000000UL, 0x0400000000000000UL, NONE);
		}
		else {
			if ((cmd[0] < 'a') || (cmd[0] > 'h')) continue;
			if ((cmd[1] < '1') || (cmd[1] > '8')) continue;
			if ((cmd[2] < 'a') || (cmd[2] > 'h')) continue;
			if ((cmd[3] < '1') || (cmd[3] > '8')) continue;
			i0 = (cmd[0] - 'a') + ((cmd[1] - '1') << 3);
			i1 = (cmd[2] - 'a') + ((cmd[3] - '1') << 3);
			UNIT0 = 0x1UL << i0;
			UNIT1 = 0x1UL << i1;
			bitboard.Move(UNIT0, UNIT1, NONE);
		}
		// std::cout << "n: " << (int)bitboard.n << std::endl;
		// std::cout << "i0: " << (int)bitboard.moves[bitboard.n-1][0] << std::endl;
		// std::cout << "i1: " << (int)bitboard.moves[bitboard.n-1][1] << std::endl;

		//std::cout << "\x1B[20F" << std::endl;
	}
	
}
