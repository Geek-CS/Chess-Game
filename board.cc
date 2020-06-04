#include "board.h"
#include "cell.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"
#include "textdisplay.h"
#include "graphicdisplay.h"

#include <memory>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

string col[8] = {"a", "b", "c", "d", "e", "f", "g", "h"};

std::map<std::string, std::shared_ptr<Cell>> Board::gettheBoard() {
	return theBoard;
}

void Board::setinit() {
	//std::map<std::string index, std::shared_ptr<Cell> c> theBoard;

	//init whitecells and blackcells
	for (int i = 0; i<8; i++) {
		whitecells.push_back(col[i]+"1");
	}
	for (int i = 0; i<8; i++) {
		whitecells.push_back(col[i]+"2");
	}
	for (int i = 0; i<8; i++) {
		blackcells.push_back(col[i]+"7");
	}
	for (int i = 0; i<8; i++) {
		blackcells.push_back(col[i]+"8");
	}

	//initialize empty cell(row 3 4 5 6)
	for (int index = 3; index <=6; index++) {
		string out;
		stringstream ss;
		ss << index;
		out = ss.str();
		for (int i = 0; i<8; i++) {
			shared_ptr<Cell> c{new Cell};
			theBoard[col[i]+out]= move(c);
		}
	}

    //initialize white pawn(row 2)
	for (int i = 0; i<8; i++) {
		// shared_ptr<Square> p2 = make_unique<Square>("Pawn", "white", true);
		shared_ptr<Pawn> p2{new Pawn("Pawn", col[i]+"2", "white", true)};
		p2->setPosn(col[i]+"2");
		p2->setattack();
		shared_ptr<Cell> c2{new Cell(p2, true)};
		theBoard[col[i]+"2"]= move(c2);
	}

    //initialize black pawn(row 7)
	for (int i = 0; i<8; i++) {
		shared_ptr<Pawn> p7{new Pawn("Pawn", col[i]+"7","black", true)};
		p7->setPosn(col[i]+"7");
		p7->setattack();
		shared_ptr<Cell> c7{new Cell(p7, true)};
		theBoard[col[i]+"7"]= move(c7);
	}

    //init white rook;
    shared_ptr<Rook> r_a1{new Rook("Rook", "a1","white",true)};
    r_a1->setPosn("a1");
    r_a1->setattack();
    shared_ptr<Cell> a1{new Cell(r_a1, true)};
    theBoard["a1"]= move(a1);

    shared_ptr<Rook> r_h1{new Rook("Rook", "h1","white",true)};
    r_h1->setPosn("h1");
    r_h1->setattack();
    shared_ptr<Cell> h1{new Cell(r_h1, true)};
    theBoard["h1"]= move(h1);

    //init black rook;
    shared_ptr<Rook> r_a8{new Rook("Rook", "a8","black",true)};
    r_a8->setPosn("a8");
    r_a8->setattack();
    shared_ptr<Cell> a8{new Cell(r_a8, true)};
    theBoard["a8"]= move(a8);

    shared_ptr<Rook> r_h8{new Rook("Rook", "h8","black",true)};
    r_h8->setPosn("h8");
    r_h8->setattack();
    shared_ptr<Cell> h8{new Cell(r_h8, true)};
    theBoard["h8"]= move(h8);

    //init white knight
    shared_ptr<Knight> n_b1{new Knight("Knight", "b1","white")};
    n_b1->setPosn("b1");
    n_b1->setattack();
    shared_ptr<Cell> b1{new Cell(n_b1, true)};
    theBoard["b1"]= move(b1);

    shared_ptr<Knight> n_g1{new Knight("Knight","g1", "white")};
    n_g1->setPosn("g1");
    n_g1->setattack();
    shared_ptr<Cell> g1{new Cell(n_g1, true)};
    theBoard["g1"]= move(g1);

    //init black knight
    shared_ptr<Knight> n_b8{new Knight("Knight", "b8","black")};
    n_b8->setPosn("b8");
    n_b8->setattack();
    shared_ptr<Cell> b8{new Cell(n_b8, true)};
    theBoard["b8"]= move(b8);

    shared_ptr<Knight> n_g8{new Knight("Knight", "g8","black")};
    n_g8->setPosn("g8");
    n_g8->setattack();
    shared_ptr<Cell> g8{new Cell(n_g8, true)};
    theBoard["g8"]= move(g8);

    //init white bishop
    shared_ptr<Bishop> b_c1{new Bishop("Bishop", "c1","white")};
    b_c1->setPosn("c1");
    b_c1->setattack();
    shared_ptr<Cell> c1{new Cell(b_c1, true)};
    theBoard["c1"]= move(c1);

    shared_ptr<Bishop> b_f1{new Bishop("Bishop", "f1","white")};
    b_f1->setPosn("f1");
    b_f1->setattack();
    shared_ptr<Cell> f1{new Cell(b_f1, true)};
    theBoard["f1"]= move(f1);

    //init black bishop
    shared_ptr<Bishop> b_c8{new Bishop("Bishop", "c8","black")};
    b_c8->setPosn("c8");
    b_c8->setattack();
    shared_ptr<Cell> c8{new Cell(b_c8, true)};
    theBoard["c8"]= move(c8);

    shared_ptr<Bishop> b_f8{new Bishop("Bishop", "f8","black")};
    b_f8->setPosn("f8");
    b_f8->setattack();
    shared_ptr<Cell> f8{new Cell(b_f8, true)};
    theBoard["f8"]= move(f8);

    //init white queen
    shared_ptr<Queen> q_d1{new Queen("Queen", "d1","white")};
    q_d1->setPosn("d1");
    q_d1->setattack();
    shared_ptr<Cell> d1{new Cell(q_d1, true)};
    theBoard["d1"]= move(d1);

    //init black queen
    shared_ptr<Queen> q_d8{new Queen("Queen", "d8","black")};
    q_d8->setPosn("d8");
    q_d8->setattack();
    shared_ptr<Cell> d8{new Cell(q_d8, true)};
    theBoard["d8"]= move(d8);

    //init white king
    shared_ptr<King> k_e1{new King("King", "e1","white",true)};
    k_e1->setPosn("e1");
    k_e1->setattack();
    shared_ptr<Cell> e1{new Cell(k_e1, true)};
    theBoard["e1"]= move(e1);

    //init black king
    shared_ptr<King> k_e8{new King("King", "e8","black",true)};
    k_e8->setPosn("e8");
    k_e8->setattack();
    shared_ptr<Cell> e8{new Cell(k_e8, true)};
    theBoard["e8"]= move(e8);

    init_textdisplay();
    cout << *TD <<endl;

    init_graphicdisplay();
    cout << *GD <<endl;
}


