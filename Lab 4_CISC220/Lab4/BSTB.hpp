#ifndef BSTB_HPP_
#define BSTB_HPP_
/*BSTB.hpp
 *  Created on: Nov 7, 2016
 *  	LAB 4
 *      Author: Eric Allen, John Pae, Lab 041, TA: Leighanne Hsu */

#include <iostream>
#include <stdlib.h>
#include "NodeTB.hpp"

using namespace std;

class BSTB{
	NodeTB* root; //top of AVL tree
	int count; //number of node words in AVL tree
	int countright;

public:
	BSTB();
	~BSTB();
	bool insert(string word); //inserts a new node word into the tree
	bool insert(string word, NodeTB* top);
	bool search(string word); //searches for a word in a tree, returns TRUE if found
	bool search(NodeTB* top, string word);
	int setHeights(NodeTB* root);
	NodeTB* getRoot();
	void searchTreeio(NodeTB* root);
	//PRINTS
	void printTreeio(); //prints out data in tree alphabetically
	void printTreeio(NodeTB* top);
	void printTreePre(); // for testing purposes, prints out tree in preorder
	void printTreePre(NodeTB *n);
	void printTreePost(); // for testing purposes, prints out tree in postorder
	void printTreePost(NodeTB *n);

	void adjustBalances(NodeTB* top); //rebalances tree
	NodeTB* rotateRight(NodeTB* top);
	NodeTB* rotateLeft(NodeTB* top);
	int getScore(NodeTB* root, BSTB* dict); //returns number of words in tree, and a set dictionary
};



#endif /* BSTB_HPP_ */
