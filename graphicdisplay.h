#ifndef GRAPHICDISPLAY_H
#define GRAPHICDISPLAY_H
#include <iostream>
#include <string>
#include <vector>
#include "window.h"
#include <utility>

//forward declaration
class Cell;

class graphicDisplay {
private:
    Xwindow &w;
    // pair is to store cells coords displayed in window
    std::vector<std::vector<std::pair <int, int> > > Display;
    // true is black and false is white 
    std::vector<std::vector<std::string> > Board; 
    int cell_len; 
    int Board_size;
    
public:
    graphicDisplay(Xwindow &w);
    ~graphicDisplay();
    void eraseCell(int prevrow, int prevcol);
    void setPiece(int prevrow, int prevcol, int nextrow, int nextcol, std::string role);        
    friend std::ostream &operator<<(std::ostream &out, graphicDisplay &gdisplay);
};

#endif