int convert(std::string s) {

	if (s == "a") {
		return 0;
	} else if (s == "b") {
		return 1;
	} else if (s == "c") {
		return 2;
	} else if (s == "d") {
		return 3;
	} else if (s == "e") {
		return 4;
	} else if (s == "f") {
		return 5;
	} else if (s == "g") {
		return 6;
	} else {
		return 7;
	}
}

void Board::setup() {

	empty_textdisplay();
	cout << *TD <<endl;

	empty_graphicdisplay();
	cout << *GD <<endl;

	for (int index = 1; index <=8; index++) {
	    string out;
	    stringstream ss;
		ss << index;
		out = ss.str();
		for (int i = 0; i<8; i++) {
			shared_ptr<Cell> c{new Cell};
			theBoard[col[i]+out]= move(c);
		}
	}
	cout << "type command: " <<endl;
	cout << "+ K e1: places the piece K(white king)/k(black king) on square e1" <<endl;
	cout << "- e1: removes the piece from the square e1" <<endl;
	cout << "＝ colour make it colour's turn to go next(black or white)" <<endl;
	cout << "done: leaves setup mode" <<endl;

    int count_wking = 0;
    string wk_des;
    int count_bking = 0;
    string bk_des;

	string in;
	string role;
	string des;

	string color;

	
	while (cin >> in){
		int row;
        int col;
		if (in == "+") {
			cin >> role >> des;
			col = convert(des.substr(0,1));
			istringstream iss1 (des.substr(1,1));
			iss1 >> row;
			if (role == "K") {
				TD->setrole(8-row, col, "K");
				cout << *TD << endl;
				GD->setPiece(-1,-1,8-row, col+1, "K");
				cout << *GD <<endl;
				count_wking += 1;
				wk_des = des;
				whitecells.push_back(des);
				shared_ptr<King> w_k{new King("King", des,"white",true)};
				w_k->setPosn(des);
				w_k->setattack();
				theBoard.at(des)->sets(move(w_k));
				theBoard.at(des)->setoccupy(true);
			} else if (role == "k") {
				TD->setrole(8-row, col, "k");
				cout << *TD << endl;
				GD->setPiece(-1,-1,8-row, col+1, "k");
				cout << *GD <<endl;
				count_bking += 1;
				bk_des = des;
				blackcells.push_back(des);
				shared_ptr<King> b_k{new King("King", des,"black",true)};
				b_k->setPosn(des);
				b_k->setattack();
				theBoard.at(des)->sets(move(b_k));
				theBoard.at(des)->setoccupy(true);
			} else if (role == "Q") {
				TD->setrole(8-row, col, "Q");
				cout << *TD << endl;
				GD->setPiece(-1,-1,8-row, col+1, "Q");
				cout << *GD <<endl;
				whitecells.push_back(des);
				shared_ptr<Queen> w_q{new Queen("Queen", des,"white")};
				w_q->setPosn(des);
				w_q->setattack();
				theBoard.at(des)->sets(move(w_q));
				theBoard.at(des)->setoccupy(true);
			} else if (role == "q") {
				TD->setrole(8-row, col, "q");
				cout << *TD << endl;
				GD->setPiece(-1,-1,8-row, col+1, "q");
				cout << *GD <<endl;
				blackcells.push_back(des);
				shared_ptr<Queen> b_q{new Queen("Queen", des,"black")};
				b_q->setPosn(des);
				b_q->setattack();
				theBoard.at(des)->sets(move(b_q));
				theBoard.at(des)->setoccupy(true);
			} else if (role == "R") {
				TD->setrole(8-row, col, "R");
				cout << *TD << endl;
				GD->setPiece(-1,-1,8-row, col+1, "R");
				cout << *GD <<endl;
				whitecells.push_back(des);
				shared_ptr<Rook> w_r{new Rook("Rook", des,"white",true)};
				w_r->setPosn(des);
				w_r->setattack();
				theBoard.at(des)->sets(move(w_r));
				theBoard.at(des)->setoccupy(true);
			} else if (role == "r") {
				TD->setrole(8-row, col, "r");
				cout << *TD << endl;
				GD->setPiece(-1,-1,8-row, col+1, "r");
				cout << *GD <<endl;
				blackcells.push_back(des);
				shared_ptr<Rook> b_r{new Rook("Rook", des,"black",true)};
				b_r->setPosn(des);
				b_r->setattack();
				theBoard.at(des)->sets(move(b_r));
				theBoard.at(des)->setoccupy(true);
			} else if (role == "B") {
				TD->setrole(8-row, col, "B");
				cout << *TD << endl;
				GD->setPiece(-1,-1,8-row, col+1, "B");
				cout << *GD <<endl;
				whitecells.push_back(des);
				shared_ptr<Bishop> w_b{new Bishop("Bishop", des,"white")};
				w_b->setPosn(des);
				w_b->setattack();
				theBoard.at(des)->sets(move(w_b));
				theBoard.at(des)->setoccupy(true);
			} else if (role == "b") {
				TD->setrole(8-row, col, "b");
				cout << *TD << endl;
				GD->setPiece(-1,-1,8-row, col+1, "b");
				cout << *GD <<endl;
				blackcells.push_back(des);
				shared_ptr<Bishop> b_b{new Bishop("Bishop", des,"black")};
				b_b->setPosn(des);
				b_b->setattack();
				theBoard.at(des)->sets(move(b_b));
				theBoard.at(des)->setoccupy(true);
			} else if (role == "N") {
				TD->setrole(8-row, col, "N");
				cout << *TD << endl;
				GD->setPiece(-1,-1,8-row, col+1, "N");
				cout << *GD <<endl;
				whitecells.push_back(des);
				shared_ptr<Knight> w_n{new Knight("Knight", des,"white")};
				w_n->setPosn(des);
				w_n->setattack();
				theBoard.at(des)->sets(move(w_n));
				theBoard.at(des)->setoccupy(true);
			} else if (role == "n") {
				TD->setrole(8-row, col, "n");
				cout << *TD << endl;
				GD->setPiece(-1,-1,8-row, col+1, "n");
				cout << *GD <<endl;
				blackcells.push_back(des);
				shared_ptr<Knight> b_n{new Knight("Knight", des,"black")};
				b_n->setPosn(des);
				b_n->setattack();
				theBoard.at(des)->sets(move(b_n));
				theBoard.at(des)->setoccupy(true);
			} else if (role == "P") {
				if (des == "a1" || des == "b1" || des == "c1" || des == "d1" || 
					des == "e1" || des == "f1" || des == "g1" || des == "h1" ||
					des == "a8" || des == "b8" || des == "c8" || des == "d8" ||
					des == "e8" || des == "f8" || des == "g8" || des == "h8") {
					cout << "Needs no pawns are on the first row or last row of the chess board" <<endl;
					cout << role << des << endl;
				} else {
					TD->setrole(8-row, col, "P");
					cout << *TD << endl;
					GD->setPiece(-1,-1,8-row, col+1, "P");
				    cout << *GD <<endl;
					whitecells.push_back(des);
					shared_ptr<Pawn> w_p{new Pawn("Pawn", des,"white", true)};
					w_p->setPosn(des);
					w_p->setattack();
					theBoard.at(des)->sets(move(w_p));
					theBoard.at(des)->setoccupy(true);
				}
			} else if (role == "p") {
				if (des == "a1" || des == "b1" || des == "c1" || des == "d1" || 
					des == "e1" || des == "f1" || des == "g1" || des == "h1" ||
					des == "a8" || des == "b8" || des == "c8" || des == "d8" ||
					des == "e8" || des == "f8" || des == "g8" || des == "h8") {
					cout << "Needs no pawns are on the first row or last row of the chess board" <<endl;
					cout << role << des << endl;
				} else {
					TD->setrole(8-row, col, "p");
					cout << *TD << endl;
					GD->setPiece(-1,-1,8-row, col+1, "p");
					cout << *GD <<endl;
					blackcells.push_back(des);
					shared_ptr<Pawn> b_p{new Pawn("Pawn", des,"black", true)};
					b_p->setPosn(des);
					b_p->setattack();
					theBoard.at(des)->sets(move(b_p));
					theBoard.at(des)->setoccupy(true);
				}
			}
			theBoard.at(des)->setoccupy(true);
		} else if (in == "-") {
			cin >> des;
			col = convert(des.substr(0,1));
			istringstream iss2 (des.substr(1,1));
			iss2 >> row;
			TD->setrole(8-row, col, "");
			cout << *TD << endl;
			GD->eraseCell(8-row, col+1);
			cout << *GD <<endl;

			if (theBoard.at(des)->gets()->getcolor() == "white") {
				if (des == wk_des) {
					wk_des = "";
					count_wking -= 1;
				}

				updatewhitecells(des, " ");
			}

			if (theBoard.at(des)->gets()->getcolor() == "black") {
				if (des == bk_des) {
					bk_des = "";
					count_bking -= 1;
				}

				updateblackcells(des, " ");
			}

			shared_ptr<Cell> c{new Cell};
			theBoard.at(des)= move(c);

		} else if (in == "=") {
			cin >> color;
			cout << "Successfully set " << color << " player moving first" <<endl;
		} else if (in == "done") {
			
			bool done = true;

			for(auto checkw: whitecells) {
				if (inCheck(checkw, "white")) {
					done = false;
					cout << "warning: Black king is in check!" <<endl;
				}
			}

			for(auto checkb: blackcells) {
				if (inCheck(checkb, "black")) {
					done = false;
					cout << "warning: White king is in check!" <<endl;
				}
			}

			if ((count_bking != 1) || (count_wking != 1)) {
				if (count_bking != 1) {
					done = false;
					cout << "chess board allows exactly one black king" <<endl;
				}
				if (count_wking != 1) {
					done = false;
					cout << "chess board allows exactly one white king" <<endl;
				}
			} 

			if (done) {
				cout << "Chess board initialized!" <<endl;
				throw color;
				break;
			}


		} else {
			cout << "invalid command" << endl;
		}
	}

}


