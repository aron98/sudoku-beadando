#ifndef DIGITBOX_HPP_INCLUDED
#define DIGITBOX_HPP_INCLUDED

#include "Widget.hpp"

#include <functional>

class Digitbox : public Widget
{
protected:
    int digit;
    std::function<void()> action;
    bool valid;
public:
    Digitbox(GUI* parent, Coord coords, int _width, int _height, int _digit=0);
    Digitbox(GUI* parent, Coord coords, int _width, int _height, std::function<void()> onChange, int _digit=0);

    void setNumber(int num);
    int getValue() const {return digit; }
    void setValid(bool _to);
    void eventHandler(const genv::event& ev);
    void draw(genv::canvas& output);
};

#endif // DIGITBOX_HPP_INCLUDED
