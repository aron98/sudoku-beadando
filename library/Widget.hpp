#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "global.hpp"
#include "GUI.hpp"

class GUI;

class Widget{
    Coord position;
    int width, height;
    bool focus,focusable;
    genv::color backgroundColor=genv::color(0,0,0);
    genv::color borderColor=genv::color(0,0,0);
    genv::color selectedColor=genv::color(0,0,0);
    GUI* gui;
public:

    Widget(GUI* parent, genv::color background=genv::color(239,239,239), genv::color border=genv::color(196,196,196), genv::color selected=genv::color(130,177,256)) : gui(parent), backgroundColor(background), borderColor(border), selectedColor(selected){}
    void setFocus();
    void unsetFocus();
    bool isFocusable();
    void eventHandler(const genv::event ev);
    void draw(genv::canvas& out);
};

#endif // WIDGET_HPP_INCLUDED
