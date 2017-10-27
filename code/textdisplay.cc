#include "textdisplay.h"
using namespace std;



void TextDisplay::update(int x, int y, char ch) {
  display[y][x] = ch;
}

void TextDisplay::notify(int x, int y, char ch) {
  update(x, y, ch);
}

int TextDisplay::getHeight() {
  return height;
}

int TextDisplay::getWidth() {
  return width;
}

char TextDisplay::getMember(int x, int y) {
  return display[y][x];
}

ostream &operator<<(ostream &out, TextDisplay &td) {
  for(int i = 0; i < td.getHeight(); i++) {
    for(int j = 0; j < td.getWidth(); j++) {
      out<<td.getMember(j, i);
    }
    out<<endl;
  }
  return out;
}
