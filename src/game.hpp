//==============================================
// include
//==============================================
#include <iostream>
#include <string>
#include "bitboard.hpp"

//==============================================
// Game
//==============================================
class Game
{
public:
	Bitboard bitboard;
	std::string cmd;
public:
	Game();
	Game(char board[8][8], bool turn);
	void Run();
};