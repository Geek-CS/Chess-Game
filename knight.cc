#include "knight.h"

using namespace std;

Knight::Knight(string role, string posn, string color): 
	Square(role), posn(posn), color(color) {}

string Knight::getcolor() {
        return this->color;
}

bool Knight::getPromote() {
	return true;
}

bool Knight::firstMove() {
	return true;
}

bool Knight::legalmove(std::string dest) {
	char x1 = posn[0];
        int y1 = stoi(posn.substr(1,1));

        char x2 = dest[0];
        int y2 = stoi(dest.substr(1,1));

	if ((abs(y2 - y1) > 0) && (abs(int(x2) - int (x1)) > 0) &&
			(abs(y2-y1) + abs(int(x2)-int(x1)) == 3)) return true;
	return false;	
}
        
vector<string> Knight::getattack() {return attack;}

void Knight::setattack() {
	char x = posn[0]; //static cast
        int y = stoi(posn.substr(1,1));
        char c = int(x) - 2;
	
	attack.clear();
	
	if (c >= 97) {
		if (y + 1 <= 8) attack.push_back(c + to_string(y+1));
		if (y - 1 >= 1) attack.push_back(c + to_string(y-1));
	}

	c = int(x) - 1;
	if (c >= 97) {
                if (y + 2 <= 8) attack.push_back(c + to_string(y+2));
                if (y - 2 >= 1) attack.push_back(c + to_string(y-2));
        }
	
	c = int(x) + 1;
        if (c <= 104) {
                if (y + 2 <= 8) attack.push_back(c + to_string(y+2));
                if (y - 2 >= 1) attack.push_back(c + to_string(y-2));
        }

	c = int(x) + 2;
        if (c <= 104) {
                if (y + 1 <= 8) attack.push_back(c + to_string(y+1));
                if (y - 1 >= 1) attack.push_back(c + to_string(y-1));
        }
}

void Knight::setPosn(string newPosn) {
        posn = newPosn;
}