std::vector<std::string> Board::getwhitecells(){
	return whitecells;
}

std::vector<std::string> Board::getblackcells(){
	return blackcells;
}

void Board::updatewhitecells(std::string startPos, std::string endPos) {
	if (endPos == " ") {
		for (vector<string>::iterator it = whitecells.begin(); it != whitecells.end(); ++it) {
			if (*it == startPos) {
				whitecells.erase(it);
				break;
			}
		}
		return;
	}

	for (vector<string>::iterator it = whitecells.begin(); it != whitecells.end(); ++it) {
		if (*it == startPos) {
			whitecells.erase(it);
			break;
		}
	}
	whitecells.push_back(endPos);
}

void Board::updateblackcells(std::string startPos, std::string endPos) {
	if (endPos == " ") {
		for (vector<string>::iterator it = blackcells.begin(); it != blackcells.end(); ++it) {
			if (*it == startPos) {
				blackcells.erase(it);
				break;
			}
		}
		return;
	}

	for (vector<string>::iterator it = blackcells.begin(); it != blackcells.end(); ++it) {
		if (*it == startPos) {
			blackcells.erase(it);
			break;
		}
	}

	blackcells.push_back(endPos);
}

string rolechar(string role, string colour) {
	if (colour == "white") {
		if (role == "King") {
			return "K";
		} else if (role == "Queen") {
			return "Q";
		} else if (role == "Rook") {
			return "R";
		} else if (role == "Bishop") {
			return "B";
		} else if (role == "Knight") {
			return "N";
		} else {
			return "P";
		}
	} else {
		if (role == "King") {
			return "k";
		} else if (role == "Queen") {
			return "q";
		} else if (role == "Rook") {
			return "r";
		} else if (role == "Bishop") {
			return "b";
		} else if (role == "Knight") {
			return "n";
		} else {
			return "p";
		}
	}

}

