#include "graphics.hpp"
#include "Widget.hpp"
#include "GUI.hpp"

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
