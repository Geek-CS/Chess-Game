#ifndef _COMPUTER_H_
#define _COMPUTER_H_


#include <string>
#include <memory>
#include <vector>

class Board;

class Computer {
	Board* currboard;
	void computermove1(std::string colour);
        void computermove2(std::string colour);
        void computermove3(std::string colour);
public:
	Computer(Board * currboard);

	void computermove(std::string level, std::string colour);

};

#endif
