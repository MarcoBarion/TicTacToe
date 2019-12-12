/*
 * game.h
 *
 *  Created on: Dec 12, 2019
 *      Author: marcobarion
 */

#ifndef GAME_HPP_
#define GAME_HPP_


#include "cell.hpp"
#include "xc.cpp"
#include "oc.cpp"

class Game{
	// Constructor
	Game();
	// Instance
	static Game* instance;

	Cell* board[3][3];


public:
	static Game* getInstance();

	void initializeBoard();

	void printBoard();

	char getCellValue(int raw, int column);

	char assignFiche(int row, int column, char fiche);

	void deinitializeBoard();

	bool checkBlockedGame();

	bool checkWinner(char player);

	~Game();
};


#endif /* GAME_HPP_ */
