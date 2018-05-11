#ifndef DIGITBOX_HPP_INCLUDED
#define DIGITBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "Widget.hpp"

class DigitBox : public Widget{
    int digit;
public:
    bool valid;
    DigitBox(GUI* parent, Coord coords, int _width, int _height, int _digit=0);
    void eventHandler(const genv::event& ev);
    void draw(genv::canvas& out);
    int getValue();
    bool isEmpty();
};

#endif // DIGITBOX_HPP_INCLUDED
