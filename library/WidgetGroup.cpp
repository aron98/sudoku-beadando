#include "WidgetGroup.hpp"

#include <vector>

using namespace genv;
using namespace std;

void WidgetGroup::addWidget(Widget* w){
    widgets.push_back(w);
}

void WidgetGroup::eventHandler(const event& ev){
    for(std::vector<Widget*>::iterator it = widgets.begin(); it != widgets.end(); ++it) {
            (*it)->eventHandler(ev);
        }
}

void WidgetGroup::draw(canvas& out){
    for(std::vector<Widget*>::iterator it = widgets.begin(); it != widgets.end(); ++it) {
            (*it)->draw(out);
        }
}

WidgetGroup::~WidgetGroup(){
    for(std::vector<Widget*>::iterator it = widgets.begin(); it != widgets.end(); ++it) {
            delete (*it);
        }
}
