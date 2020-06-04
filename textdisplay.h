#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <string>
#include <iostream>

class TextDisplay{   
	std::string** Display; 
public:
    TextDisplay();
//    ~TextDisplay();
    void setrole(int r, int c, std::string role); // sets the coords to be the piece
    std::string** getdisplay()const;
};

std::ostream &operator<<(std::ostream &out, const TextDisplay &tdisplay);

#endif