void Board::doIllegalmove(string startPos, string endPos, string colour) {
	string win = "Win!";
	string s = "illegal";
	int startrow;
	int startcol;

	startcol = convert(startPos.substr(0,1));
	istringstream iss1 (startPos.substr(1,1));
	iss1 >> startrow;
	startrow = 8 - startrow;

	int endrow;
	int endcol;

	endcol = convert(endPos.substr(0,1));
	istringstream iss2 (endPos.substr(1,1));
	iss2 >> endrow;
	endrow = 8 - endrow;


	if (theBoard.at(endPos)->checkoccupy() && (theBoard.at(endPos)->gets()->getcolor() != colour)) {

		theBoard.at(endPos) = move(theBoard.at(startPos));
		theBoard.at(endPos)->gets()->setPosn(endPos);
		theBoard.at(endPos)->gets()->setattack();
		theBoard.at(endPos)->setoccupy(true);
		shared_ptr<Cell> c{new Cell};
		theBoard.at(startPos) = move(c);

		if (colour == "white") {
			updatewhitecells(startPos, endPos);
			updateblackcells(endPos, " ");
			if (inCheck(endPos, colour) == true) {
				if (isWin(colour)) {
					throw win;
				}
				cout << "Black King is in check!"<<endl;
			}

			TD->setrole(endrow, endcol, rolechar(theBoard.at(endPos)->gets()->getrole(), colour));
			TD->setrole(startrow, startcol, "");
			GD->setPiece(startrow, startcol+1, endrow, endcol+1,rolechar(theBoard.at(endPos)->gets()->getrole(), colour));
		}

		if (colour == "black") {
			updateblackcells(startPos, endPos);
			updatewhitecells(endPos, " ");
			if (inCheck(endPos,colour) == true) {
				if (isWin(colour)) {
					throw win;
				}
				cout << "White King is in check!"<<endl;
			}

			TD->setrole(endrow, endcol, rolechar(theBoard.at(endPos)->gets()->getrole(), colour));
			TD->setrole(startrow, startcol, "");
			GD->setPiece(startrow, startcol+1, endrow, endcol+1,rolechar(theBoard.at(endPos)->gets()->getrole(), colour));
		}

		if (theBoard.at(endPos)->gets()->getrole() == "Pawn") {
			if (endPos.substr(1,1) == "8") {
				cout << "White Pawn Promotion!" <<endl;
				cout << "Choose Promotion: Queen/Rook/Bishoo/Knight" <<endl;
				string changerole;
				cin >> changerole;
				if (changerole == "Queen") {
					TD->setrole(endrow, endcol, "Q");
					GD->setPiece(-1,-1,endrow, endcol+1, "Q");
					shared_ptr<Queen> w_q{new Queen("Queen", endPos,"white")};
					w_q->setPosn(endPos);
					w_q->setattack();
					theBoard.at(endPos)->sets(move(w_q));
				} else if (changerole == "Rook") {
					TD->setrole(endrow, endcol, "R");
					GD->setPiece(-1,-1,endrow, endcol+1, "R");
					shared_ptr<Rook> w_r{new Rook("Rook", endPos,"white", true)};
					w_r->setPosn(endPos);
					w_r->setattack();
					theBoard.at(endPos)->sets(move(w_r));
				} else if (changerole == "Bishop") {
					TD->setrole(endrow, endcol, "B");
					GD->setPiece(-1,-1,endrow, endcol+1, "B");
					shared_ptr<Bishop> w_b{new Bishop("Bishop", endPos,"white")};
					w_b->setPosn(endPos);
					w_b->setattack();
					theBoard.at(endPos)->sets(move(w_b));
				}  else if (changerole == "Knight") {
					TD->setrole(endrow, endcol, "N");
					GD->setPiece(-1,-1,endrow, endcol+1, "N");
					shared_ptr<Knight> w_n{new Knight("Knight", endPos,"white")};
					w_n->setPosn(endPos);
					w_n->setattack();
					theBoard.at(endPos)->sets(move(w_n));
				}

			}

			if (endPos.substr(1,1) == "1") {
				cout << "Black Pawn Promotion!" <<endl;
				cout << "Choose Promotion: Queen/Rook/Bishoo/Knight" <<endl;
				string changerole;
				cin >> changerole;
				if (changerole == "Queen") {
					TD->setrole(endrow, endcol, "q");
					GD->setPiece(-1,-1,endrow, endcol+1, "q");
					shared_ptr<Queen> w_q{new Queen("Queen", endPos,"white")};
					w_q->setPosn(endPos);
					w_q->setattack();
					theBoard.at(endPos)->sets(move(w_q));
				} else if (changerole == "Rook") {
					TD->setrole(endrow, endcol, "r");
					GD->setPiece(-1,-1,endrow, endcol+1, "r");
					shared_ptr<Rook> w_r{new Rook("Rook", endPos,"white", true)};
					w_r->setPosn(endPos);
					w_r->setattack();
					theBoard.at(endPos)->sets(move(w_r));
				} else if (changerole == "Bishop") {
					TD->setrole(endrow, endcol, "b");
					GD->setPiece(-1,-1,endrow, endcol+1, "b");
					shared_ptr<Bishop> w_b{new Bishop("Bishop", endPos,"white")};
					w_b->setPosn(endPos);
					w_b->setattack();
					theBoard.at(endPos)->sets(move(w_b));
				}  else if (changerole == "Knight") {
					TD->setrole(endrow, endcol, "n");
					GD->setPiece(-1,-1,endrow, endcol+1, "n");
					shared_ptr<Knight> w_n{new Knight("Knight", endPos,"white")};
					w_n->setPosn(endPos);
					w_n->setattack();
					theBoard.at(endPos)->sets(move(w_n));
				}

			}

		}
		cout << *TD <<endl;
		cout << *GD <<endl;
		if (colour == "white") {
			if (inCheck(endPos, colour) == true) {
				if (isWin(colour)) {
					throw win;
				}
				cout << "Black King is in check!"<<endl;
			}
		}

		if (colour == "black") {
			if (inCheck(endPos,colour) == true) {
				if (isWin(colour)) {
					throw win;
				}
				cout << "White King is in check!"<<endl;
			}
		}
		throw colour;
	}else if (theBoard.at(endPos)->checkoccupy() == false) {
		theBoard.at(endPos) = move(theBoard.at(startPos));
		theBoard.at(endPos)->gets()->setPosn(endPos);
		theBoard.at(endPos)->gets()->setattack();
		theBoard.at(endPos)->setoccupy(true);
		shared_ptr<Cell> c{new Cell};
		theBoard.at(startPos) = move(c);

		if (colour == "white") {
			updatewhitecells(startPos, endPos);
			if (inCheck(endPos, colour) == true) {
				if (isWin(colour)) {
					throw win;
				}
				cout << "Black King is in check!"<<endl;
			}

			TD->setrole(endrow, endcol, rolechar(theBoard.at(endPos)->gets()->getrole(), colour));
			TD->setrole(startrow, startcol, "");
			GD->setPiece(startrow, startcol+1, endrow, endcol+1,rolechar(theBoard.at(endPos)->gets()->getrole(), colour));
		}

		if (colour == "black") {
			updateblackcells(startPos, endPos);
			if (inCheck(endPos,colour) == true) {
				if (isWin(colour)) {
					throw win;
				}
				cout << "White King is in check!"<<endl;
			}

			TD->setrole(endrow, endcol, rolechar(theBoard.at(endPos)->gets()->getrole(), colour));
			TD->setrole(startrow, startcol, "");
			GD->setPiece(startrow, startcol+1, endrow, endcol+1,rolechar(theBoard.at(endPos)->gets()->getrole(), colour));

		}

		if (theBoard.at(endPos)->gets()->getrole() == "Pawn") {
			if (endPos.substr(1,1) == "8") {
				cout << "White Pawn Promotion!" <<endl;
				cout << "Choose Promotion: Queen/Rook/Bishoo/Knight" <<endl;
				string changerole;
				cin >> changerole;
				if (changerole == "Queen") {
					TD->setrole(endrow, endcol, "Q");
					GD->setPiece(endrow,endcol+1,endrow,endcol+1, "Q");
					shared_ptr<Queen> w_q{new Queen("Queen", endPos,"white")};
					w_q->setPosn(endPos);
					w_q->setattack();
					theBoard.at(endPos)->sets(move(w_q));
				} else if (changerole == "Rook") {
					TD->setrole(endrow, endcol, "R");
					GD->setPiece(endrow,endcol+1,endrow,endcol+1, "R");
					shared_ptr<Rook> w_r{new Rook("Rook", endPos,"white", true)};
					w_r->setPosn(endPos);
					w_r->setattack();
					theBoard.at(endPos)->sets(move(w_r));
				} else if (changerole == "Bishop") {
					TD->setrole(endrow, endcol, "B");
					GD->setPiece(endrow,endcol+1,endrow,endcol+1, "B");
					shared_ptr<Bishop> w_b{new Bishop("Bishop", endPos,"white")};
					w_b->setPosn(endPos);
					w_b->setattack();
					theBoard.at(endPos)->sets(move(w_b));
				}  else if (changerole == "Knight") {
					TD->setrole(endrow, endcol, "N");
					GD->setPiece(endrow,endcol+1,endrow,endcol+1, "N");
					shared_ptr<Knight> w_n{new Knight("Knight", endPos,"white")};
					w_n->setPosn(endPos);
					w_n->setattack();
					theBoard.at(endPos)->sets(move(w_n));
				}

			}

			if (endPos.substr(1,1) == "1") {
				cout << "Black Pawn Promotion!" <<endl;
				cout << "Choose Promotion: Queen/Rook/Bishoo/Knight" <<endl;
				string changerole;
				cin >> changerole;
				if (changerole == "Queen") {
					TD->setrole(endrow, endcol, "q");
					GD->setPiece(endrow,endcol+1,endrow,endcol+1, "q");
					shared_ptr<Queen> w_q{new Queen("Queen", endPos,"white")};
					w_q->setPosn(endPos);
					w_q->setattack();
					theBoard.at(endPos)->sets(move(w_q));
				} else if (changerole == "Rook") {
					TD->setrole(endrow, endcol, "r");
					GD->setPiece(endrow,endcol+1,endrow,endcol+1, "r");
					shared_ptr<Rook> w_r{new Rook("Rook", endPos,"white", true)};
					w_r->setPosn(endPos);
					w_r->setattack();
					theBoard.at(endPos)->sets(move(w_r));
				} else if (changerole == "Bishop") {
					TD->setrole(endrow, endcol, "b");
					GD->setPiece(endrow,endcol+1,endrow,endcol+1, "b");
					shared_ptr<Bishop> w_b{new Bishop("Bishop", endPos,"white")};
					w_b->setPosn(endPos);
					w_b->setattack();
					theBoard.at(endPos)->sets(move(w_b));
				}  else if (changerole == "Knight") {
					TD->setrole(endrow, endcol, "n");
					GD->setPiece(endrow,endcol+1,endrow,endcol+1, "n");
					shared_ptr<Knight> w_n{new Knight("Knight", endPos,"white")};
					w_n->setPosn(endPos);
					w_n->setattack();
					theBoard.at(endPos)->sets(move(w_n));
				}

			}

		}
		cout << *TD <<endl;
		cout << *GD <<endl;
		if (colour == "white") {
			if (inCheck(endPos, colour) == true) {
				if (isWin(colour)) {
					throw win;
				}
				cout << "Black King is in check!"<<endl;
			}
		}

		if (colour == "black") {
			if (inCheck(endPos,colour) == true) {
				if (isWin(colour)) {
					throw win;
				}
				cout << "White King is in check!"<<endl;
			}
		}
		throw colour;

	} else {
		throw s;
	}
}

