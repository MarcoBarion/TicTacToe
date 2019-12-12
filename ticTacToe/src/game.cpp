/*
 * game.cpp
 *
 *  Created on: Dec 12, 2019
 *      Author: marcobarion
 */

#include "game.hpp"

Game::Game(){}

Game* Game::getInstance(){

	static Game instance;

	return &instance;
}


void Game::initializeBoard(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			board[i][j] = new Cell( '0'+(3*i+j) );
		}
	}
}

void Game::printBoard(){
	for(int i=0; i<3; i++){
		cout<<"\t";
		for(int j=0; j<3; j++){
			board[i][j]->print();
		}
		cout<<endl<<endl;
	}
}

char Game::getCellValue(int row, int column){
	return board[row][column] -> getValue();
}

void Game::assignFiche(int row, int column, char fiche){
	delete board[row][column];
	fiche=='O' ? board[row][column] = new OC() : board[row][column] = new XC();
}

void Game::deinitializeBoard(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			delete board[i][j];
		}
	}
}

bool Game::checkBlockedGame(){

	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			char p = board[i][j]->getValue();
			if(p != 'X' && p != 'O')
				return false;
		}
	}
	return true;

}

bool Game::checkWinner(char player){

	//by raw
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			if(board[i][j]->getValue() != player)
				break;
			else if(j==2)
				return true;
		}
	}

	//by column
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			if(board[j][i]->getValue() != player)
				break;
			else if(j==2)
				return true;
		}
	}

	//cross
	for(int i=0; i<3; ++i){
		if(board[i][i]->getValue() != player)
			break;
		else if(i==2)
			return true;
	}
	for(int i=0; i<3; ++i){
		if(board[i][2-i]->getValue() != player)
			break;
		else if(i==2)
			return true;
	}

	return false;
}

