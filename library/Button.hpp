#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "Widget.hpp"
#include <functional>

class Button : public Widget{
    std::function<void()> action;
    std::string value;
public:
    Button(GUI* parent, Coord coords, int w, int h, std::function<void()> onClick, std::string _value, bool f):Widget(parent,coords,w,h),action(onClick),value(_value){
        //std::cout<<"pista";
        focusable=f;
    }
    void eventHandler(const genv::event& ev);
    void draw(genv::canvas& out);
};

#endif // BUTTON_HPP_INCLUDED
