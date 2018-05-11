#include "DigitBox.hpp"

using namespace genv;
using namespace std;

DigitBox::DigitBox(GUI* parent, Coord coords, int _width, int _height, int _digit) : Widget(parent, coords, _width, _height){
    valid=true;
    focusable=(_digit==0);
    digit=_digit;
}

void DigitBox::eventHandler(const event& ev){
    if(!focusable) return;

    if(ev.type == ev_key)
    {
        if('0' <= ev.keycode && ev.keycode <= '9' && focus) digit = ev.keycode - '0';
    }
    if(ev.type==ev_mouse){
        if(isOver(ev.pos_x,ev.pos_y))mouseOver=true;
        else mouseOver=false;
        if(ev.button == btn_left){
            if(isOver(ev.pos_x, ev.pos_y))focus=true;
            else focus=false;
        }
        if(focus){
            if(ev.button == btn_wheelup && digit<9) digit++;
            if(ev.button == btn_wheeldown && digit>0) digit--;
        }
    }
}

void DigitBox::draw(canvas& out){
    out << move_to(position.x, position.y);
    if(focus) out << selectedColor;
    else if(!focusable && !valid) out << color(255,backgroundColor.green,backgroundColor.blue);
    else if(mouseOver) out << color(selectedColor.red+30,selectedColor.green+30, selectedColor.blue);
    else out << borderColor;
    out << box(width, height);

    out << move_to(position.x+1, position.y+1);
    if(focusable)
    {
        if(valid)out << backgroundColor;
        else out << color(255,backgroundColor.green,backgroundColor.blue);
    }
    else out << color(backgroundColor.red-20,backgroundColor.green-20,backgroundColor.blue-20);
    out << box(width-2, height-2);

    if(digit!=0)
    {
        string t = to_string(digit);
        int fh = out.cascent() + out.cdescent();
        int md = (height - fh)/2 + out.cascent();

        int mr = (width - out.twidth(t))/2;

        out << move_to(position.x + mr, position.y + md);
        out << color(0,0,0);
        out << text(t);
    }
}

int DigitBox::getValue(){
    return digit;
}

bool DigitBox::isEmpty(){
    return (digit==0);
}
