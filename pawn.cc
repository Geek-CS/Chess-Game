#include <string>
#include "pawn.h"

using namespace std;

Pawn::Pawn(string role, string posn, string color, bool firstmove): 
	Square(role), posn(posn), color(color), firstmove(firstmove) {
		if ((color == "white") && (stoi(posn.substr(1,1)) == 8)) promote = true;
        	else if ((color == "black") && (stoi(posn.substr(1,1)) == 1)) promote = true;
		else promote = false;
	}

std::string Pawn::getcolor() {
	return color;
}

bool Pawn::legalmove(string dest) {
	char x1 = posn[0];
	int y1 = stoi(posn.substr(1,1));
	

	char x2 = dest[0];
	int y2 = stoi(dest.substr(1,1));

	for (auto s : attack) {
		if (dest == s) {return true;} //move is an attack
	}

	if (firstmove == true) { 
		if ((color == "black") && (x2 == x1) && (y2 == y1 - 2)) {firstmove = false; return true;}
		if ((color == "white") && (x2 == x1) && (y2 == y1 + 2)) {firstmove = false; return true;}
	}

	if ((color == "black") && (x2 == x1) && (y2 == y1 - 1)) {return true;}
	if ((color == "white") && (x2 == x1) && (y2 == y1 + 1)) {return true;}

	return false;

}

void Pawn::setattack() {
	char x = posn[0]; //static cast
	int y = stoi(posn.substr(1,1));

	attack.clear(); // empty the attack vector

	if (color == "black") {
		if (y == 1) return;
		if (int(x) == 97) { // if pawn is already on the left edge
			x = int(x) + 1;
			--y;
			attack.push_back(x+to_string(y));
		} else if (int(x) == 104) { // right edge
			x = int(x) - 1;
			--y;
			attack.push_back(x+to_string(y));
		} else {
			x = int(x) + 1;
			--y;
			attack.push_back(x + to_string(y));
			x = int(x) - 2;
			attack.push_back(x + to_string(y));
		}
	} else if (color == "white") {
		if (y == 8) return;
		if (int(x) == 97) {
			x = int(x) + 1;
			++y;
			attack.push_back(x+to_string(y));
		} else if (int(x) == 104) {
			x = int(x) - 1;
			++y;
			attack.push_back(x+to_string(y));
		} else {
			x = int(x) + 1;
			++y;
			attack.push_back(x+to_string(y));
			x = int(x) - 2;
			attack.push_back(x+to_string(y));
		}
	}

}

vector<std::string> Pawn::getattack(){ return attack; }

bool Pawn::firstMove() { return firstmove; }

//bool Pawn::enpassent() {return false;} //???

void Pawn::setPosn(string newPosn) {
        posn = newPosn;

	if ((color == "white") && (stoi(posn.substr(1,1)) == 8)) promote = true;
	if ((color == "black") && (stoi(posn.substr(1,1)) == 1)) promote = true;

}

bool Pawn::getPromote() {return promote;}


