//==============================================
// boardToBitboards
//==============================================
void boardToBitboards(char board[8][8], unsigned long int * bitboards)
{
	for (int i = 0; i < 12; i++){
		bitboards[i] = 0x0000000000000000UL;
	}

	for (int i = 0; i < 64; i++){
		switch (board[i/8][i%8]){
			case 'r':
				bitboards[0] += 0x0000000000000001UL << i;
				break;
			case 'n':
				bitboards[1] += 0x0000000000000001UL << i;
				break;
			case 'b':
				bitboards[2] += 0x0000000000000001UL << i;
				break;
			case 'q':
				bitboards[3] += 0x0000000000000001UL << i;
				break;
			case 'k':
				bitboards[4] += 0x0000000000000001UL << i;
				break;
			case 'p':
				bitboards[5] += 0x0000000000000001UL << i;
				break;
			case 'R':
				bitboards[6] += 0x0000000000000001UL << i;
				break;
			case 'N':
				bitboards[7] += 0x0000000000000001UL << i;
				break;
			case 'B':
				bitboards[8] += 0x0000000000000001UL << i;
				break;
			case 'Q':
				bitboards[9] += 0x0000000000000001UL << i;
				break;
			case 'K':
				bitboards[10] += 0x0000000000000001UL << i;
				break;
			case 'P':
				bitboards[11] += 0x0000000000000001UL << i;
				break;
			defaULt:
				break;
		}
	}
}

//==============================================
// bitboardsToBoard
//==============================================
void bitboardsToBoard(unsigned long int * bitboards, char board[8][8])
{
	for (int i = 0; i < 64; i++)
	{
		board[i/8][i%8] = '-';
		if (((bitboards[0] >> i) & 1) == 1) board[i/8][i%8] = 'r';
		if (((bitboards[1] >> i) & 1) == 1) board[i/8][i%8] = 'n';
		if (((bitboards[2] >> i) & 1) == 1) board[i/8][i%8] = 'b';
		if (((bitboards[3] >> i) & 1) == 1) board[i/8][i%8] = 'q';
		if (((bitboards[4] >> i) & 1) == 1) board[i/8][i%8] = 'k';
		if (((bitboards[5] >> i) & 1) == 1) board[i/8][i%8] = 'p';
		if (((bitboards[6] >> i) & 1) == 1) board[i/8][i%8] = 'R';
		if (((bitboards[7] >> i) & 1) == 1) board[i/8][i%8] = 'N';
		if (((bitboards[8] >> i) & 1) == 1) board[i/8][i%8] = 'B';
		if (((bitboards[9] >> i) & 1) == 1) board[i/8][i%8] = 'Q';
		if (((bitboards[10] >> i) & 1) == 1) board[i/8][i%8] = 'K';
		if (((bitboards[11] >> i) & 1) == 1) board[i/8][i%8] = 'P';
	}
}

//==============================================
// printChessBoard
//==============================================
void printChessBoard(char board[8][8])
{
	for (int i = 0; i < 8; i++){
		if (i != 0) std::cout << std::endl;
		for (int j = 0; j < 8; j++){
			std::cout << board[i][j];
			if (j != 7) std::cout << ' ';
		}
	}
	std::cout << std::endl;
}

// std::cout << "Hello World!" << std::endl;
	// std::cout << sizeof(unsigned long int) << std::endl;
	// char board[8][8] = {
	// 	{'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
	// 	{'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
	// 	{'-', '-', '-', '-', '-', '-', '-', '-'},
	// 	{'-', '-', '-', '-', '-', '-', '-', '-'},
	// 	{'-', '-', '-', '-', '-', '-', '-', '-'},
	// 	{'-', '-', '-', '-', '-', '-', '-', '-'},
	// 	{'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
	// 	{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
	// };
	// unsigned long int whiteRooks, whiteKnights, whiteBishops, whiteQueens, whiteKing, whitePawns, blackRooks, blackKnights, blackBishops, blackQueens, blackKing, blackPawns;
	// unsigned long int bitboards[] = {
	// 	whiteRooks, 
	// 	whiteKnights, 
	// 	whiteBishops, 
	// 	whiteQueens, 
	// 	whiteKing, 
	// 	whitePawns, 
	// 	blackRooks, 
	// 	blackKnights, 
	// 	blackBishops, 
	// 	blackQueens, 
	// 	blackKing, 
	// 	blackPawns
	// };
	// char board[8][8] = {
	// 	{'-', '-', '-', '-', '-', '-', '-', '-'},
	// 	{'-', '-', '-', '-', '-', '-', '-', '-'},
	// 	{'-', '-', '-', '-', '-', '-', '-', '-'},
	// 	{'-', '-', '-', '-', '-', '-', '-', '-'},
	// 	{'-', '-', '-', '-', '-', '-', '-', '-'},
	// 	{'-', '-', '-', '-', '-', '-', '-', '-'},
	// 	{'-', '-', '-', '-', '-', '-', '-', '-'},
	// 	{'-', '-', '-', '-', '-', '-', '-', '-'},
	// };
	// //printChessBoard(board);
	// unsigned long int bitboards[12];
	// boardToBitboards(board, bitboards);
	// //printChessBoard(board);
	// bitboards[0] = FILE_H;
	// bitboardsToBoard(bitboards, board);
	// printChessBoard(board);
	// std::cout << "whiteRooks:" << std::bitset<64>(bitboards[0])  << std::endl;
	// std::cout << "whiteKnights: " << std::bitset<64>(bitboards[1])  << std::endl;
	// std::cout << "whiteBishops: " << std::bitset<64>(bitboards[2])  << std::endl;
	// std::cout << "whiteQueens:" << std::bitset<64>(bitboards[3])  << std::endl;
	// std::cout << "whiteKing:" << std::bitset<64>(bitboards[4])  << std::endl;
	// std::cout << "whitePawns:" << std::bitset<64>(bitboards[5])  << std::endl;
	// std::cout << "blackRooks:" << std::bitset<64>(bitboards[6])  << std::endl;
	// std::cout << "blackKnights: " << std::bitset<64>(bitboards[7])  << std::endl;
	// std::cout << "blackBishops: " << std::bitset<64>(bitboards[8])  << std::endl;
	// std::cout << "blackQueens:" << std::bitset<64>(bitboards[9])  << std::endl;
	// std::cout << "blackKing:" << std::bitset<64>(bitboards[10])  << std::endl;
	// std::cout << "blackPwans:" << std::bitset<64>(bitboards[11])  << std::endl;