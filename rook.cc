#include <string>
#include "rook.h"

using namespace std;

Rook::Rook(string role, string posn, string color, bool firstmove):
	Square(role), posn(posn), color(color), firstmove(firstmove) {}

string Rook::getcolor() {
        return this->color;
}

bool Rook::getPromote() {
	return true;
}

bool Rook::legalmove(std::string dest) {
	char x1 = posn[0];
        int y1 = stoi(posn.substr(1,1));


        char x2 = dest[0];
        int y2 = stoi(dest.substr(1,1));

	if ((x2 == x1) && (1 <= y2) && (y2 <= 8)) {firstmove = false; return true;}
	if ((y2 == y1) && (97 <= x2) && (x2 <= 104)) {firstmove = false; return true;}

	return false;
}

vector<std::string> Rook::getattack() {return attack;}

void Rook::setattack() {
	char x = posn[0]; //static cast
        int y = stoi(posn.substr(1,1));
	char c = 96;

        attack.clear(); // empty the attack vector

	for (int i = 1; i < 9; ++i) {
		if (i == y) continue; // skip the posn that rook is currently at
		attack.push_back(x + to_string(i));
	}

	for (int i = 1; i < 9; ++i) {
		c = int(c) + 1;
		if (int(c) == int(x)) continue;
		attack.push_back(c + to_string(y));
	}
}	

bool Rook::firstMove() {return firstmove;}

//bool Rook::castling() {return false;}

void Rook::setPosn(string newPosn) {
        posn = newPosn;
}


