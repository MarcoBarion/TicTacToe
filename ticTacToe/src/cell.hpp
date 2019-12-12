/*
 * cell.hpp
 *
 *  Created on: Dec 10, 2019
 *      Author: marcobarion
 */

#ifndef CELL_HPP_
#define CELL_HPP_

#include <iostream>
using namespace std;

class Cell{
	char value;

public:
	Cell();
	Cell(char val);

	char virtual getValue();
	void virtual print();
	virtual ~Cell();
};

#endif /* CELL_HPP_ */