void Board::doMove(string startPos, string endPos, string colour) {
	string s = "illegal";
	if (theBoard.at(startPos)->gets()->legalmove(endPos)) {
		if ((theBoard.at(startPos)->gets()->getrole() == "Queen") ||
			(theBoard.at(startPos)->gets()->getrole() == "Bishop") ||
			(theBoard.at(startPos)->gets()->getrole() == "Rook")) {
			if (blockpath(startPos, endPos)) {
				throw s;
			} else {
				doIllegalmove(startPos, endPos, colour);
			}
		} else if (theBoard.at(startPos)->gets()->getrole() == "Pawn") {
			if (startPos.substr(0,1) == endPos.substr(0,1)) {

				if (theBoard.at(startPos)->gets()->firstMove()) { //move one cell
					enpassent = false;
				} else { //move two cell
					int coll = -1;
					int colr = 1;
					for (int i = 0; i< 8; i++) {
						if (endPos.substr(0,1) != col[i]) {
							coll += 1;
							colr += 1;
						} else {
							break;
						}
					}

					string row = endPos.substr(1,1);

					if (coll < 0) {
						if ((theBoard.at(col[colr]+row)->checkoccupy() && 
							theBoard.at(col[colr]+row)->gets()->getrole() == "Pawn" &&
							theBoard.at(col[colr]+row)->gets()->getcolor() != colour)) {
							enpassent = true;
						}
					} else if (colr > 7) {
						if ((theBoard.at(col[coll]+row)->checkoccupy() && 
							theBoard.at(col[coll]+row)->gets()->getrole() == "Pawn" &&
							theBoard.at(col[coll]+row)->gets()->getcolor() != colour)) {
							enpassent = true;
						}
					} else {
						if ((theBoard.at(col[coll]+row)->checkoccupy() && 
							theBoard.at(col[coll]+row)->gets()->getrole() == "Pawn" &&
							theBoard.at(col[coll]+row)->gets()->getcolor() != colour) ||
							(theBoard.at(col[colr]+row)->checkoccupy() &&
							theBoard.at(col[colr]+row)->gets()->getrole() == "Pawn" &&
							theBoard.at(col[colr]+row)->gets()->getcolor() != colour)) {
							enpassent = true;
					    }
					}
				}
				if (theBoard.at(endPos)->checkoccupy()) {
					throw s;
				} else  {
					doIllegalmove(startPos, endPos, colour);
				}
			} else {
				if (theBoard.at(endPos)->checkoccupy()) {
					doIllegalmove(startPos, endPos, colour);
				} else {
					enpassentMove(startPos, endPos, colour);
				}
			}

		} else {
			doIllegalmove(startPos, endPos, colour);
		}
	} else {
		if (theBoard.at(startPos)->gets()->getrole() == "King" &&
			       theBoard.at(startPos)->gets()->firstMove() &&
			       (endPos == "c1" || endPos == "g1" || endPos == "c8" || endPos == "g8")){

			       	if (endPos == "c1") {
			       		if (theBoard.at("b1")->checkoccupy() || 
			       			theBoard.at("c1")->checkoccupy() || 
			       			theBoard.at("d1")->checkoccupy()) {
			       			throw s;
			       		} else {
			       			if (theBoard.at("a1")->checkoccupy() && 
			       				theBoard.at("a1")->gets()->getrole() == "Rook" &&
			       				theBoard.at("a1")->gets()->firstMove()) {
			       				castling = true;
			       				castlingMove(startPos, endPos, colour);
			       			} else {
			       				throw s;
			       			}
			       		}
			       	}

			       	if (endPos == "g1") {
			       		if (theBoard.at("f1")->checkoccupy() || 
			       			theBoard.at("g1")->checkoccupy()) {
			       			throw s;
			       		} else {
			       			if (theBoard.at("h1")->checkoccupy() && 
			       				theBoard.at("h1")->gets()->getrole() == "Rook" &&
			       				theBoard.at("h1")->gets()->firstMove()) {
			       				castling = true;
			       				castlingMove(startPos, endPos, colour);
			       			} else {
			       				throw s;
			       			}
			       		}
			       	}

			       	if (endPos == "c8") {
			       		if (theBoard.at("b8")->checkoccupy() || 
			       			theBoard.at("c8")->checkoccupy() || 
			       			theBoard.at("d8")->checkoccupy()) {
			       			throw s;
			       		} else {
			       			if (theBoard.at("a8")->checkoccupy() && 
			       				theBoard.at("a8")->gets()->getrole() == "Rook" &&
			       				theBoard.at("a8")->gets()->firstMove()) {
			       				castling = true;
			       				castlingMove(startPos, endPos, colour);
			       			} else {
			       				throw s;
			       			}
			       		}
			       	}

			       	if (endPos == "g8") {
			       		if (theBoard.at("f8")->checkoccupy() || 
			       			theBoard.at("g8")->checkoccupy()) {
			       			throw s;
			       		} else {
			       			if (theBoard.at("h8")->checkoccupy() && 
			       				theBoard.at("h8")->gets()->getrole() == "Rook" &&
			       				theBoard.at("h8")->gets()->firstMove()) {
			       				castling = true;
			       				castlingMove(startPos, endPos, colour);
			       			} else {
			       				throw s;
			       			}
			       		}
			       	}


		} 
		throw s;
	}
}

