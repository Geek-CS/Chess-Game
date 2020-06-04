
#ifndef _SQUARE_H_
#define _SQUARE_H_

#include <string>
#include <vector>
class Square {
	std::string role;
public:
	Square(std::string role);
        virtual std::string getcolor() = 0;
	std::string getrole ();  
    virtual bool legalmove(std::string endPos) = 0;
    virtual std::vector<std::string> getattack() = 0;
    virtual void setattack() = 0;
    virtual void setPosn(std::string des) = 0;
    virtual bool firstMove() = 0;
    virtual bool getPromote() = 0;
};

#endif
