#include "cell.h"
#include "square.h"

using namespace std;

Cell::Cell(){}
Cell::Cell(std::shared_ptr<Square> s, bool occupy):s{move(s)}, occupy{occupy} {}

void Cell::sets(std::shared_ptr<Square> mys) {
	this->s = move(mys);
}

Square* Cell::gets() {
	return s.get();
}


bool Cell::checkoccupy() {
	return this->occupy;
}
void Cell::setoccupy(bool b) {
	this->occupy = b;
}
