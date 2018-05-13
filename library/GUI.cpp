#include "GUI.hpp"

using namespace genv;
using namespace std;

GUI::GUI(int _width, int _height) : width(_width),height(_height){
    gout.open(width, height);
    outputCanvas=canvas(width,height);
}

void GUI::addWidget(Widget* w){
    widgets.push_back(w);
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

