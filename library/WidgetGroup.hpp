#ifndef WIDGETGROUP_HPP_INCLUDED
#define WIDGETGROUP_HPP_INCLUDED

#include "Widget.hpp"

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
