#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "global.hpp"
#include "GUI.hpp"

class GUI;

class Widget{
protected:
    Coord position;
    int width, height;
    bool focus,focusable,mouseOver;
    genv::color backgroundColor=genv::color(0,0,0);
    genv::color borderColor=genv::color(0,0,0);
    genv::color selectedColor=genv::color(127,176,255);
    GUI* gui;
public:
    Widget(GUI* parent, Coord coords, int _width, int _height);
    bool isOver(int _x, int _y);
    bool isFocusable();
    virtual void eventHandler(const genv::event& ev)=0;
    virtual void draw(genv::canvas& out)=0;
};

#endif // WIDGET_HPP_INCLUDED
