#ifndef __PLAYER
#define __PLAYER
#pragma once
#include"gFunctions.h"
#include <iostream>
#include <string>
#include <vector>
//states of ownership
#define NOTOWN 0
#define OWN 1
#define MORTGAGE 2
using namespace std;

class Player{

private:

	string playerName;
	int balance;
	int location;
	vector<vector<int>> groupOwns{ //vector of vector boolean   represeting the groups and ownership
		{ NOTOWN,NOTOWN },
		{ NOTOWN,NOTOWN },
		{ NOTOWN,NOTOWN },
		{ NOTOWN,NOTOWN,NOTOWN },
		{ NOTOWN,NOTOWN },
		{ NOTOWN,NOTOWN },
		{ NOTOWN,NOTOWN,NOTOWN },
		{ NOTOWN,NOTOWN },
		{ NOTOWN,NOTOWN },
	};

public:
	Player() {};
	~Player() {};
	Player(string name) {//player start and set name
		playerName = name;
		balance = 1500;
		location = 0;
		groupOwns;
	};
	
	string getPlayerName() { return playerName; };
	int getBalance() { return balance; };
	int getLocation() { return location; };

	void setPlayerName(string inputName) { playerName = inputName; };
	void setLocation(int inputNum) { location = inputNum; };
	void setBalance(int inputNum) { balance = inputNum; };

	void move_player(int rollLocation) {//moves the player and seting the range of movement
		if (location + rollLocation > 25) {
			balance += 200;
			cout<< playerName << " passes GO and collects "<<POUND <<"200"<<endl;
		}
		location=(location + rollLocation) % 25;
	};
	void lose_money(int cost) {
		balance -= cost;
	};

	void gain_money(int cost) {
		balance += cost;
	};
	void move_to_jail(){
		location = 6;
	}
	bool bReturn_ownership_state(int group, int position) {//find if the user owns the serched position
		return groupOwns[group][position] == OWN;
	};
	void change_ownership_state (int group,int position) {//sets the position that is given as owned
		groupOwns[group][position] = OWN;
	};
	bool check_own_group(int group) {//serches if the owner has all the propertys in a group*   *the group is a vector of bool
		for (auto i = groupOwns[group].begin(); i != groupOwns[group].end();i++ ) {
			if (*i == NOTOWN) {//if not own return false
				return false;
			}

		}
		return true;// if nothing got interupted the player has all the propertys in the group
	};
};

#endif 