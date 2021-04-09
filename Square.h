#ifndef __SQUARE
#define __SQUARE
#pragma once
#include"Player.h"
#include<string>
using namespace std;
class Square {
protected:
	string squareName;
	int type;

public:
	Square() {
		squareName="";
		type=0;
	};
	~Square() {};
	//geters
	string getSquareName() { return squareName; };
	int getType() { return type; };
	//seters
	void setSquareName(string inputName) { squareName = inputName; };
	void setType(int inputNum) { type = inputNum;};
	//virtual functions 

	//the act functions have the player addrese so the can be chaged internaly 
	virtual void act(Player &player, Player &player2) {}
	virtual void act(Player &player) {}


	//virtuals setters and geters for properrtys and airports
	virtual int getPropertyCost() { return 0; };
	virtual int getRent() { return 0; };
	virtual int getGroup() { return 0; };
	virtual bool getOwned() { return false; };
	virtual int getGroupPosition() { return 0; };
	
	virtual void setPropertyCost(int inputNum) {};
	virtual void setRent(int inputNum) {};
	virtual void setGroup(int inputNum) {};
	virtual void setOwned(bool inputBool) {};
	virtual void setGroupPosition(int inputNum) {};
};

#endif