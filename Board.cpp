#include "stdafx.h"
#include "Board.h"
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
//number of each type
int RED = 0;
int GREY = 0;
int BROWN = 0;
int ORANGE = 0;
int YELLOW = 0;
int GREEN = 0;
int BLUE = 0;
int PURPLE = 0;
int AIRPORT = 0;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string part;

	while (getline(ss, part, delimiter)) {//splits the string stream to the delimiter
		internal.push_back(part);
	}

	return internal;
}
void setBoard(vector<Square*>*square,string file) {
	string line;
	string content;
	ifstream myFile(file);
	if (myFile.is_open()) {
		int loc = 0;//i index
		while (getline(myFile, line)) {
			if (line[0] == '1') {//if property
				Property* p = new Property();//new peoperty type
				square->push_back(p);
				vector<string> sep = split(line, ' ');//split
				square->at(loc)->setType(stoi(sep[0]));//sets the values
				square->at(loc)->setSquareName(sep[1] +' '+ sep[2]);
				square->at(loc)->setPropertyCost(stoi(sep[3]));
				square->at(loc)->setRent(stoi(sep[4]));
				square->at(loc)->setGroup(stoi(sep[5]));
				switch (square->at(loc)->getGroup())//checks for groups and adds the position to the group each prperty is in
				{
				case 0:
					square->at(loc)->setGroupPosition(RED);
					RED ++;
					break;
				case 1:
					square->at(loc)->setGroupPosition(GREY);
					GREY++;
					break;
				case 2:
					square->at(loc)->setGroupPosition(BROWN);
					BROWN++;
					break;
				case 3:
					square->at(loc)->setGroupPosition(ORANGE);
					ORANGE++;
					break;
				case 4:
					square->at(loc)->setGroupPosition(YELLOW);
					YELLOW++;
					break;
				case 5:
					square->at(loc)->setGroupPosition(GREEN);
					GREEN++;
					break;
				case 6:
					square->at(loc)->setGroupPosition(BLUE);
					BLUE++;
					break;
				case 7:
					square->at(loc)->setGroupPosition(PURPLE);
					PURPLE++;
					break;

				}
				

			}
			else if (line[0]== '3'){//if airport reads all and set the name and the position
				Airport* a = new Airport();
				square->push_back(a);
				square->at(loc)->setType(line[0] - '0');
				for (int i = 2; i < line.length(); i++) {
					content += line[i];
					if (line[i + 1] == '\0') {
						square->at(loc)->setSquareName(content);
						content = "";

					}
				}
				square->at(loc)->setGroupPosition(AIRPORT);
				AIRPORT++;
			}else {//evrything else is a special squares whith a unique type 
				Special* s = new Special();
				square->push_back(s);
				square->at(loc)->setType(line[0]-'0');
				for (int i = 2; i < line.length(); i++) {
					content += line[i];
					if (line[i + 1] == '\0') {
						square->at(loc)->setSquareName(content);
						content = "";

					}
				}
			}
			loc++;
		}
		if (line != "") {
			myFile.close();
		}
		else {//empty monopoly file
			myFile.close();
			cout << "Your import file \"Monopoly.txt\" is empty ";
			system("PAUSE");
			exit(1);
		}

	}
	else {
		myFile.close();
		cout << "Unable to open the import file check:" << endl << "	1: not named \"Monopoly.txt\"" << endl
			<< "	2: Not placed in the corect folder" << endl;
		system("PAUSE");
		exit(1);
	}
}

Board::Board(){	
	setBoard(square,"Monopoly.txt");// calss the set board function to set up the board 

}


Board::~Board(){
}
