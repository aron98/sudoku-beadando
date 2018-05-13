#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include "graphics.hpp"
#include "Widget.hpp"

#include <vector>

class Widget;

class GUI{
    int width, height;
    genv::canvas outputCanvas;
    genv::color backgroundColor=genv::color(239,239,239);
    genv::color borderColor=genv::color(200,200,200);
    std::vector<Widget*> widgets;
    void draw();
public:
    GUI(int _width=400, int _height=400);
    void eventLoop();
    genv::color getBackgroundColor();
    genv::color getBorderColor();
    void addWidget(Widget* w);
    ~GUI();
};

#endif // GUI_HPP_INCLUDED
