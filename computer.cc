#include "computer.h"
#include "board.h"
#include "square.h"
#include "cell.h"
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

Computer::Computer(Board * currboard):currboard{currboard}{}

string pawnmove[64] = {"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1", 
                       "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
                       "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
                       "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
                       "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
                       "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
                       "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
                       "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8"};

void Computer::computermove1(string colour) {
	
	if (colour == "white") {
		for (auto start:currboard->getwhitecells()) {

			if (currboard->gettheBoard().at(start)->gets()->getrole() ==  "Pawn") {
				for (int i = 0; i < 64; i++) {
					if (currboard->gettheBoard().at(start)->gets()->legalmove(pawnmove[i])) {

					    try {
					    	currboard->doMove(start, pawnmove[i], colour);
					    }
					    catch (string color) {
					    	if (color != "illegal") {
					    		throw color;
					    	}
					    }
					} 
				}
			}

			for (auto end: currboard->gettheBoard().at(start)->gets()->getattack()) {
				try {
					currboard->doMove(start, end, colour);
				}
				catch (string color) {
					if (color != "illegal") {
						throw color;
					}
				}
			}
		}
	}

	if (colour == "black") {
		for (auto start:currboard->getblackcells()) {

			if (currboard->gettheBoard().at(start)->gets()->getrole() ==  "Pawn") {
				for (int i = 0; i < 64; i++) {
					if (currboard->gettheBoard().at(start)->gets()->legalmove(pawnmove[i])) {
						
						try {
					    	currboard->doMove(start, pawnmove[i], colour);
					    }
					    catch (string color) {
					    	if (color != "illegal") {
					    		throw color;
					    	}
					    }
					} 
				}
			}

			for (auto end: currboard->gettheBoard().at(start)->gets()->getattack()) {
				try {
					currboard->doMove(start, end, colour);
				}
				catch (string color) {
					if (color != "illegal") {
						throw color;
					}
				}

			}
		}
	}
}



	

void Computer::computermove2(string colour) {
	if (colour == "white") {
		for (auto start:currboard->getwhitecells()) {
			for (auto end: currboard->gettheBoard().at(start)->gets()->getattack()) {

				if (currboard->gettheBoard().at(end)->checkoccupy() &&
					(currboard->gettheBoard().at(end)->gets()->getcolor()== "black")) {

					try {
						currboard->doMove(start, end, colour);
					}
					catch(string color) {
						if (color != "illegal") {
							throw color;
						}
					}
				}
			}
		}
	}

	if (colour == "black") {
		for (auto start:currboard->getblackcells()) {
			for (auto end: currboard->gettheBoard().at(start)->gets()->getattack()) {

				if (currboard->gettheBoard().at(end)->checkoccupy() &&
					(currboard->gettheBoard().at(end)->gets()->getcolor()== "white")) {

					try {
						currboard->doMove(start,end,colour);
					}
					catch (string color) {
						if (color != "illegal") {
							throw color;
						}
					}
				} 
			}
		}
	}

	computermove1(colour);

}

void Computer::computermove3(string colour) {
	vector<string> dangerSquares;
	if (colour == "white") {
		for (auto startw: currboard->getwhitecells()) {

			for (auto bp : currboard->getblackcells()) { //find all squares under attack
				for (auto blackControl : currboard->gettheBoard().at(bp)->gets()->getattack()) {
                        if (!currboard->blockpath(bp, blackControl)) dangerSquares.push_back(blackControl);
                }
            }

            bool move = true;
            if (currboard->gettheBoard().at(startw)->gets()->getrole() == "Pawn") {
            	for (int i = 0; i < 64; i++) {
            		for (auto ds : dangerSquares) {
            			if (ds == pawnmove[i]) {
            				move = false;
            				break;
            			}
            		}
            		if (move == true) {
            			try {
            				currboard->doMove(startw, pawnmove[i], colour);
            			}
            			catch(string color) {
            				if (color != "illegal") {
            					throw color;
            				}
            			}
            		}
                }

            } else {
            	for (auto a : currboard->gettheBoard().at(startw)->gets()->getattack()) {
            		for (auto ds : dangerSquares) {
            			if (ds == a) {
            				move = false;
            				break;
            			}
            		}
            		if (move == true) {
            			try {
            				currboard->doMove(startw, a, colour);
            			}
            			catch(string color) {
            				if (color != "illegal") {
            					throw color;
            				}
            			}
            		}
                }
            }
		}
	}

	if (colour == "black") {
		for (auto startb: currboard->getblackcells()) {

			for (auto bp : currboard->getwhitecells()) { //find all squares under attack
				for (auto blackControl : currboard->gettheBoard().at(bp)->gets()->getattack()) {
                        if (!currboard->blockpath(bp, blackControl)) dangerSquares.push_back(blackControl);
                }
            }

            bool move = true;
            if (currboard->gettheBoard().at(startb)->gets()->getrole() == "Pawn") {
            	for (int i = 0; i < 64; i++) {
            		for (auto ds : dangerSquares) {
            			if (ds == pawnmove[i]) {
            				move = false;
            				break;
            			}
            		}
            		if (move == true) {
            			try {
            				currboard->doMove(startb, pawnmove[i], colour);
            			}
            			catch(string color) {
            				if (color != "illegal") {
            					throw color;
            				}
            			}
            		}
                }

            } else {
            	for (auto a : currboard->gettheBoard().at(startb)->gets()->getattack()) {
            		for (auto ds : dangerSquares) {
            			if (ds == a) {
            				move = false;
            				break;
            			}
            		}
            		if (move == true) {
            			try {
            				currboard->doMove(startb, a, colour);
            			}
            			catch(string color) {
            				if (color != "illegal") {
            					throw color;
            				}
            			}
            		}
                }
            }
		}
	}

	computermove2(colour);

}


void Computer::computermove(string level, string colour) {
	if (level == "com_diff1") {
		computermove1(colour);
	}else if (level == "com_diff2") {
		computermove2(colour);
	}else if(level == "com_diff3") {
		computermove3(colour);
	}
}