bool Board::inCheck(std::string des, std::string colour) {
	bool check = false;
	for (auto pos: theBoard.at(des)->gets()->getattack()) {

		if (theBoard.at(pos)->checkoccupy()) {
			if (theBoard.at(pos)->gets()->getrole() == "King") {
				if (theBoard.at(pos)->gets()->getcolor() != colour) {
					check = true;
					break;
				}
			}
		}

	}
	return check;
}

void Board::init_textdisplay() {
	shared_ptr<TextDisplay> td{new TextDisplay()};
	TD = move(td);

	for (int r1 = 2; r1 <= 5; r1++) {
		for(int c1 = 0; c1 < 8; c1++) { 
			TD->setrole(r1, c1, "");
        }
    }

    for (int c2 = 0; c2 < 8; c2++) {
    	TD->setrole(1, c2, "p");
    	TD->setrole(6, c2, "P");
    }

    string blackrole[8] = {"r", "n", "b", "q", "k", "b", "n", "r"};
    string whiterole[8] = {"R", "N", "B", "Q", "K", "B", "N", "R"};

    for (int c3 = 0; c3 < 8; c3++) {
    	TD->setrole(0,c3,blackrole[c3]);
    	TD->setrole(7,c3,whiterole[c3]);
    }
}

void Board::empty_textdisplay() {
	//TD = new TextDisplay();

	shared_ptr<TextDisplay> td{new TextDisplay()};
	TD = move(td);

	for (int i = 0; i<8; i++) {
		for (int j = 0; j<8; j++) {
			TD->setrole(i,j, "");
		}
	}

}

bool Board::blockpath(string start, string end) {
	int startrow;
	string startcol;

	startcol = start.substr(0,1);
	istringstream iss1 (start.substr(1,1));
	iss1 >> startrow;

	int endrow;
	string endcol;

	endcol = end.substr(0,1);
	istringstream iss2 (end.substr(1,1));
	iss2 >> endrow;

	int s = 0;
	int e = 0;
	for (int i = 0; i < 8; i++) {
		if (col[i] == startcol) {
			break;
		} else {
			s+=1;
		}
	}
	for (int j= 0; j<8; j++) {
		if (col[j] == endcol) {
			break;
		} else {
			e+=1;
		}
	}



	if (startcol == endcol) {
		if (startrow < endrow) {
			for (int i = startrow + 1; i < endrow; i++ ) {
				string chari;
				stringstream ss;
				ss << i;
				chari = ss.str();
				if (theBoard.at(startcol+chari)->checkoccupy()) {
					return true;
				}
			}

		} else {
			for (int i = endrow + 1; i < startrow; i++ ) {
				string chari;
				stringstream ss;
				ss << i;
				chari = ss.str();
				if (theBoard.at(startcol+chari)->checkoccupy()) {
					return true;
				}
			}
		}
		return false;
		
	} else if (startrow == endrow) {
		string row;
		stringstream ss;
		ss << startrow;
		row = ss.str();

		if (s < e) {
			for (int k = s+1; k < e; k++) {
				if (theBoard.at(col[k]+row)->checkoccupy()) {
					return true;
				}
			}
		} else {
			for (int m = e+1; m < s; m++) {
				if (theBoard.at(col[m]+row)->checkoccupy()) {
					return true;
				}
			}
		}
		return false;
	} else {
		// string col[8] = {"a"....."h"}
		if (s < e) {

			if (startrow < endrow) {      
				for (int x = s+1; x < e; x++){
					startrow += 1;
					string rows;
		            stringstream ss;
					ss << startrow;
		            rows = ss.str();  
					if (theBoard.at(col[x] + rows)->checkoccupy()) {
						return true;
					}
				}
				return false;
			} else {
				for (int y = s+1; y < e; y++) {
					startrow -= 1;
					string rows;
		            stringstream ss;
					ss << startrow;
		            rows = ss.str();
					if (theBoard.at(col[y] + rows)->checkoccupy()) {
						return true;
					}
				}
				return false;
			}
		} else {
			if (startrow < endrow) {
				for (int x = e+1; x < s; x++){
					startrow += 1;
					string rows;
		            stringstream ss;
					ss << startrow;
		            rows = ss.str(); 
					if (theBoard.at(col[x] +rows)->checkoccupy()) {
						return true;
					}
				}
				return false;
			} else {
				for (int y = e+1; y < s; y++) {
					startrow -= 1;
					string rows;
		            stringstream ss;
					ss << startrow;
		            rows = ss.str();
					if (theBoard.at(col[y] +rows)->checkoccupy()) {
						return true;
					}
				}
				return false;
			}
		}
	}
}
			

