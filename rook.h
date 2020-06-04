#ifndef _ROOK_H_
#define _ROOK_H_

#include "square.h"
#include <vector>
#include <string>

class Rook: public Square {
	std::string posn;
	std::string color;
	bool firstmove;
	std::vector<std::string> attack;
public:
	Rook(std::string role, std::string posn, std::string color, bool firstmove);
	bool legalmove(std::string endPos)override;
	std::vector<std::string> getattack()override;
	void setattack()override;
	void setPosn(std::string des) override;
	bool firstMove()override;
	bool getPromote()override;
	std::string getcolor()override;
};

#endif
