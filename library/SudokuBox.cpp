#include "SudokuBox.hpp"

#include <vector>

using namespace genv;
using namespace std;

SudokuBox::SudokuBox(GUI* parent, Coord coords, vector<vector<int>> _fields, int _width, int _height) : Widget(parent,coords,_width,_height){
    int h = gout.cascent() + gout.cdescent() + 7;
    for(int i = 0; i < _fields.size(); i++){
        vector<DigitBox*> r;
        for(int j = 0; j<_fields[i].size(); j++){
            DigitBox* d = new DigitBox(gui,Coord(position.x+3+i*h+i/3*2, position.y+3+j*h + j/3*2), h-1,h-1,_fields[i][j]);
            r.push_back(d);
        }
        fields.push_back(r);
    }
}

void SudokuBox::eventHandler(const event& ev){
    for(int i = 0; i < fields.size(); i++){
        for(int j = 0; j<fields[i].size(); j++){
            fields[i][j]->eventHandler(ev);
        }
    }
    validate();
}

void SudokuBox::draw(canvas& out){
    out<<move_to(position.x,position.y)<<borderColor<<box(width, height)<<move_to(position.x+1,position.y+1)<<backgroundColor<<box(width-2,height-2);
    for(int i = 0; i < fields.size(); i++){
        for(int j = 0; j<fields[i].size(); j++){
            fields[i][j]->draw(out);
        }
    }
}

bool SudokuBox::validate(){
    for(int x = 0; x<3; x++){
        for(int y = 0; y<3; y++){
            vector<DigitBox*> box;
            for(int i = 0+x*3; i < 3+x*3; i++){
                for(int j = 0+y*3; j < 3+y*3; j++){
                    for(int a=0; a<box.size(); a++){
                        if(box[a]->getValue()==fields[i][j]->getValue()){
                            if(box[a]->getValue()!=0){
                                if(fields[i][j]->isFocusable()) fields[i][j]->valid=false;
                                else box[a]->valid=false;
                            }
                            box[a]->valid=true;
                        }/*else{
                            box[a]->valid=true;
                        }*/
                    }
                    box.push_back(fields[i][j]);
                }
            }
        }
    }
    bool validated=true;
    for(int i = 0; i < fields.size(); i++){
        for(int j = 0; j < fields[i].size(); j++){
            if(fields[i][j]->isEmpty() || !((*fields[i][j]).valid)){
                validated=false;
            }
        }
    }
    return validated;
}

SudokuBox::~SudokuBox(){
    vector< vector<DigitBox*> >::iterator row;
    vector<DigitBox*>::iterator col;
    for (row = fields.begin(); row != fields.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            delete (*col);
        }
    }
}
