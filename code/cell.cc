#include "cell.h"
#include <iostream>
#include "GObject.h"
using namespace std;

Cell::Cell(): g(0), td(0), offsetX(0), offsetY(0), def(0), current(0) {};

Cell::Cell(GObject *g, TextDisplay *td, int offsetX, int offsetY, char def, int x, int y): g(g), td(td), offsetX(offsetX), offsetY(offsetY), def(def), x(x), y(y) {
  for(int i = 0; i < 8; i++) neighbors[i] = 0;
  current = def;
  //cout<<"made a cell!"<<endl;
}

void Cell::addNeighbor(Cell *c, int i) {
  neighbors[i] = c;
}

Cell *Cell::getNeighbor(string direction) {
  if(direction == "no") return neighbors[1];
  if(direction == "so") return neighbors[6];
  if(direction == "ea") return neighbors[4];
  if(direction == "we") return neighbors[3];
  if(direction == "ne") return neighbors[2];
  if(direction == "nw") return neighbors[0];
  if(direction == "se") return neighbors[7];
  if(direction == "sw") return neighbors[5];
  return 0;
}

void Cell::notify(GObject *go) {
  g = go;
  if(g == 0) {
    current = def;
  }
  else {
    current = g->getSymbol();
  }
  td->notify(x+ offsetX, y + offsetY, current);
}

char Cell::getCurrent() {
    return current;
}

char Cell::getDef() {
    return def;
}

Character* Cell::getOcc() {
	char c = getCurrent();
	if ( c != '\\' && c != 'P' && c != 'G' && getDef() == getCurrent() ) {
		return g;
	} else {
		return 0;
	}
}
