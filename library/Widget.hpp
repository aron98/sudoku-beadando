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
    bool focus,focusable;
    genv::color backgroundColor=genv::color(0,0,0);
    genv::color borderColor=genv::color(0,0,0);
    genv::color selectedColor=genv::color(127,176,255);
    GUI* gui;
public:
    Widget(GUI* parent, Coord coords, int _width, int _height);
    void setFocus();
    void unsetFocus();
    bool isFocusable();
    virtual void eventHandler(const genv::event& ev);
    virtual void draw(genv::canvas& out);
};

#endif // WIDGET_HPP_INCLUDED
