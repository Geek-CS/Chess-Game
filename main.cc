#include "board.h"
#include "computer.h"
#include "cell.h"
#include "square.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"
#include "pawn.h"

#include <string>
#include <iostream>

using namespace std;

class Score{
	int whitescore;
	int blackscore;
public:
	Score(int whitescore, int blackscore): whitescore{whitescore}, blackscore{blackscore} {}
	void addw() {
		whitescore += 1;
	}
	void addb() {
		blackscore += 1;
	}
	int getwhitescore() {
		return whitescore;
	}
	int getblackscore() {
		return blackscore;
	}
};

int main() {
	cout << "Command: setup (setup your own initial chess board)" <<endl;
	cout << "Command: game white-player black-player (with initialized chess board)" <<endl;
	cout << "choose player: human / com_diff1 / com_diff2 / com_diff3" <<endl;

	Board myboard;
	bool isset = false;
	string iswhite = "white";
	Computer playerc(&myboard);

	Score finalscore{0,0};

	string s;
	string startPos;
	string endPos;

	string whitep;
	string blackp;

	string lastmove = "black";
	string c;

	while (cin >> s) {
	if (s == "game") {
		if (isset == false) {
			myboard.setinit();
			cout <<"White " << whitep << "'s turn" <<endl;
		} else {
			cout << iswhite << " 's turn"<<endl;
		}

		if (isset) {
			if (iswhite == "black") {
				lastmove = "white";
			} else {
				lastmove = "black";
			}
			isset = false;
		}

		cin >> whitep >> blackp;
		if ((whitep == "com_diff1" || whitep == "com_diff2" || whitep == "com_diff3")&&
			blackp == "human") {
			if (lastmove == "white") {
				cout << "Black " << blackp << "'s turn!" <<endl;
				cout << "Command: move e2 e3(for example: moveing chess on e2 to e3)" <<endl;
			} else {
				cout << "White computer's turn! Press w to get move!" <<endl;
				cin >> c;
			}
		    if (c == "w") {
		    	try {
					playerc.computermove(whitep,"white");
				}
				catch (string msg) {
					if (msg == "Win!") {
						finalscore.addw();
						cout << "White Win!" <<endl;
						cout << "Initialize a new chess board or Ctrl+D to terminate!" <<endl;
					}

					cout << lastmove << " human's turn!" <<endl;
					lastmove = msg;
				}
		    }
		} else if ((whitep == "com_diff1" || whitep == "com_diff2" || whitep == "com_diff3")&&
			(blackp == "com_diff1" || blackp == "com_diff2" || blackp == "com_diff3")) {
			cout << "Both players are computers!" <<endl;

			if (lastmove == "white") {
				cout << "Black " << blackp << "'s turn! Press b to get move!" <<endl;
			} else {
				cout << "White computer's turn! Press w to get move!" <<endl;
			}

			cin >> c;
			if (c == "w") {
				try {
					playerc.computermove(whitep,"white");
				}
				catch (string msg) {
					if (msg == "Win!") {
						finalscore.addw();
						cout << "White Wins!"<<endl;
						cout << "Initialize a new chess board or Ctrl+D to terminate!" <<endl;
					}
						cout << lastmove << " computer's turn! Press b to get move!" <<endl;
						lastmove = msg;
					}
			} 
			if (c == "b") {
				try {
					playerc.computermove(blackp, "black");
				}
				catch (string msg) {
					if (msg == "Win!") {
						finalscore.addb();
						cout <<"Black Wins!"<<endl;
						cout << "Initialize a new chess board or Ctrl+D to terminate!" <<endl;
					}
					cout << lastmove << " computer's turn! Press w to get move!" <<endl;
					lastmove = msg;
				}
			}
		} else if (whitep == "human" && (blackp == "com_diff1" || blackp == "com_diff2" || blackp == "com_diff3")) {

			if (lastmove == "white") {
				cout << "Black " << blackp << "'s turn! Press b to get move!" <<endl;
				cin >> c;
			} else {
				cout << "White human's turn!" <<endl;
				cout << "Command: move e2 e3(for example: moveing chess on e2 to e3)" <<endl;
			}

			if (c == "b") {
				try {
					playerc.computermove(blackp, "black");
				}
				catch (string msg) {
					if (msg == "Win!") {
						finalscore.addb();
						cout << "Black Wins!" <<endl;
						cout << "Initialize a new chess board or Ctrl+D to terminate!" <<endl;
					}
					cout << lastmove << " computer's turn! Press w to get move!" <<endl;
					lastmove = msg;
				}
			}

		} else {

			cout << "Command: move e2 e3(for example: moveing chess on e2 to e3)" <<endl;
		}

	} else if (s == "resign") {
		if (whitep == "human" && blackp == "human") {
			if (lastmove == "white") {
				finalscore.addw();
				cout << "White Wins!" <<endl; 
			} else if (lastmove == "black") {
				finalscore.addb();
				cout <<"Black Wins!" <<endl;
			}

		}else {
			if (whitep == "human") {
				cout << "Black Wins!" <<endl;
				finalscore.addb();
			} else if (blackp == "human") {
				cout <<"White Wins!" <<endl;
				finalscore.addw();
			}
		}

		cout << endl;
		cout << "Initialize a new chess board or Ctrl+D to terminate!" << endl;
	} else if (s == "move") {
		if ((cin >> startPos >> endPos) &&((startPos.substr(0, 1) == "a" || startPos.substr(0, 1) == "b" || startPos.substr(0, 1) == "c" ||
				startPos.substr(0, 1) == "d" || startPos.substr(0, 1) == "e" || startPos.substr(0, 1) == "f" ||
				startPos.substr(0, 1) == "g" || startPos.substr(0, 1) == "h") &&
				(endPos.substr(0, 1) == "a" || endPos.substr(0, 1) == "b" || endPos.substr(0, 1) == "c" ||
				endPos.substr(0, 1) == "d" || endPos.substr(0, 1) == "e" || endPos.substr(0, 1) == "f" ||
				endPos.substr(0, 1) == "g" || endPos.substr(0, 1) == "h")) ) {
			
			if (isset) {
				if (iswhite == "black") {
					lastmove = "white";
				} else {
					lastmove = "black";
				}
				isset = false;
			}
				
			if (whitep == "human" && blackp == "human") {
				try{
					if(lastmove == "white") {
						myboard.doMove(startPos, endPos, "black");
					} else if (lastmove == "black") {
						myboard.doMove(startPos, endPos, "white");
					}	
				} 
				catch (string msg) {

					if (msg == "Win!") {
						if (lastmove == "white") {
							finalscore.addb();
							cout <<"Checkmate! Black Wins!" <<endl;
							cout <<endl;
						    cout << "Initialize a new chess board or Ctrl+D to terminate!" <<endl;
						} else if (lastmove == "black") {
							finalscore.addw();
							cout <<"Checkmate! White Wins!" <<endl;
							cout <<endl;
						    cout << "Initialize a new chess board or Ctrl+D to terminate!" <<endl;
						}
					} else if (msg == "illegal") {
						cout << "Warning: Illegal move!" <<endl;
					} else {
						cout << lastmove << " human's turn" <<endl;
						lastmove = msg;
					}
				}
			} else {
				if (whitep == "human") {
					try {
						myboard.doMove(startPos, endPos, "white");
					}
					catch (string msg) {
						if (msg == "Win!") {
							finalscore.addw();
							cout <<"Checkmate! White Wins!" <<endl;
							cout <<endl;
							cout << "Initialize a new chess board or Ctrl+D to terminate!" <<endl;
						}
						else if (msg == "illegal") {
							cout << "Warning: Illegal move!" <<endl;
						} else {
							cout << lastmove << " computer's turn! Press b to get move!" <<endl;
							lastmove = msg;
						}
					}

					cin >> c;
					if (c == "b") {
						try {
							playerc.computermove(blackp, "black");
						}
						catch (string msg) {
							if (msg == "Win!") {
								finalscore.addb();
								cout << "Checkmate! Black Wins!" <<endl;
								cout <<endl;
								cout << "Initialize a new chess board or Ctrl+D to terminate!" <<endl;
							}
							cout << lastmove << " human's turn!" <<endl;
							lastmove = msg;
						}

					}
				} else if (blackp == "human") {
					try {
						myboard.doMove(startPos, endPos, "black");
					}
					catch (string msg) {
						if (msg == "Win!") {
							finalscore.addb();
							cout <<"Checkmate! Black Wins!" <<endl;
							cout <<endl;
							cout << "Initialize a new chess board or Ctrl+D to terminate!" <<endl;
						}else if (msg == "illegal") {
							cout << "Warning: Illegal move!" <<endl;
						} else {
							cout << lastmove << " computer's turn! Press w to get move" <<endl;
							lastmove = msg;
						}
					}

					cin >> c;
					if (c == "w") {
						try {
							playerc.computermove(blackp, "white");
						}
						catch (string msg) {
							if (msg == "Win!") {
								finalscore.addw();
								cout <<"Checkmate! White Wins!"<<endl;
								cout <<endl;
								cout << "Initialize a new chess board or Ctrl+D to terminate!" <<endl;
							}
							cout << lastmove << " human's turn!" <<endl;
							lastmove = msg;
						}

					}
				} 
			}
		}else {
			cout <<"Invalid move command: " << startPos << endPos << endl;
		}
	} else if (s == "setup") {
		try {
			myboard.setup();
		}
		catch (string msg) {
			isset = true;
			iswhite = msg;
			cout << msg << " player's turn" <<endl;
			cout << "Command: game white-player black-player (with initialized chess board)" <<endl;
			cout << "choose player: human / com_diff1 / com_diff2 / com_diff3" <<endl;

		}
	} else {
		cout << "Invalid Command!"<<endl;
	}
}

cout << "Final Score:" <<endl;
cout << "White: " << finalscore.getwhitescore() <<endl;
cout << "Black: " << finalscore.getblackscore() <<endl;
}
