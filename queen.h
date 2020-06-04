#ifndef _QUEEN_H_
#define _QUEEN_H_

#include "square.h"
#include <vector>
#include <string>

class Queen:public Square {
	std::string color;
	std::string posn;
	std::vector<std::string> attack;
public:
	Queen(std::string role, std::string posn, std::string color);
	bool legalmove(std::string endPos)override;
	std::vector<std::string> getattack()override;
	void setattack()override;
	std::string getcolor()override;
	void setPosn(std::string des) override;
	bool firstMove()override;
	bool getPromote()override;
};

#endif
