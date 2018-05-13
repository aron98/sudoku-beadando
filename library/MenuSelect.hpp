#ifndef MENUSELECT_HPP_INCLUDED
#define MENUSELECT_HPP_INCLUDED

#include "Widget.hpp"

struct Item{
    std::string value;
    bool itemSelected;
    Item(std::string _value, bool _selected):value(_value),itemSelected(_selected){}
};

class MenuSelect : public Widget{
protected:
    int maxLathato,from;
    std::string selectedItem;
    std::vector<Item> items;
    void selectItem(int item);
    bool isOver(int posx, int posy);
public:
    MenuSelect(GUI* parent, Coord coords, int _width, int _height, std::vector<std::string> _items, int _maxLathato);
    void eventHandler(const genv::event& ev);
    void draw(genv::canvas& out);
    std::string getValue();
};

#endif // MENUSELECT_HPP_INCLUDED
