#include <iostream>
#include "bitboard.hpp"
#include "test_bitboard.hpp"

//==============================================
// main
//==============================================
int main(void)
{
	Test_MovesWN();
	Test_MovesBN();
	Test_MovesWR();
	Test_MovesBR();
	Test_MovesWB();
	Test_MovesBB();
	Test_MovesWQ();
	Test_MovesBQ();
	Test_MovesWK();
	Test_MovesBK();
	Test_MovesWP();
	Test_MovesBP();
	Test_MovesW();
	Test_Move();
	
	//foo();
	// uint64_t LS1B;
	// uint8_t i;
	// bitboard.LS1B(0x0, LS1B, i);
	// std::cout << std::bitset<64>(LS1B) << std::endl;
	// std::cout << (int)i << std::endl;
	return 0;
}

