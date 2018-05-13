#include "Widget.hpp"

using namespace genv;
using namespace std;

Widget::Widget(GUI* parent, Coord coords, int _width, int _height) : gui(parent), position(coords), width(_width), height(_height){
    backgroundColor=gui->getBackgroundColor();
    borderColor=gui->getBorderColor();
    focus=false;
    mouseOver=false;
}

bool Widget::isOver(int posx, int posy){
    if(!focusable) return false;
    if(posx>position.x && posx<=position.x+width && posy > position.y && posy<=position.y+height){
        return true;
    }
    return false;
}

void Widget::eventHandler(const event& ev){
    if(ev.type==ev_mouse){
        if(isOver(ev.pos_x,ev.pos_y))mouseOver=true;
        else mouseOver=false;
    }
}

bool Widget::isFocusable(){
    return focusable;
}
