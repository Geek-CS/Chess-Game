#ifndef _CELL_H_
#define _CELL_H_

#include <string>
#include <memory>

class Square;

class Cell {
	std::shared_ptr<Square> s;
	bool occupy=false;
public:
	Cell();
	Cell(std::shared_ptr<Square> s, bool occupy);
	void sets(std::shared_ptr<Square> mys);
	Square* gets();
	bool checkoccupy();
	void setoccupy(bool b);
};

#endif
