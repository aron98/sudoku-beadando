#include "InputField.hpp"

using namespace genv;
using namespace std;

InputField::InputField(GUI* parent, Coord coords, int _width, int _height, string val):Widget(parent,coords,_width,_height),value(val){
    pipe=false;
    focus=false;
    focusable=true;
    from=0;
    time=0;
    see=width/(gout.twidth("a"));
}

void InputField::draw(canvas& can){
    string addon = pipe && focus ? "|" : "";
    int to = (see+from>value.length() ? value.length() : see+from);
    string out=value.substr (from,to);
    can<<move_to(position.x,position.y);
    if(focus) can<<selectedColor;
    else if(mouseOver) can<<color(selectedColor.red+30,selectedColor.green+30, selectedColor.blue);
    else can<<borderColor;
    int fh = can.cascent() + can.cdescent();
    int md = (height - fh)/2 + can.cascent();
    can<<box(width,height)<<move_to(position.x+1,position.y+1)<<color(255,255,255)<<box(width-2,height-2)<<move_to(position.x+2,position.y+md)<<color(0,0,0)<<text(out+addon);
}

void InputField::input(string in){
    if(in=="backspace"){
        if(value.length()<1){
            value="";
        }else{
            value=value.substr(0,value.length()-1);
            if(full) from--;
        }
    if(genv::gout.twidth(value)>=width-10){
        full=true;
    }else{
        full=false;
    }
    }else{
        value+=in;
        if(genv::gout.twidth(value)>=width-10){
            full=true;
        }else{
            full=false;
        }
        if(full){
            from++;
        }
    }
}

void InputField::toggle(){
    pipe=!pipe;
}

string InputField::getValue(){
    return value;
}

void InputField::eventHandler(const event& ev){
    Widget::eventHandler(ev);
    if(ev.type==ev_mouse && ev.button==btn_left){
        if(isOver(ev.pos_x,ev.pos_y)){
            focus= true;
        }else{
            focus=false;
        }
    }
    if(ev.type==ev_timer){
        if((++time)%15==0) toggle();
    }
    if(focus && ev.type==ev_key){
         if(ev.keycode==key_backspace){
            input("backspace");
        }else if(ev.keycode>=32 && ev.keycode<=255){
            string s;
            s=(char) ev.keycode;
            input(s);
        }
    }
}
