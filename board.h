#ifndef _BOARD_H_
#define _BOARD_H_

#include <map>
#include <memory>
#include <string>
#include <vector>
#include "window.h"

//add
class Cell;
class TextDisplay;
class graphicDisplay;

class Board {
	std::map<std::string, std::shared_ptr<Cell>> theBoard;
	std::vector<std::string> whitecells;
	std::vector<std::string> blackcells;



	//TextDisplay* TD;
	std::shared_ptr<TextDisplay> TD;

	Xwindow w;
	//graphicDisplay* GD;
	std::shared_ptr<graphicDisplay> GD;

	bool isWin(std::string colour);
    bool inCheck(std::string des, std::string colour);
	void doIllegalmove(std::string startPos, std::string endPos, std::string colour);

	void updatewhitecells(std::string startPos, std::string endPos);
	void updateblackcells(std::string startPos, std::string endPos);

	bool enpassent = false;
	void enpassentMove(std::string start, std::string end, std::string colour);

	bool castling = false;
	void castlingMove(std::string start, std::string end, std::string colour);

	void init_textdisplay();
	void empty_textdisplay();

	void init_graphicdisplay();
	void empty_graphicdisplay();
public:
	std::map<std::string, std::shared_ptr<Cell>> gettheBoard();

	std::vector<std::string> getwhitecells();
	std::vector<std::string> getblackcells();

	void setinit();
	void setup();
	void doMove(std::string startPos, std::string endPos, std::string colour);
	bool blockpath(std::string start, std::string end);

};

#endif
