#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
class TextDisplay {
  int height, width;
  char **display;
  void update(int x, int y, char ch);
  public:
    TextDisplay(int height, int width): height(height), width(width) {
      display = new char *[height];
      for(int i = 0; i < height; i++) {
        display[i] = new char [width];
      }
      for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
          if(j == 0 || j == width - 1) {
            display[i][j] = '|';
          }
          else if(i == 0 || i == height - 1) {
            display[i][j] = '-';
          }
          else {
            display[i][j] = ' ';
          }
        }
      }
    }
    void notify(int x, int y, char ch);
    int getHeight();
    int getWidth();
    char getMember(int x, int y);


friend std::ostream &operator<<(std::ostream &out, TextDisplay &td);
};
#endif
