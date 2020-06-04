#include "queen.h"

using namespace std;

Queen::Queen(string role, string posn, string color):
	Square(role), posn(posn), color(color) {}

string Queen::getcolor() {
        return this->color;
}

bool Queen::firstMove(){
	return true;
}

bool Queen::getPromote() {
	return true;
}
bool Queen::legalmove(std::string dest) {
	char x1 = posn[0];
        int y1 = stoi(posn.substr(1,1));


        char x2 = dest[0];
        int y2 = stoi(dest.substr(1,1));

	if ((abs(y2 - y1) == abs(int(x2) - int(x1))) &&
                (1 <= y2) && (y2 <= 8) &&
                (97 <= x2) && (x2 <= 104)) return true;
	
	if ((x2 == x1) && (1 <= y2) && (y2 <= 8)) return true;
        if ((y2 == y1) && (97 <= x2) && (x2 <= 104)) return true;

	return false;
}

vector<string> Queen::getattack() {return attack;}

void Queen::setattack() {
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
	
	c = x;

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

void Queen::setPosn(string newPosn) {
        posn = newPosn;
}


