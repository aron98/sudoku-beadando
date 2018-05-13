#ifndef WIDGETGROUP_HPP_INCLUDED
#define WIDGETGROUP_HPP_INCLUDED

#include "graphics.hpp"
#include "Widget.hpp"
#include "GUI.hpp"

#include <vector>

class WidgetGroup : public Widget{
protected:
    std::vector<Widget*> widgets;
public:
    WidgetGroup(GUI* parent):Widget(parent,Coord(0,0),0,0){}
    void addWidget(Widget* w);
    void eventHandler(const genv::event& ev);
    void draw(genv::canvas& out);
    ~WidgetGroup();
};

#endif // WIDGETGROUP_HPP_INCLUDED
