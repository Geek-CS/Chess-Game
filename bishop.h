#ifndef _BISHOP_H_
#define _BISHOP_H_

#include "square.h"
#include <vector>
#include <string>

class Bishop: public Square {
	std::string color;
	std::string posn;
	std::vector<std::string> attack;
public:
	Bishop(std::string role, std::string posn, std::string color);
	bool legalmove(std::string endPos)override;
	std::vector<std::string> getattack()override;
	void setattack()override;
	std::string getcolor()override;
	void setPosn(std::string des) override;
	bool getPromote()override;
	bool firstMove()override;
};

#endif
