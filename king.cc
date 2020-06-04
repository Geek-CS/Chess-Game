#include "king.h"

using namespace std;

King::King(string role, string posn, string color, bool firstmove):
	Square(role), posn(posn), color(color), firstmove(firstmove) {}

string King::getcolor() {
	return this->color;
}

bool King::getPromote() {
	return true;
}

bool King::legalmove(std::string dest) {
	char x1 = posn[0];
        int y1 = stoi(posn.substr(1,1));


        char x2 = dest[0];
        int y2 = stoi(dest.substr(1,1));
	
	if ((x2 == x1) && (y2 == y1)) return false;

        if ((abs(y2 - y1) <= 1) && (abs(int(x2) - int(x1)) <= 1) &&
                        (1 <= y2) && (y2 <= 8) && (97 <= x2) &&(x2 <= 104)) {firstmove = false; return true;}

	return false;
}


vector<string> King::getattack() {return attack;}

void King::setattack() {
	char x = posn[0]; //static cast
        int y = stoi(posn.substr(1,1));
        char c = x;

	attack.clear();

	if (y + 1 <= 8) attack.push_back(x + to_string(y+1));
	if (y - 1 >= 1) attack.push_back(x + to_string(y-1));


	c = int(c) + 1;
	if (int(c) <= 104) { // check right boundry
		if (y - 1 >= 1) attack.push_back(c + to_string(y-1));
		attack.push_back(c + to_string(y));
		if (y + 1 <= 8) attack.push_back(c + to_string(y+1));
	}

	c = x;
	c = int(c) - 1;
	if (int(c) >= 97) {// check left boundry
		if (y - 1 >= 1) attack.push_back(c + to_string(y-1));
		attack.push_back(c + to_string(y));
		if (y + 1 <= 8) attack.push_back(c + to_string(y+1));
	}

}


//bool inCheck();
        
//bool checkMate();
        
bool King::firstMove() {return firstmove;}

//bool King::castling() {return firstmove;}

void King::setPosn(string newPosn) {
        posn = newPosn;
}


