#include "graphicdisplay.h"

using namespace std;

graphicDisplay::graphicDisplay(Xwindow& w):
    w(w), Board(), Display(), cell_len(500/10), Board_size(9) {
        unsigned int x = 0;
        unsigned int y = 0;
        unsigned int n = 0;
        while (n < Board_size) {
             vector<pair<int, int> > rowDisplay;
             Display.push_back(rowDisplay);
             vector<string> cellCont;
             Board.push_back(cellCont);
            x=0;
            if (n >= 8) {
                for (unsigned int m = 0; m < Board_size; m++) {
                    Display[n].push_back(make_pair(x,y));
                    x += cell_len + 1;
                }
            Board[n].push_back("");
            Board[n].push_back("a");
            Board[n].push_back("b");
            Board[n].push_back("c");
            Board[n].push_back("d");
            Board[n].push_back("e");
            Board[n].push_back("f");
            Board[n].push_back("g");
            Board[n].push_back("h");
            }
            else {
              for(unsigned int m = 0; m < Board_size; m++) {
                  Display[n].push_back(make_pair(x,y));
                  if(m != 0) {
                    Board[n].push_back("assign"); 
                  } else {
                      int r = 8 - n;
                      Board[n].push_back(to_string (r));
                  }
                  x += cell_len + 1;
              }
            }
        y += cell_len + 1;
        n++;
    }
}

graphicDisplay::~graphicDisplay() {
    unsigned int n = 0;
    while(n < Board_size) {
        Board[n].clear();
        Display[n].clear();
        n++;
    }
    Board.clear();
    Display.clear();
}

void graphicDisplay::eraseCell(int r, int c) {
    Board[r][c] = "";
}

void graphicDisplay::setPiece(int prevrow, int prevcol, int nextrow, int nextcol, string role) {
    if (prevrow >= 0 && prevcol >= 0) {
        eraseCell(prevrow, prevcol);
    }
    if (nextrow >= 0 && nextcol >= 0) {
        Board[nextrow][nextcol] = role;
    }
}

ostream &operator<<(ostream &out, graphicDisplay &gdisplay){
    for (int n = 0; n < gdisplay.Board_size; n++) {
        for (int m = 0; m < gdisplay.Board_size; m++) {
        int x = gdisplay.Display[n][m].first;
        int y = gdisplay.Display[n][m].second;
        if (n<8 && m > 0) {
            if (m == 0) {
                (gdisplay.w).fillRectangle (x, y, gdisplay.cell_len, gdisplay.cell_len, 0);
            }
            // row is odd and column is even, or other way around
            if ((n % 2 == 1 && m % 2 == 0) || (n % 2 == 0 && m % 2 == 1)) {
                    (gdisplay.w).fillRectangle(x, y, gdisplay.cell_len, gdisplay.cell_len, 0);
                }
            // row and column are both even or both odd
            if ((n % 2 == 1 && m % 2 == 1) || (n % 2 == 0 && m % 2 == 0)) {
                    (gdisplay.w).fillRectangle(x, y, gdisplay.cell_len, gdisplay.cell_len, 4);
                }
        }
         if (gdisplay.Board[n][m] != "assign") {
                x += (500/17);
                y += (500/17);
                (gdisplay.w).drawBigString(x, y, gdisplay.Board[n][m]);
            }
       
    }
}
return out;
}
