/*
 * NodeTB.cpp
 *
 *  Created on: Nov 7, 2016
 *  	LAB 4
 *      Author: Eric Allen, John Pae, Lab 041, TA: Leighanne Hsu */
#include "NodeTB.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

NodeTB::NodeTB(string nword){
	word = nword;
	balance = 0;
	left = NULL;
	right = NULL;
	parent =NULL;
}

NodeTB::~NodeTB(){
	if (left != NULL || right != NULL){
		cout <<"WARNING: deconstruction may cause memory leak"<< endl;
	}
	left = NULL;
	right = NULL;
	word = "";
	//balance = NULL;
}
string NodeTB::getWord(){
	return word;
}


