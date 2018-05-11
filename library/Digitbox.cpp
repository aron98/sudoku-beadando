#include "Digitbox.hpp"

using namespace genv;
using namespace std;

SudokuDigitBox::SudokuDigitBox(GUI* parent, Coord pos, int _width, int _ height, int _digit):
    Widget(p, pos, _width, _height)
{
    focusable = (_digit!=0);
    digit = _digit;
    action = nullptr;
    valid=true;
}

SudokuDigitBox::SudokuDigitBox(GUI* parent, Coord pos, int _width, int _ height, function<void()> onChange, int _digit):
    Widget(p,pos,wh)
{
    focusable = (_digit!=0);
    digit = _digit;
    action = onChange;
    valid=true;
}

void Digitbox::setNumber(int num)
{
    if(0 <= num && num <=9) digit = num;
}

void SudokuDigitBox::eventHandler(const genv::event& ev)
{
    if(!focusable) return;

    if(ev.type == ev_key)
    {
        if('0' <= ev.keycode && ev.keycode <= '9')
        {
            if(digit!=ev.keycode-'0' && action) action();
            digit = ev.keycode - '0';
        }

    }

    if(ev.type == ev_mouse)
    {
        if(ev.button == btn_wheelup){ setNumber(digit+1); if(action) action(); }
        if(ev.button == btn_wheeldown){ setNumber(digit-1); if(action) action(); }
    }

}

void Digitbox::draw(genv::canvas& out)
{
    out << move_to(position.x, position.y);
    if(focus) out << selectedColor;
    else out << borderColor;
    out << box(width, height);

    out << move_to(position.x+1, position.y+1);
    if(focusable){
        if(valid) out<<backgroundColor;
        else out<<color(255,backgroundColor.green,backgroundColor.blue)
    }
    else out << color(backgroundColor.red-50,backgroundColor.green-50,backgroundColor.blue-50);
    out << box(width-2, height-2);

    if(digit!=0)
    {
        string t = to_string(digit);
        int fh = out.cascent() + out.cdescent();
        int md = (height - fh)/2 + out.cascent();

        int mr = (width - out.twidth(t))/2;

        out << move_to(width + mr, height + md);
        out << color(0,0,0);
        out << text(t);
    }
}

void setValid(bool _to){
    valid=_to;
}
