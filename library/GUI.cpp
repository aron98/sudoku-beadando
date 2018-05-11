#include "graphics.hpp"
#include "GUI.hpp"

using namespace genv;
using namespace std;

GUI::GUI(int _width, int _height){
    width=_width;
    height=_height;
    gout.open(width, height);
    eventLoop();
}

void GUI::eventLoop(){
    event ev;
    while(gin >> ev) {

    }
}
