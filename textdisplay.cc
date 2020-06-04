#include "textdisplay.h"
using namespace std;


void TextDisplay::setrole(int r, int c, string role) {
    Display[r][c]=role;
}

std::string** TextDisplay::getdisplay() const{
    return this->Display;
}

const int board_size = 8;

TextDisplay::TextDisplay() {
    Display = new string*[board_size];
    int m=0;
    while ( m<board_size) {
        Display[m]=new string[board_size];
        m++;
    }
}

//TextDisplay::~TextDisplay() {
  //  int m=0; 
    //while (m<board_size) {
      //  delete Display[m];
        //m++;
   // }
    //delete []Display;
//}

ostream &operator<<(std::ostream &out, const TextDisplay &tdisplay) {   
    for (int r=0; r<board_size; r++) {
	cout << 8-r << "  ";
        unsigned int c=0;
        while ( c<board_size) {
            if (tdisplay.getdisplay()[r][c]== ""){
                if ((r%2==0 && c%2==0)||(r%2!=0 && c%2!=0)) {
                    out << "_ ";
                } else {
                    out << "  ";
                }
            } else {
                out << tdisplay.getdisplay()[r][c] << " ";
            }
            c++;
        }
	cout << endl;
    }
    cout << endl;
    cout << "   a b c d e f g h" << endl;
    return out;
}
