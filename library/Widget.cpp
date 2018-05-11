#include "graphics.hpp"
#include "Widget.hpp"

using namespace genv;
using namespace std;

Widget::Widget(GUI* parent, Coord coords, int _width, int _height) : gui(parent), position(coords), width(_width), height(_height){
    backgroundColor=gui->getBackgroundColor();
    borderColor=gui->getBorderColor();
}

void Widget::setFocus(){
    focus=true;
}

void Widget::unsetFocus(){
    focus=false;
}

bool Widget::isFocusable(){
    return focusable;
}

void Widget::draw(genv::canvas& out){
    out<<move_to(position.x,position.y);
}
