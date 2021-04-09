#ifndef __PROPERTY
#define __PROPERTY
#pragma once
#include "Square.h"
class Property :public Square{
private:
	int propertyCost;
	int rent;
	int group;
	bool owned;
	int groupPosition;


public:
	Property():Square() {//defult clas
		propertyCost = 0;
		rent = 0;
		group = 0;
		owned = false;
		
	};
	~Property() {};

	void act(Player &player, Player &player2)override{//action taken
		cout << player.getPlayerName() << " has landed on "<< squareName << endl;
		if (owned == false) {//if the property  is not owned
			if (player.getBalance() > 0) {
				owned = true;
				player.lose_money(propertyCost);//loses money to buy the property
				player.change_ownership_state(group, groupPosition);//get's the ownership
				cout << player.getPlayerName() << " buys " << squareName << " for " << POUND << propertyCost << endl;
			}
		}else if (player.bReturn_ownership_state(group,groupPosition) == false){//above is if the airport is owned and if the curent player not owns it (enemy player owns)
			if (player2.check_own_group(group)) {//if the group is fully owned the rent cost is doublue
				player.lose_money(rent*2);//player 1 loses the money
				player2.gain_money(rent*2);//player 2 get the money
				cout << player.getPlayerName() << " pays " << rent*2 << endl;
			}else {//noraml rent
				player.lose_money(rent);//player 1 loses the money
				player2.gain_money(rent);//player 2 get the money
				cout << player.getPlayerName() << " pays " << rent<< endl;
			}
		}
	};
	int getPropertyCost()override {return propertyCost;};
	int getRent()override {return rent; };
	int getGroup()override { return group; };
	bool getOwned()override { return owned; };
	int getGroupPosition()override { return groupPosition; };

	void setPropertyCost(int inputNum)override {propertyCost = inputNum;};
	void setRent(int inputNum)override {rent = inputNum;};
	void setGroup(int inputNum)override {group = inputNum;};
	void setOwned(bool inputBool)override { owned = inputBool; };
	void setGroupPosition(int inputNum)override { groupPosition = inputNum; };
};

#endif