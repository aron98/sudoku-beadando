#include "SudokuBox.hpp"

#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace genv;
using namespace std;

SudokuBox::SudokuBox(GUI* parent, Coord coords, string filename, int _width, int _height) : Widget(parent,coords,_width,_height){
    loadMap(filename);
}

void SudokuBox::loadMap(string filename){
    int h = gout.cascent() + gout.cdescent() + 7;
    ifstream input(filename.c_str());
    for(int i = 0; i < 9; i++){
        stringstream ss;
        string str;
        getline(input,str);
        ss<<str;
        vector<DigitBox*> r;
        for(int j = 0; j < 9; j++){
            int temp;
            ss>>temp;
             DigitBox* d = new DigitBox(gui,Coord(position.x+3+i*h+i/3*2, position.y+3+j*h + j/3*2), h-1,h-1,temp);
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
    for(int i=0; i<fields.size(); ++i)
    {
        for(int j=0; j<fields[i].size(); ++j)
        {
            fields[i][j]->valid=true;
        }
    }


    for(int i=0; i<fields.size(); ++i)
    {
        for(int j=0; j<fields[i].size(); ++j)
        {
            if(fields[i][j]->getValue() == 0) continue;
            for(int k=j+1; k<fields[i].size(); ++k)
            {
                if(fields[i][j]->getValue() == fields[i][k]->getValue())
                {
                    fields[i][j]->valid = false;
                    fields[i][k]->valid = false;
                }
            }
        }
    }

    for(int i=0; i<fields.size(); ++i)
    {
        for(int j=0; j<fields[i].size(); ++j)
        {
            if(fields[j][i]->getValue() == 0) continue;

            for(int k=j+1; k<fields[i].size(); ++k)
            {
                if(fields[j][i]->getValue() == fields[k][i]->getValue())
                {
                    fields[j][i]->valid = false;
                    fields[k][i]->valid = false;
                }
            }
        }
    }

    for(int m=0;m<9;++m)
    {
        int i0 = 3*(int(m/3));
        int j0 = 3*(m%3);

        for(int k=0;k<9;++k)
        {
            int i1 = k/3 + i0;
            int j1 = k%3 + j0;
            if(fields[i1][j1]->getValue()==0) continue;

            for(int l=k+1;l<9;++l)
            {
                int i2 = l/3 + i0;
                int j2 = l%3 + j0;
                if(fields[i1][j1]->getValue() == fields[i2][j2]->getValue())
                {
                    fields[i1][j1]->valid = false;
                    fields[i2][j2]->valid = false;
                }
            }

        }

    }
    bool valid=true;
    for(int i=0; i<fields.size(); ++i)
    {
        for(int j=0; j<fields[i].size(); ++j)
        {
            if(!fields[i][j]->valid || fields[i][j]->getValue()==0) valid=false;
        }
    }
    return valid;
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
