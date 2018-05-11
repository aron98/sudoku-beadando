#include "graphics.hpp"
#include "Widget.hpp"

using namespace genv;
using namespace std;

void Widget::setFocus(){
    focus=true;
}

void Widget::unsetFocus(){
    focus=false;
}

bool Widget::isFocusable(){
    return focusable;
}

void Widget::eventHandler(const genv::event ev){

}

void Widget::draw(genv::canvas& out){
    out<<move_to(position.x,position.y);
}
