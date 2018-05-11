#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include "graphics.hpp"

class GUI{
    int width, height;
public:
    GUI(int _width=400, int _height=400);
    void eventLoop();
};

#endif // GUI_HPP_INCLUDED
