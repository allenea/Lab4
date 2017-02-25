/*
 * BSTB.cpp
 *
 *  Created on: Nov 7, 2016
 *  	LAB 4
 *      Author: Eric Allen, John Pae, Lab 041, TA: Leighanne Hsu */


#include <iostream>
#include <stdlib.h>
#include "BSTB.hpp"
#include "NodeTB.hpp"
using namespace std;

BSTB::BSTB(){
	root = NULL;
	count = 0;
	countright = 0; // counts num right


}//end

BSTB::~BSTB() {
	if (root->left == NULL && root->right == NULL) {
		root->~NodeTB();
		return;
	} else { //if the node has children
		if (root->left != NULL) {
			root->left = NULL;
		} //the node has a left child
		if (root->right != NULL) {
			root->right = NULL;
		} //the node has a right child
	} //else
}//BSTB
bool BSTB::insert(string word){
	bool inserted;
	if (root == NULL){
		root = new NodeTB(word);
		count++;
		inserted = true;
	}//if
	else{
	inserted = insert(word, root);//begin recursion at Root
	//cerr<<"insert AB";
	adjustBalances(root);
	}//else
	return inserted;
}//end

bool BSTB::insert(string word, NodeTB* root){
	bool inserted;
	if(root == NULL || word == root->getWord()){
		inserted = false;
	}//if
	if (word < root->getWord()){
		if (root->left != NULL){
			inserted = insert(word, root->left);
		}//if
		else{
			NodeTB* node = new NodeTB(word);
			root->left = node;
			count++;
			inserted = true;
		}//else
	}//insert
	else if (word > root->getWord()){
		if (root->right != NULL){
			return insert(word, root->right);
		}//if
		else{
			NodeTB* node = new NodeTB(word);
			root->right = node;
			count++;
			inserted = true;
		}//else
	}//elseif
	return inserted;
}//insert
void BSTB :: printTreeio(){
	return printTreeio(root);//start recursion at Root
}//end

void BSTB :: printTreeio(NodeTB* root){
	if (root->left != NULL){//print the left child (alphabetically less)
		printTreeio(root->left);
	}//if
	cout <<root->getWord()<< endl;//print root
	if (root->right != NULL){
		printTreeio(root->right);//print the left child (alphabetically more)
	}//if
	return;
}//end

void BSTB::searchTreeio(NodeTB* root){

	if (root->left != NULL){//print the left child (alphabetically less)
		searchTreeio(root->left);
	}//if
	//cout <<root->getWord()<< endl;//print root
	if (root->right != NULL){
		searchTreeio(root->right);//print the left child (alphabetically more)
	}//if
	if(search(root->getWord()) == true){
		countright++;

	}//if
	cout<<countright<<endl;
}//end

bool BSTB :: search(string word){
	bool found = search(root, word);//start recursion at Root
	return found;
}//end

bool BSTB::search(NodeTB* root, string word){
	bool found = false;//set default, the word has not been found yet
	if(root == NULL){
		return found;
	}//if
	if (root->getWord() == word){//if found
		found = true;
	}else{//if not found
		if (word < root->getWord()){//search to the left of root
			found = search(root->left, word);
		}//if
		else if (word > root->getWord()){//search to the right of oot
			found = search(root->right, word);
		}//elseif
	}//else
	return found;
}//end

int BSTB::setHeights(NodeTB* root){
	if (root == NULL){
		root->balance = 0;
		return 0;
	}//if
	else{
		root->balance = max(setHeights(root->left), setHeights(root->right)) + 1;
		return root->balance;
	}//else
}//setHeights

void BSTB :: adjustBalances(NodeTB* root){



	///////
	/*
	if (root == NULL){
		root->balance = 0;
	}

	if(root->right->balance - root->left->balance > 1){
		if(root->left->balance > 0){
			rotateLeft(root);
		}
		else{
			NodeTB *tmp;
			tmp= root->right;
			root->right = rotateLeft(tmp);
			root= rotateRight(root);

		}
	}
	else if(root->right->balance - root->left->balance < -1){

		if(root->right->balance <= 0){
			rotateRight(root);
		}
		else{
			NodeTB *tmp;
			tmp= root->left;
			root->left = rotateLeft(tmp);
			root= rotateRight(root);
		}
	}
	else{
		return;
	}
	cerr<<"inbetween";
	*/
}//end


NodeTB* BSTB::rotateRight(NodeTB* root) {
	//if (root->left->getBal() < 0){//if the two signs are not aligned
	//	root->left = rotateLeft(root->left);
	//}//if
	//rotation
	NodeTB *x = root->left;
	NodeTB *tmp = x->right;

	// Perform rotation
	x->right = root;
	root->left = tmp;

	// Update heights
	if (root->left->balance > root->right->balance) { //why did we look at y first?
		root->balance = root->left->balance + 1;
	} //if
	else {
		root->balance = root->right->balance + 1;
	}//else
	if (x->left->balance > x->right->balance) {
		x->balance = x->left->balance + 1;
	}//if
	else {
		x->balance = x->right->balance + 1;
	}//else
	return x; // Return new root
}//rotateright


NodeTB* BSTB::rotateLeft(NodeTB* root) {

	NodeTB *x = root->right;
	NodeTB *tmp = x->left;

	// Perform rotation
	x->left = root;
	root->right = tmp;

	// Update heights
	if (root->left->balance > root->right->balance) {  //why did we look at y first?
			root->balance = root->left->balance + 1;
	}//if
	else {
			root->balance =root->right->balance + 1;
	}//else
	if (x->left->balance > x->right->balance) {
			x->balance = x->left->balance + 1;
	}//if
	else {
			x->balance = x->right->balance + 1;
	}//else
	return x; // Return new root
}//rotateleft

//testing print methods
void BSTB :: printTreePre(){
	return printTreePre(root);
}//printTreePre

void BSTB :: printTreePre(NodeTB* root){
	if (root == NULL){
		return;
	}//if
	else{
		cout<<root->word<<endl;
		printTreePre(root->left);
		printTreePre(root->right);
	}//else
}//printTreePre

void BSTB :: printTreePost(){
	return printTreePost(root);
}//printTreePost()

void BSTB :: printTreePost(NodeTB* root){
	if (root == NULL){
		return;
	}//if
	else{
		printTreePost(root->left);
		printTreePost(root->right);
		cout<<root->word<<endl;
	}//else
}//printTreePost

int BSTB::getScore(NodeTB* root, BSTB* dict){
	//COUNT RIGHT
	string word = root->getWord();
	//int score = 0;
	if(root != NULL){
		if (dict->search(word) == true){//if word is in dict
			countright++;
			//score = score + 3;
			//return score;
		}//if

		else{
			//score = score - 6;
			//return score]];
			countright = 0;
		}//else
		//score= score + getScore(root->left, dict) + getScore(root->right, dict);//if node has two children
		//return score;
	}
	if (root == NULL){
		//score = 0;
		//return score;
		return 0;
	}//if
	cout<<"Game CR"<<countright<<endl;
	return countright;
}//end

NodeTB* BSTB::getRoot(){
	return root;
}//getRoot
