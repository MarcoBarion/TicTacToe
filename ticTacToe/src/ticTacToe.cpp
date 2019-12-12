//============================================================================
// Name        : ticTacToe.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

/*
 * TODO
 * - reduce the number of loops to check the matrix
 * - write some tests
 * - variable declaration in for loop, is it ok?
 * - remove the include in this file??
 */

//#include "cell.hpp"
//#include "xc.cpp"
//#include "oc.cpp"

//void printBoard(Cell* ptrMatrix[][3]);
//
//void initializeBoard(Cell* ptrMatrix[][3]);
//
//void deinitializeBoard(Cell* ptrMatrix[][3]);
//
//bool checkWinner(Cell* ptrMatrix[][3], char player);
//
//bool checkBlockedGame(Cell* ptrMatrix[][3]);


#include "game.hpp"

int main() {

	//Cell* board[3][3];
	int cell;

	char playerName = 'O';
	bool playing = true;
	char anotherGame ='N';

	//Game::getInstance();

	Game::getInstance()->initializeBoard();
	cout<<"*************************"<<endl;
	cout<<"** LETS START THE GAME **"<<endl;
	cout<<"*************************"<<endl<<endl;

	Game::getInstance()->printBoard();

	while( playing ){

		cout<<"Player " <<playerName <<" select a cell: \n";
		cin>>cell;

		char cellValue = Game::getInstance()->getCellValue(cell/3, cell%3);
		while(cellValue == 'X' || cellValue == 'O'){
			cout<<"The location is already occupied. Choose again: ";
			cin>>cell;
			cellValue = Game::getInstance()->getCellValue(cell/3, cell%3);
		}

		//delete board[cell/3][cell%3];
		//playerName=='O' ? board[cell/3][cell%3] = new OC() : board[cell/3][cell%3] = new XC();
		Game::getInstance()->assignFiche(cell/3, cell%3, playerName);

		Game::getInstance()->printBoard();

		if( Game::getInstance()->checkWinner(playerName) ){
			cout<<"*************************"<<endl;
			cout<<"*****     "<<playerName<<" WON!    *****"<<endl;
			cout<<"*************************"<<endl<<endl;
			playing = false;
		}
		if( Game::getInstance()->checkBlockedGame() ){
			cout<<"*************************"<<endl;
			cout<<"***** YOU ARE EVEN  *****"<<endl;
			cout<<"*************************"<<endl<<endl;
			playing = false;
		}

		// Starting new game
		if(playing == false){
			do{
				cout<<"Do you wanna play another game? Y|N";
				cin>>anotherGame;
			} while(anotherGame !='Y' && anotherGame !='N');

			if(anotherGame == 'Y'){
				Game::getInstance()->deinitializeBoard();
				Game::getInstance()->initializeBoard();
				playing = true;
				Game::getInstance()->printBoard();
			}
		}

		// change player turn
		playerName == 'O'? playerName = 'X' : playerName = 'O';

	}

	return 0;
}

//void printBoard(Cell* ptrMatrix[][3]){
//	for(int i=0; i<3; i++){
//		cout<<"\t";
//		for(int j=0; j<3; j++){
//			ptrMatrix[i][j]->print();
//		}
//		cout<<endl<<endl;
//	}
//}

//void deinitializeBoard(Cell* ptrMatrix[][3]){
//	for(int i=0; i<3; i++){
//		for(int j=0; j<3; j++){
//			delete ptrMatrix[i][j];
//		}
//	}
//}

//void initializeBoard(Cell* ptrMatrix[][3]){
//	for(int i=0; i<3; i++){
//		for(int j=0; j<3; j++){
//			ptrMatrix[i][j] = new Cell( '0'+(3*i+j) );
//		}
//	}
//}

//bool checkBlockedGame(Cell* ptrMatrix[][3]){
//
//	for(int i=0; i<3; ++i){
//		for(int j=0; j<3; ++j){
//			char p = ptrMatrix[i][j]->getValue();
//			if(p != 'X' && p != 'O')
//				return false;
//		}
//	}
//	return true;
//
//}

//bool checkWinner(Cell* ptrMatrix[][3], char player){
//
//	//by raw
//	for(int i=0; i<3; ++i){
//		for(int j=0; j<3; ++j){
//			if(ptrMatrix[i][j]->getValue() != player)
//				break;
//			else if(j==2)
//				return true;
//		}
//	}
//
//	//by column
//	for(int i=0; i<3; ++i){
//		for(int j=0; j<3; ++j){
//			if(ptrMatrix[j][i]->getValue() != player)
//				break;
//			else if(j==2)
//				return true;
//		}
//	}
//
//	//cross
//	for(int i=0; i<3; ++i){
//		if(ptrMatrix[i][i]->getValue() != player)
//			break;
//		else if(i==2)
//			return true;
//	}
//	for(int i=0; i<3; ++i){
//		if(ptrMatrix[i][2-i]->getValue() != player)
//			break;
//		else if(i==2)
//			return true;
//	}
//
//	return false;
//}
