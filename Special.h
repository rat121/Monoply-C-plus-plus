#ifndef __SPECIAL
#define __SPECIAL
#pragma once
#include "Square.h"
#include <string>
class Special :public Square
{
public:
	Special() :Square() {};
	~Special() {};
	
	void act(Player &player)override {//act
		string playerName = player.getPlayerName();
		switch (type){//square type represent what type of specila square
		case 7://go to jail
			player.move_to_jail();//mover to jail
			player.lose_money(50);//loses money
			cout << playerName << " lands on Go to Jail" << endl;
			cout << playerName << " goes to Jail" << endl;
			cout << playerName << " pays "<<POUND<< "50" << endl;
			break;
		case 6://jail
			cout << playerName << " lands on Jail" << endl;
			cout << playerName << " is just visiting" << endl;
			break;
		case 8: //free parking
			cout << playerName << " lands on Free Parking" << endl;
			cout << playerName << " is resting" << endl;
			break;
		case 2:// hit go
			player.gain_money(200);
			cout<<playerName<<" lands on GO and collects"<<POUND<<"200."<<endl;
			break;
		case 5://penalty 
			switch (Random()){//random penalty out of 6
				cout << playerName << " lands on Penalty" << endl;
			case 1:
				player.lose_money(20);
				cout << "Pay food bill.Player loses "<<POUND<<"20." << endl;
				break;
			case 2:
				player.lose_money(50);
				cout << "Pay phone bill.Player loses "<<POUND<<"50" << endl;
				break;
			case 3:
				player.lose_money(100);
				cout << "Pay heating bill.Player loses "<<POUND<<"100." << endl;
				break;
			case 4:
				player.lose_money(150);
				cout << "Pay vehicle tax.Player loses "<<POUND<<"150." << endl;
				break;
			case 5:
				player.lose_money(200);
				cout << "Pay fuel bill.Player loses "<< POUND<<"200." << endl;
				break;
			case 6:
				player.lose_money(300);
				cout << "Pay windfall tax.Player loses " << POUND<<"300" << endl;
				break;
			}
			break;
		case 4://bonus
			cout<< playerName<<"lands on Bonus"<<endl;
			switch (Random()) {//random bonus of 6
				cout << playerName << " lands on Penalty" << endl;
			case 1:
				player.gain_money(20);
				cout << "Find some money.Player gains " << POUND << "20." << endl;
				break;
			case 2:
				player.gain_money(50);
				cout << "Win competition.Player gains " << POUND << "50." << endl;
				break;
			case 3:
				player.gain_money(100);
				cout << "Tax rebate.Player gain " << POUND << "100." << endl;
				break;
			case 4:
				player.gain_money(150);
				cout << "Win lottery.Player gains " << POUND << "150." << endl;
				break;
			case 5:
				player.gain_money(200);
				cout << "Bequest.Player gains " << POUND << "200." << endl;
				break;
			case 6:
				player.gain_money(300);
				cout << "Birthday.Player gains " << POUND << "300." << endl;
				break;
			}
			break;
		}
	}
	
};

#endif