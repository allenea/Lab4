/*
 * Main.cpp
 *
 *  Created on: Nov 7, 2016
 *  	LAB 4
 *      Author: Eric Allen, John Pae, Lab 041, TA: Leighanne Hsu */

#include <stdio.h>
#include <iostream>
#include "NodeTB.hpp"
#include "Game.hpp"
#include "BSTB.hpp"
using namespace std;


int main(){
	cout<<"testing BSTB..."<<endl;
	BSTB test = BSTB();
	cout<<"test, created"<<endl;
	test.insert("this");
	test.insert("is");
	test.insert("another");
	test.insert("test");
	test.insert("program");
	cout<<"printing..."<<endl;
	test.printTreeio();
	test.search("another");
	test.search("hello");
	//1 means TRUE
	cout<<test.search("another")<<endl;
	//0 means FALSE
	cout<<test.search("hello")<<endl;
	Game gtest = Game();
	gtest.readTreeFromFile("testdict.txt");
	gtest.startGame();



	//Game();
	return 0;
}//end main



