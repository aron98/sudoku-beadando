#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include "graphics.hpp"
#include "Widget.hpp"

#include <vector>

class Widget;

class GUI{
    int width, height;
    genv::canvas outputCanvas;
    genv::color backgroundColor=genv::color(0,0,0);
    genv::color borderColor=genv::color(0,0,0);
    std::vector<Widget*> widgets;
    void draw();
public:
    GUI(int _r=239, int _g=239, int _b=239, int _width=400, int _height=400);
    void eventLoop();
    genv::color getBackgroundColor();
};

#endif // GUI_HPP_INCLUDED
