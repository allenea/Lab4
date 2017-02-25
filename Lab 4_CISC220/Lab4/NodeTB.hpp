/*
 * NodeTB.hpp
 *
 *  Created on: Nov 7, 2016
 *  	LAB 4
 *      Author: Eric Allen, John Pae, Lab 041, TA: Leighanne Hsu */

#ifndef NODETB_HPP_
#define NODETB_HPP_

#include <iostream>
#include <stdlib.h>
using namespace std;
//#include "BSTB.HPP"

class NodeTB {
	friend class BSTB;
	friend class Game;
	string word;
	int balance;
	//POINTERS
	NodeTB* left;
	NodeTB* right;
	NodeTB* parent;

public:
	//CONSTRUCTORS & DESTRUCTORS
	NodeTB(string f);
	~NodeTB();
	//GETTERS
	string getWord();


};

#endif /* NODETB_HPP_ */
