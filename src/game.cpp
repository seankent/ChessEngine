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
	while (1){
		bitboard.Print();
		std::cout << "->     \b\b\b\b\b";
		std::cin >> cmd;

		//if (command == "done") break;
		uint8_t i0, i1;

		// switch (command[0]){
		// 	case 'a': 
		// 		i0 = 0;
		// 		break;
		// 	case 'b':
		// 		i0 = 8;
		// 		break;
		// 	case 'c':
		// 		i0 = 16;
		// 		break;
		// 	case 'c':
		// 		i0 = 24;
		// 		break;
		// 	case 'c':
		// 		i0 = 32;
		// 		break;
		// 	case 'c':
		// 		i0 = 40;
		// 		break;
		// 	case 'c':
		// 		i0 = 48;
		// 		break;
		// 	case 'c':
		// 		i0 = 56;
		// 		break;
		// 	default:
		// 		break;
		// }
		//std::cout << cmd[0];

		if (cmd == "done") break;
		else if (cmd == "0-0"){
			if (bitboard.turn == 0) bitboard.Move(4, 6, NONE);
			else bitboard.Move(60, 62, NONE);
		}
		else if (cmd == "0-0-0"){
			if (bitboard.turn == 0) bitboard.Move(4, 2, NONE);
			else bitboard.Move(60, 58, NONE);
		}
		else {
			if ((cmd[0] < 'a') || (cmd[0] > 'h')) continue;
			if ((cmd[1] < '1') || (cmd[1] > '8')) continue;
			if ((cmd[2] < 'a') || (cmd[2] > 'h')) continue;
			if ((cmd[3] < '1') || (cmd[3] > '8')) continue;
			i0 = (cmd[0] - 'a') + ((cmd[1] - '1') << 3);
			i1 = (cmd[2] - 'a') + ((cmd[3] - '1') << 3);
		}
		
		bitboard.Move(i0, i1, NONE);
		//else break;
		//i0 = 10;
		//std::cout << ('a' -  << std::endl;
		//std::cout << (int)i0 << std::endl;
		//std::cout << (int)i1 << std::endl;
		//std::cout << (cmd[1] < 'a') << std::endl;
		//bitboard.Print();
				
			
		

		std::cout << "\x1B[20F" << std::endl;
	}
	
}

// "\x1b[A"