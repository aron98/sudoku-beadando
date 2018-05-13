#ifndef INPUTFIELD_H_INCLUDED
#define INPUTFIELD_H_INCLUDED

#include "Widget.hpp"

#include <string>

class InputField : public Widget{
    std::string value;
    bool pipe,full;
    int see, from, time;
    void input(std::string in);
    void toggle();
public:
    InputField(GUI* parent, Coord coords, int _width, int _height, std::string val="");
    void draw(genv::canvas& out);
    std::string getValue();
    void eventHandler(const genv::event& ev);

};

#endif // INPUTFIELD_H_INCLUDED
