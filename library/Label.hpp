#ifndef LABEL_HPP_INCLUDED
#define LABEL_HPP_INCLUDED

#include "Widget.hpp"

class Label : public Widget{
    std::string value;
public:
    Label(GUI* parent, Coord coords, int _width, int _height, std::string _value="");
    void eventHandler(const genv::event& ev);
    void draw(genv::canvas& out);
    void changeVal(std::string _val="");
};

#endif // LABEL_HPP_INCLUDED
