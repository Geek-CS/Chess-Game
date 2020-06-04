#include "bishop.h"
#include <cstdlib>

using namespace std;

Bishop::Bishop(string role, string posn, string color):
	Square(role), posn(posn), color(color) {}

string Bishop::getcolor() {
        return this->color;
}

bool Bishop::firstMove() {
	return true;
}

bool Bishop::getPromote() {
	return true;
}

bool Bishop::legalmove(std::string dest) {
	char x1 = posn[0];
        int y1 = stoi(posn.substr(1,1));


        char x2 = dest[0];
        int y2 = stoi(dest.substr(1,1));
	
	if ((abs(y2 - y1) == abs(int(x2) - int(x1))) &&
		(1 <= y2) && (y2 <= 8) &&
		(97 <= x2) && (x2 <= 104)) return true;

	return false;
}

vector<string> Bishop::getattack() {return attack;}

void Bishop::setattack() {
	char x = posn[0]; //static cast
        int y = stoi(posn.substr(1,1));
	char c = x;
	attack.clear();
	
	for (int i = 1; i < 9; ++i) {
		c = int(c) + 1;
		if (c > 104) break; // x pass h
		if (y + i <= 8) attack.push_back(c + to_string(y+i));
		if (y - i >= 1) attack.push_back(c + to_string(y-i));
	}

	c = x;

	for (int i = 1; i < 9; ++i) {
		c = int(c) - 1;
		if (c < 97) break; // x pass a
		if (y + i <= 8) attack.push_back(c + to_string(y+i));
		if (y - i >= 1) attack.push_back(c + to_string(y-i));
	}
}

void Bishop::setPosn(string newPosn) {
	posn = newPosn;
}