void Board::enpassentMove(string start, string end, string colour) {
	string s = "illegal";
	if (enpassent) {
		string col = end.substr(0,1);
		string row = end.substr(1,1);

		int enpassrow;
		int enpasscol= convert(col);

		int rowi;
		istringstream iss (row);
	    iss >> rowi;

		if (colour == "white") {
			rowi -= 1;
			enpassrow = 8-rowi;

			stringstream ss;
		    ss << rowi;
		    row = ss.str();

			TD->setrole(enpassrow, enpasscol, "");
			GD->setPiece(enpassrow, enpasscol+1,enpassrow, enpasscol+1, "");
			updateblackcells(col+row, " ");
		}

		if (colour == "black") {
			rowi += 1;
			enpassrow = 8-rowi;

			stringstream ss;
		    ss << rowi;
		    row = ss.str();

			TD->setrole(enpassrow, enpasscol, "");
			GD->setPiece(enpassrow, enpasscol+1,enpassrow, enpasscol+1, "");
			updatewhitecells(col+row, " ");
		}


		shared_ptr<Cell> c{new Cell};
		theBoard.at(col+row) = move(c);
		enpassent = false;

		doIllegalmove(start, end, colour);

	} else {
		throw s;
	}
}

void Board::castlingMove(string start, string end, string colour) {
	string s = "illegal";
	int startrow;
	int startcol;

	startcol = convert(start.substr(0,1));
	istringstream iss1 (start.substr(1,1));
	iss1 >> startrow;
	startrow = 8 - startrow;

	int endrow;
	int endcol;

	endcol = convert(end.substr(0,1));
	istringstream iss2 (end.substr(1,1));
	iss2 >> endrow;
	endrow = 8 - endrow;


	if (castling) {
		theBoard.at(end) = move(theBoard.at(start));
		theBoard.at(end)->gets()->setPosn(end);
		theBoard.at(end)->gets()->setattack();
		theBoard.at(end)->setoccupy(true);
		shared_ptr<Cell> c{new Cell};
		theBoard.at(start) = move(c);

		if (colour == "white") {
			updatewhitecells(start, end);
			if (inCheck(end, colour) == true) {
				cout << "Black King is in check!"<<endl;
			}

			TD->setrole(endrow, endcol, rolechar(theBoard.at(end)->gets()->getrole(), colour));
			TD->setrole(startrow, startcol, "");
			GD->setPiece(startrow, startcol+1, endrow, endcol+1,rolechar(theBoard.at(end)->gets()->getrole(), colour));
		}

		if (colour == "black") {
			updateblackcells(start, end);
			if (inCheck(end,colour) == true) {
				cout << "White King is in check!"<<endl;
			}

			TD->setrole(endrow, endcol, rolechar(theBoard.at(end)->gets()->getrole(), colour));
			TD->setrole(startrow, startcol, "");
			GD->setPiece(startrow, startcol+1, endrow, endcol+1,rolechar(theBoard.at(end)->gets()->getrole(), colour));

		}

		if (end == "c1") {
			theBoard.at("d1") = move(theBoard.at("a1"));
			theBoard.at("d1")->gets()->setPosn("d1");
			theBoard.at("d1")->gets()->setattack();
			theBoard.at("d1")->setoccupy(true);
			shared_ptr<Cell> c{new Cell};
			theBoard.at("a1") = move(c);

			updatewhitecells("a1", "d1");
			if (inCheck("d1", "white") == true) {
				cout << "Black King is in check!"<<endl;
			}

			TD->setrole(7, 3, rolechar(theBoard.at("d1")->gets()->getrole(), "white"));
			TD->setrole(7, 0, "");
			GD->setPiece(7, 1, 7, 4,rolechar(theBoard.at("d1")->gets()->getrole(), "white"));
		} else if (end == "g1") {
			theBoard.at("f1") = move(theBoard.at("h1"));
			theBoard.at("f1")->gets()->setPosn("f1");
			theBoard.at("f1")->gets()->setattack();
			theBoard.at("f1")->setoccupy(true);
			shared_ptr<Cell> c{new Cell};
			theBoard.at("h1") = move(c);

			updatewhitecells("h1", "f1");
			if (inCheck("f1", "white") == true) {
				cout << "Black King is in check!"<<endl;
			}

			TD->setrole(7, 5, rolechar(theBoard.at("f1")->gets()->getrole(), "white"));
			TD->setrole(7, 7, "");
			GD->setPiece(7, 8, 7, 6,rolechar(theBoard.at("f1")->gets()->getrole(), "white"));
		} else if(end == "c8") {
			theBoard.at("d8") = move(theBoard.at("a8"));
			theBoard.at("d8")->gets()->setPosn("d8");
			theBoard.at("d8")->gets()->setattack();
			theBoard.at("d8")->setoccupy(true);
			shared_ptr<Cell> c{new Cell};
			theBoard.at("a8") = move(c);

			updateblackcells("a8", "d8");
			if (inCheck("d8", "black") == true) {
				cout << "Black King is in check!"<<endl;
			}

			TD->setrole(0, 3, rolechar(theBoard.at("d8")->gets()->getrole(), "black"));
			TD->setrole(0, 0, "");
			GD->setPiece(0, 1, 0, 4,rolechar(theBoard.at("d8")->gets()->getrole(), "black"));
		} else if(end == "g8") {
			theBoard.at("f8") = move(theBoard.at("h8"));
			theBoard.at("f8")->gets()->setPosn("f8");
			theBoard.at("f8")->gets()->setattack();
			theBoard.at("f8")->setoccupy(true);
			shared_ptr<Cell> c{new Cell};
			theBoard.at("h8") = move(c);
			updateblackcells("h8", "f8");
			if (inCheck("f8", "black") == true) {
				cout << "Black King is in check!"<<endl;
			}

			TD->setrole(0, 5, rolechar(theBoard.at("f8")->gets()->getrole(), "black"));
			TD->setrole(0, 7, "");
			GD->setPiece(0, 8, 0, 6,rolechar(theBoard.at("f8")->gets()->getrole(), "black"));
		}
		cout << *TD <<endl;
		cout << *GD <<endl;
		throw colour;
	}else {
		throw s;
	}
}




