// Monopoly.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <string>
#include <vector>
#include "Board.h"
#include<iostream>
using namespace std;

int ROUNDS = 1;
//file string
const string seedF = "seed.txt";
//file returns
int seed;


string getSeed(string File) {//reads the files and returns them as a string
	string line;
	string content;
	ifstream myFile(File);
	if (myFile.is_open()){
		while (getline(myFile, line)){
			content += line;
		}
		if (content != "") {
			myFile.close();
			return content;
		}else{//empty seed file
			myFile.close();
			cout << "Your seed files is empty ";
			system("PAUSE");
			exit(1);
		}
		
	}else {//unable to open seed file
		myFile.close();
		cout << "Unable to open one of the import files check:" << endl << "	1: not named \"seed.txt\"" << endl
			<< "	2: Not placed in the corect folder"<<endl;
		system("PAUSE");
		exit(1);
	}
}

int main(){
	//pre game set up
	//reading files
	seed = stoi(getSeed(seedF));//get's the integer value out of the returned string
	srand(static_cast<unsigned int> (seed));//sets the seed
	Board board;//cals the defult board constractor and creates the board
	int lastPlayer = 0;
	cout << "Welcome to Monopoly" << endl;
	while (ROUNDS <= 20) {//20 loop Let's play !!!
		for (int i = 0; i < 2; i++) {//2 players
		board.player_move(i);//cals the move function
		board.player_act(i,lastPlayer);//cals the act functions
		cout << endl;
		lastPlayer = i;//remebers the other player
		}


		ROUNDS++;//next round
	}
	


	system("PAUSE");
	return 0;
}

