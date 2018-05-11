#include "graphics.hpp"
#include "GUI.hpp"
#include "Widget.hpp"
#include "Sudoku.hpp"

using namespace genv;
using namespace std;

Sudoku::Sudoku(GUI* parent, Coord coords, int _width, int _height) : Widget(parent,coords,_width,_height){
    backgroundColor=gui->getBackgroundColor();
    borderColor=gui->getBorderColor();
}
