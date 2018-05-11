#include "graphics.hpp"
#include "Widget.hpp"
#include "GUI.hpp"

using namespace genv;
using namespace std;

Widget::Widget(GUI* parent, Coord coords, int _width, int _height) : gui(parent), position(coords), width(_width), height(_height){
    backgroundColor=gui->getBackgroundColor();
    borderColor=gui->getBorderColor();
}

bool Widget::isOver(int posx, int posy){
    if(!focusable) return false;
    if(posx>position.x && posx<=position.x+width && posy > position.y && posy<=position.y+height){
        return true;
    }
    return false;
}
