#include "Label.hpp"

using namespace genv;
using namespace std;

Label::Label(GUI* parent, Coord coords, int _width, int _height, string _value):Widget(parent,coords,(_width > gout.twidth(_value) ? _width: gout.twidth(_value)+4),_height),value(_value){
    focusable=false;
}

void Label::eventHandler(const event& ev){

}

void Label::draw(canvas& out){
    out << move_to(position.x, position.y);
    out << borderColor;
    out << box(width, height);

    out << move_to(position.x+1, position.y+1);
    out << backgroundColor;
    out << box(width-2, height-2);

    int fh = out.cascent() + out.cdescent();
    int md = (height - fh)/2 + out.cascent();
    int mr = (width - out.twidth(value))/2;
    out << move_to(position.x + mr, position.y + md);
    out << color(0,0,0);
    out << text(value);
}

void Label::changeVal(string _val){
    value=_val;
}
