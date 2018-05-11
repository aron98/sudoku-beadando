#include "graphics.hpp"
#include "GUI.hpp"
#include "Widget.hpp"

using namespace genv;
using namespace std;

GUI::GUI(int _r, int _g, int _b, int _width, int _height) : width(_width),height(_height){
    gout.open(width, height);
    outputCanvas=canvas(width,height);
    backgroundColor=color(_r,_g,_b);
    _r=(_r>=50 ? _r-50 : _r+50);
    _g=(_g>=50 ? _g-50 : _g+50);
    _b=(_b>=50 ? _b-50 : _b+50);
    borderColor=color(_r,_g,_b);
}

void GUI::eventLoop(){
    event ev;
    gin.timer(1000/30);
    while(gin >> ev) {
        outputCanvas<<move_to(0,0)<<borderColor<<box(width,height)<<move_to(1,1)<<backgroundColor<<box(width-2,height-2);
        draw();
    }
}

void GUI::draw(){
    gout<<stamp(outputCanvas,0,0);
    gout<<refresh;
}

