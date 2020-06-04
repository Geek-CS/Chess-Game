#ifndef _PAWN_H_
#define _PAWN_H_

#include "square.h"


class Pawn: public Square {
	bool firstmove;
	std::string posn;
	std::string color;
	std::vector<std::string> attack;
	bool promote;
public:
	Pawn(std::string role, std::string posn, std::string color, bool firstmove);
	bool legalmove(std::string dest) override;
	void setattack() override;
	bool firstMove()override;
	std::vector<std::string> getattack() override;
//	bool enpassent();
	void setPosn(std::string newPosn) override;
	std::string getcolor()override;
	bool getPromote()override;

};

#endif

