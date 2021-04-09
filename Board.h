#ifndef __BOARD
#define __BOARD
#pragma once
#include "Property.h"
#include "Special.h"
#include "Player.h"
#include "Airport.h"
#include <vector>
#include "gFunctions.h"
using namespace std;


class Board{
protected:
	vector<Square*> *square= new vector<Square*>();//vector of square pointers
	Player players[2] = {Player("Dog"),Player("Car")};//players
public:
	Board();//in the cpp becose of size
	~Board();
	void player_move(int playerNum) {//player moves
		int roll = Random();//roll the "dice"
		cout << players[playerNum].getPlayerName() << " rolls " << roll << endl;
		players[playerNum].move_player(roll);
	};
	void player_act(int playerNum,int lastPlayer) {//player acting
		int curentSquareType = square->at(players[playerNum].getLocation())->getType();
		if (curentSquareType == 1 || curentSquareType == 3) {//if it is property or square
			square->at(players[playerNum].getLocation())->act(players[playerNum], players[lastPlayer]);
		}else{//if special square
			square->at(players[playerNum].getLocation())->act(players[playerNum]);
		}
			cout<< players[playerNum].getPlayerName() <<" has "<< POUND << players[playerNum].getBalance()<<endl;


	};
};

#endif