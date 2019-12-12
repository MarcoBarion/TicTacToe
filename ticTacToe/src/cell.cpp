/*
 * cell.cpp
 *
 *  Created on: Dec 10, 2019
 *      Author: marcobarion
 */

#include "cell.hpp"

Cell::Cell(){}
Cell::Cell(char val){
	value = val;
}
char Cell::getValue(){
	return value;
}
void Cell::print(){
	cout<<value<<"  ";
}
Cell::~Cell(){
	cout<< "Destructor of Cell" << std::endl;
}
