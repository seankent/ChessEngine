#ifndef EVALUATE_HPP
#define EVALUATE_HPP

//==============================================
// include
//==============================================
#include <iostream>
#include "bitboard.hpp"

//==============================================
// Evaluate
//==============================================
int Evaluate(Bitboard bitboard);

//==============================================
// EvaluateMaterial
//==============================================
int EvaluateMaterial(Bitboard bitboard);

#endif