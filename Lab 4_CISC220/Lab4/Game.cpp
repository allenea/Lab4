/*
 * Game.cpp
 *
 *  Created on: Nov 7, 2016
 *  	LAB 4
 *      Author: Eric Allen, John Pae, Lab 041, TA: Leighanne Hsu */
#include <iostream>
#include <stdlib.h>
#include "NodeTB.hpp"
#include "BSTB.hpp"
#include "Game.hpp"
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Game::Game() {
	readTreeFromFile("testdict.txt");
} //game
Game::Game(string infile) {
	readTreeFromFile(infile);
	numletters = 0;
	totalscore =0;
	numright = 0; // the count of the number of words in the dict tree
	totalwords = 0;  // the count of the total number of words generated
	currletters = NULL; //the random set of letters;
} //game

void Game::startGame() {
	/* startGame(): this is the user interface part – it asks how many letters the user wants,
	 *  reads that number in, prints out the set of random letters (including at least one vowel,
	 *  and then tells the user to start typing in words.
	 *
	 *  Each word typed in is added to the wordlist
	 *  (the linked list).  When the user enters -1,(see note at bottom about a timer) the function then
	 *  calculates the user’s total score by calling a function that first checks to make sure that each
	 *   word only includes letters in the set of random letters and then checks to see if each word in the
	 *   list is in the AVL tree.  It then prints out the list of valid words and the user’s score.
	 *   This function loops until the user no longer wants to play again.
	 */
	cout << "How Many Letters Do You Want?" << endl;
	cin >> numletters;
	currletters = getLetters(numletters);
	cout << "testing getting letters... currletters" << endl;
	cout << currletters << endl;
	getWords();
	//print out random set of letters
	checkWordsForScore();
	cout << "List of Entered Words::" << endl;
	wordlist->printTreeio();
	cout << "Score:    " << totalscore << endl;

} //startGame

void Game::readTreeFromFile(string dictfile) {
	dict = new BSTB();
	ifstream file(dictfile.c_str());  // converts a string to a character array
	string word;
	while (!file.eof()) {  // checks for end of file
		file >> word;
		if (!file.eof()) {
			dict->insert(word);
		}  //if
	}  //while
	cout << "IN ORDER::::::   " << endl;
	dict->printTreeio();
	//cout << "PreTest::::::   " << endl;
	//dict->printTreePre();
	//cout << "PostTest:::::::  " << endl;
	//dict->printTreePost();
	return;
}  //readTreeFromFile

char* Game::getLetters(int x) {
	srand(time(NULL));
	/* getLetters(): this method (called by the startGame method) gets a set of x random letters
	 and returns it.
	 */
	//Make first letter a vowel and then every letter after that random. bc you must have 1 vowel.
	char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
	char letters[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
			'y', 'z' };

	int vow = rand() % 5;
	//int con = rand()% 26 + 1;
	//cout<< vowels[vow]<<endl;
	currletters = new char[x];
	currletters[0] = vowels[vow];
	//cout<<"ghjkl";
	for (int i = 1; i < x; i++) {
		int con = rand() % 26;
		//cout<<letters[con]<<endl;
		currletters[i] = letters[con];
		//cerr<<"goes in";

	}	//for
	return currletters;
}	//getLetters

void Game::getWords() {
	/* getWords():this method (called by the startGame method) loops while the user enters potential words.
	 Each word gets added to the wordlist tree.
	 */
	string word;
	wordlist = new BSTB();
	cout << "What Word Do You Want To Play? or Enter -1 to exit" << endl;
	while (true) {
		cin >> word;
		if (word == "-1") {
			cout << "Exit Guessing Game, You Entered -1" << endl;
			return;
		}	//if
			//added this later to only add words that are allowed.
		if (checkWLetters(word) == true) {
			//cout<< word <<"added to list"<<endl;
			wordlist->insert(word); // add to wordlist BSTB
			totalwords++;
		} //if
		else {
			cout << "You Used Letters Not Available To You" << endl;
			return;
		} //else
	} //while
} //getWords

bool Game::checkWLetters(string s) {
	/* checkWLetters(): checks to see if s only contains letters in currletters (the random set of letters)
	 *  and returns true if s only contains valid letters, false otherwise
	 */
	int *fakeArr = new int[numletters];
	for (int i = 0; i < numletters; i++) {
		fakeArr[i] = 0;
	}//for
	bool boolean = false;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < numletters; j++) {
			if (s[i] == currletters[j] && fakeArr[j] != 1) {
				boolean = true;
				fakeArr[j] = 1;
				break;
			} //if
			else {
				boolean = false;
			}//else
		} //for j
		cout << s[i];
	} //for i
	return boolean;
} //checkWletters

void Game::checkWordsForScore() {
	/* checkWordsForScore(): gets the count of the number of words typed in that are in the dictionary,
	 * and then calculates the total score
	 */
//HOW MANY YOU GUESS TOTAL...
	cout<<totalwords<<endl;
	int penalty = 0;
	int prize = 0;
 /// THE PROBLEM IS IT ONLY LOOKS AT FIRST WORD AND ASSUMES THE REST GET SAME SCORING.
	numright = wordlist->getScore(wordlist->getRoot(), dict);
	cout<<numright<<endl;
	int numwrong = totalwords - numright;
	cout<<"nunwrong"<<numwrong<<endl;

	for(int i = 0;i!=numwrong;i++){
		penalty -= 6;
	}
	cout<<"penalty"<<penalty<<endl;
	for(int j=0; j!=numright; j++){
		prize +=3;
	}
	cout<<"prize"<<prize<<endl;


	totalscore = penalty + prize;
	cout<<totalscore<<endl;


	/*
	int penalty = 0;
	int winscore = 0;
	for(int i = 0; i < totalwords;i++){

		//right = wordlist->getScore(wordlist->getRoot(), dict);
		cout<<"post"<<right<<endl;
		if(wordlist->getScore(wordlist->getRoot(), dict) >= 0){
			//cout<<numright<<endl;
			winscore = winscore + 3 ;
		}
		cout<<"winscore::"  << winscore<<endl;
		if(wordlist->getScore(wordlist->getRoot(), dict) == -1){
			penalty = penalty - 6;
		}
		//penalty += penalty;
		cout<<"PENALTY::"  <<penalty<<endl;
		//totalWrong = totalwords-numright;
	}
	cout <<"totalscore::"  << totalscore << endl;
	totalscore = penalty + winscore;
	*/

} //checkWordsForScore()





