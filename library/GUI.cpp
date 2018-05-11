#include "graphics.hpp"
#include "GUI.hpp"
#include "Widget.hpp"
#include "DigitBox.hpp"

#include <vector>

using namespace genv;
using namespace std;

GUI::GUI(int _width, int _height) : width(_width),height(_height){
    gout.open(width, height);
    outputCanvas=canvas(width,height);
    Coord coord(10,10);
    int h = outputCanvas.cascent() + outputCanvas.cdescent() + 7;
    DigitBox* number = new DigitBox(this, coord, h-1, h-1,9);
    widgets.push_back(number);
    DigitBox* number2 = new DigitBox(this, Coord(50,50), h-1, h-1);
    widgets.push_back(number2);
}

void GUI::eventLoop(){
    event ev;
    gin.timer(1000/30);
    while(gin >> ev) {
        outputCanvas<<move_to(0,0)<<borderColor<<box(width,height)<<move_to(1,1)<<backgroundColor<<box(width-2,height-2);
        for(std::vector<Widget*>::iterator it = widgets.begin(); it != widgets.end(); ++it) {
            (*it)->eventHandler(ev);
            (*it)->draw(outputCanvas);
        }
        draw();
    }
}

void GUI::draw(){
    gout<<stamp(outputCanvas,0,0);
    gout<<refresh;
}

color GUI::getBackgroundColor(){
    return backgroundColor;
}

color GUI::getBorderColor(){
    return borderColor;
}

GUI::~GUI(){
    for(std::vector<Widget*>::iterator it = widgets.begin(); it != widgets.end(); ++it) {
        delete (*it);
    }
}

