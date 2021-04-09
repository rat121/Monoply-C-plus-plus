#ifndef __AIRPORT
#define __AIRPORT
#pragma once 
#include "Square.h"
class Airport:public Square{
	private:
		int airpotCost;
		int rent;
		bool owned;
		int group;
		int groupPosition;

	public:
		Airport() {//airport has defult values
			airpotCost = 200;
			rent = 10;
			owned = false;
			group = 8;
			groupPosition;
		};
		~Airport() {};

		void act(Player &player, Player &player2)override{//action taken 
		cout << player.getPlayerName() << " has landed on "<< squareName << endl;
		if (owned == false) {//if the airport is not owned
			if (player.getBalance() > 0) {
				owned = true;
				player.lose_money(rent);//loses money to buy the airport
				player.change_ownership_state(group, groupPosition);//get's the ownership
				cout << player.getPlayerName() << " buys " << squareName << " for " << POUND << airpotCost << endl;
			}
		}
		else if (player.bReturn_ownership_state(group, groupPosition) == false) {//above is if the airport is owned and if the curent player not owns it (enemy player owns)
			if (player2.check_own_group(group)) {//if the airport is fully owned the rent cost is doublue
				player.lose_money(rent * 2);//player 1 loses the money
				player2.gain_money(rent * 2);//player 2 get the money
				cout << player.getPlayerName() << " pays " << rent * 2 << endl;
			}
			else {//normal rent
				player.lose_money(rent);//player 1 loses the money
				player2.gain_money(rent);//player 2 get the money
				cout << player.getPlayerName() << " pays " << rent << endl;
			}
		}
	};
	int getPropertyCost()override {return airpotCost;};
	int getRent()override {return rent; };
	bool getOwned()override { return owned; };
	int getGroup()override { return group; };
	int getGroupPosition()override { return groupPosition; };
	

	void setPropertyCost(int inputNum)override { airpotCost = inputNum;};
	void setRent(int inputNum)override {rent = inputNum;};
	void setOwned(bool inputBool)override { owned = inputBool; };
	void setGroup(int inputNum)override { group = inputNum; };
	void setGroupPosition(int inputNum)override { groupPosition = inputNum ; };
	};

#endif 


