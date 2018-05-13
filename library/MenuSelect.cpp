#include "MenuSelect.hpp"

using namespace genv;
using namespace std;

MenuSelect::MenuSelect(GUI* parent, Coord coords, int _width, int _height, vector<string> _items, int _maxLathato):Widget(parent,coords,_width,_height), maxLathato(_maxLathato),from(0){
    focus=false;
    focusable=true;
    for(int i = 0; i < _items.size(); i++){
        bool val = (i==0);
        if(val) selectedItem=_items[i];
        Item it(_items[i],val);
        items.push_back(it);
        /*if(gout.twidth(_items[i])+4+8+gout.twidth("V")>width) width=gout.twidth(_items[i])+4+8+gout.twidth("V");
        if(height<gout.cascent()+gout.cdescent()+4) height=gout.cascent()+gout.cdescent()+4;*/
    }
}

void MenuSelect::draw(canvas& out){
    int to = (items.size()<maxLathato ? items.size() : maxLathato);
    if(focus) out<< selectedColor;
    else if(mouseOver) out << color(selectedColor.red+30,selectedColor.green+30, selectedColor.blue);
    else out<<borderColor;
    out<<move_to(position.x,position.y)<<box(width,height);
    out<<move_to(position.x+1,position.y+1)<<backgroundColor<<box(width-2,height-2);
    out<<move_to(position.x+2,position.y+height/2+gout.cascent()/2)<<color(0,0,0)<<text(selectedItem);
    if(focus) out<< selectedColor;
    else if(mouseOver) out << color(selectedColor.red+30,selectedColor.green+30, selectedColor.blue);
    else out<<borderColor;
    out<<move_to(position.x+width-8-gout.twidth("V"),position.y)<<box_to(position.x+width-1,position.y+height-1)<<move_to(position.x+width-8-gout.twidth("V")+1,position.y+1)<<backgroundColor<<box_to(position.x+width-2,position.y+height-2);
    out<<move_to(position.x+width-8-gout.twidth("V")/2,position.y+height/2+gout.cascent()/2)<<color(0,0,0)<<text("V");
    if(focus){
        for(int i=from; i < to+from; i++){
            out<<move_to(position.x,position.y+(i-from+1)*height)<<borderColor<<box(width,height);
            int blue=(items[i].itemSelected ? 255 : backgroundColor.blue);
            out<<move_to(position.x+1,position.y+1+(i-from+1)*height)<<color(backgroundColor.red,backgroundColor.green,blue)<<box(width-2,height-2);
            out<<move_to(position.x+2,position.y+height/2+gout.cascent()/2+(i-from+1)*height)<<color(0,0,0)<<text(items[i].value);
        }
    }
}

bool MenuSelect::isOver(int posx, int posy){
    if(focus){
        int to = (items.size()<maxLathato ? items.size() : maxLathato);
        if(posx>position.x && posx<=position.x+width && posy > position.y && posy<=position.y+height*(to+1)){
            return true;
        }
        return false;
    }else{
        if(posx>position.x && posx<=position.x+width && posy > position.y && posy<=position.y+height){
            return true;
        }
        return false;
    }
}

void MenuSelect::selectItem(int _item){
    for(int i = 0; i < items.size(); i++){
        if(i==_item){
            items[i].itemSelected=true;
            selectedItem=items[i].value;
        }
        else items[i].itemSelected=false;
    }
}

void MenuSelect::eventHandler(const event& ev){
    Widget::eventHandler(ev);
    if(ev.type == ev_mouse){
        if(ev.button==btn_left && ev.button==1){
            if(focus && isOver(ev.pos_x, ev.pos_y)){
                focus=false;
                if(!isOver(ev.pos_x, ev.pos_y)) selectItem((ev.pos_y-position.y)/height+from-1);
            }else{
                focus=isOver(ev.pos_x, ev.pos_y);
            }
        }else if(ev.button==btn_wheeldown && focus){
            if(items.size()-maxLathato>from) from++;
        }else if(ev.button==btn_wheelup && focus){
            if(from>=1) from--;
        }
    }
}

string MenuSelect::getValue(){
    return selectedItem;
}
