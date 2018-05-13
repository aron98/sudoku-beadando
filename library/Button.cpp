#include "Button.hpp"

using namespace genv;
using namespace std;

void Button::eventHandler(const event& ev){
    Widget::eventHandler(ev);
    if(focusable){
        if(ev.type==ev_mouse && ev.button==btn_left){
            if(isOver(ev.pos_x,ev.pos_y)) action();
        }
    }
}

void Button::draw(canvas& out){
    out << move_to(position.x, position.y);
    if(focus) out << selectedColor;
    //else if(!focusable && !valid) out << color(255,borderColor.green,borderColor.blue);
    else if(mouseOver && focusable) out << color(selectedColor.red+30,selectedColor.green+30, selectedColor.blue);
    else out << borderColor;
    out << box(width, height);

    out << move_to(position.x+1, position.y+1);
    if(focusable) out << backgroundColor;
    else out << color(backgroundColor.red-20,backgroundColor.green-20,backgroundColor.blue-20);
    out << box(width-2, height-2);

    int fh = out.cascent() + out.cdescent();
    int md = (height - fh)/2 + out.cascent();
    int mr = (width - out.twidth(value))/2;
    out << move_to(position.x + mr, position.y + md);
    out << color(0,0,0);
    out << text(value);
}
