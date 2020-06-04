#ifndef _KING_H_
#define _KING_H_

#include "square.h"
#include <vector>
#include <string>

class King: public Square {
	std::string posn;
	std::string color;
	bool firstmove;
	std::vector<std::string> attack;
public:
	King(std::string role, std::string posn, std::string color, bool firstmove);
	bool legalmove(std::string endPos)override;
	std::vector<std::string> getattack()override;
	void setattack()override;
	void setPosn(std::string des) override;
	std::string getcolor()override;
	bool firstMove()override;
	bool getPromote()override;
}; 

#endif