void Board::init_graphicdisplay() {
	//GD {new graphicDisplay(w)};

	shared_ptr<graphicDisplay> gd{new graphicDisplay(w)};
	GD = move(gd);

	GD->setPiece(-1, -1, 0, 1, "r");
	GD->setPiece(-1, -1, 0, 2, "n");
	GD->setPiece(-1, -1, 0, 3, "b");
	GD->setPiece(-1, -1, 0, 4, "q");
	GD->setPiece(-1, -1, 0, 5, "k");
	GD->setPiece(-1, -1, 0, 6, "b");
	GD->setPiece(-1, -1, 0, 7, "n");
	GD->setPiece(-1, -1, 0, 8, "r");

	GD->setPiece(-1, -1, 7, 1, "R");
	GD->setPiece(-1, -1, 7, 2, "N");
	GD->setPiece(-1, -1, 7, 3, "B");
	GD->setPiece(-1, -1, 7, 4, "Q");
	GD->setPiece(-1, -1, 7, 5, "K");
	GD->setPiece(-1, -1, 7, 6, "B");
	GD->setPiece(-1, -1, 7, 7, "N");
	GD->setPiece(-1, -1, 7, 8, "R");

	GD->setPiece(-1, -1, 1, 1, "p");
	GD->setPiece(-1, -1, 1, 2, "p");
	GD->setPiece(-1, -1, 1, 3, "p");
	GD->setPiece(-1, -1, 1, 4, "p");
	GD->setPiece(-1, -1, 1, 5, "p");
	GD->setPiece(-1, -1, 1, 6, "p");
	GD->setPiece(-1, -1, 1, 7, "p");
	GD->setPiece(-1, -1, 1, 8, "p");

	GD->setPiece(-1, -1, 6, 1, "P");
	GD->setPiece(-1, -1, 6, 2, "P");
	GD->setPiece(-1, -1, 6, 3, "P");
	GD->setPiece(-1, -1, 6, 4, "P");
	GD->setPiece(-1, -1, 6, 5, "P");
	GD->setPiece(-1, -1, 6, 6, "P");
	GD->setPiece(-1, -1, 6, 7, "P");
	GD->setPiece(-1, -1, 6, 8, "P");
	cout << "cout" <<endl;

}

void Board::empty_graphicdisplay() {
	shared_ptr<graphicDisplay> gd{new graphicDisplay(w)};
	GD = move(gd);
}

bool Board::isWin(string colour) {

	if (colour == "white") {
        // can i move out of mate?
	
    vector<string> escape;
	string kPos,attackerPos;
	for (auto c : blackcells) { // find available move for king
		if (theBoard.at(c)->gets()->getrole() == "King") {
			escape = theBoard.at(c)->gets()->getattack();
			kPos = c;
			break;
		}
	}

	vector<string> underattack;
	vector<string> attacker;
	for (auto u : whitecells) { // find all underattack squares, u represents posn of white piece
		for (auto a : theBoard.at(u)->gets()->getattack()) { // a represents possible dest of attack
			if (!blockpath(u, a)) {
				underattack.push_back(a); // all squares thats not blocked
				if (a == kPos) attacker.push_back(u); // attacker marked
			}
		}
	}

	bool dangerous = false;
        //vector<string> safe;
	for (auto a : escape) {
		dangerous = false;
		for (auto b : underattack) { //check to see if any escape move is underattack
			if (a == b) {
				dangerous = true;
				break;
			}
		}
		if (dangerous == false){
		    return false; // indicate there are still valid move
        	//safe.push_back(a);// get a list of all safe moves
	    }
    }

	if (attacker.size() > 1) {
	return true; // take mate and block mate cannot happen when there are more than one attacker
}
	//can i take mate?
	
	for (auto bc : blackcells) {// find all available counterattack moves
		for (auto ba : theBoard.at(bc)->gets()->getattack()) {
			if ((!blockpath(bc, ba)) && (ba == attacker[0])) return false; // attacker can be killed
			
		}
	}


	return true;
}

if (colour == "black") {
        // can i move out of mate?
	
    vector<string> escape;
	string kPos,attackerPos;
	for (auto c : whitecells) { // find available move for king
		if (theBoard.at(c)->gets()->getrole() == "King") {
			escape = theBoard.at(c)->gets()->getattack();
			kPos = c;
			break;
		}
	}

	vector<string> underattack;
	vector<string> attacker;
	for (auto u : blackcells) { // find all underattack squares, u represents posn of white piece
		for (auto a : theBoard.at(u)->gets()->getattack()) { // a represents possible dest of attack
			if (!blockpath(u, a)) {
				underattack.push_back(a); // all squares thats not blocked
				if (a == kPos) attacker.push_back(u); // attacker marked
			}
		}
	}

	bool dangerous = false;
        //vector<string> safe;
	for (auto a : escape) {
		dangerous = false;
		for (auto b : underattack) { //check to see if any escape move is underattack
			if (a == b) {
				dangerous = true;
				break;
			}
		}
		if (dangerous == false){
		    return false; // indicate there are still valid move
        	//safe.push_back(a);// get a list of all safe moves
	    }
    }

	if (attacker.size() > 1) {
	return true; // take mate and block mate cannot happen when there are more than one attacker
}
	//can i take mate?
	
	for (auto bc : whitecells) {// find all available counterattack moves
		for (auto ba : theBoard.at(bc)->gets()->getattack()) {
			if ((!blockpath(bc, ba)) && (ba == attacker[0])) return false; // attacker can be killed
			
		}
	}


	return true;
}
	 //indicate there are no available move

}















