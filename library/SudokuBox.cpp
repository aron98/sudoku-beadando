#include "SudokuBox.hpp"

using namespace genv;
using namespace std;

SudokuBox::SudokuBox(GUI* parent, Coord coords, std::function<void()> _action, int _width, int _height) : Widget(parent,coords,_width,_height),action(_action){}

bool SudokuBox::loadMap(string filename){
    int h = gout.cascent() + gout.cdescent() + 7;
    ifstream input(filename.c_str());
    if(!input.good()) return false;
    vector<vector<int>> loadMatrix;
    for(int i = 0; i < 9; i++){
        stringstream ss;
        string str;
        getline(input,str);
        ss<<str;
        vector<int> r;
        for(int j = 0; j < 9; j++){
            int temp;
            ss>>temp;
            if(temp <0 || temp >9) temp=0;
            r.push_back(temp);
        }
        loadMatrix.push_back(r);
    }
    if(loadMatrix.size()!=9) return false;
    for(int i=0; i <9; i++){
        if(loadMatrix[i].size()!=9) return false;
    }
    fields.clear();
    for(int j = 0; j < 9; j++){
        vector<DigitBox*> r;
        for(int i = 0; i < 9; i++){
             DigitBox* d = new DigitBox(gui,Coord(position.x+3+i*h+i/3*2, position.y+3+j*h + j/3*2), h-1,h-1,loadMatrix[j][i]);
            r.push_back(d);
        }
        fields.push_back(r);
    }
    return true;
}

void SudokuBox::generator(int k){
    SudokuGenerator sudoku(k);
    loadMap("levels/generator.sudoku");
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

void SudokuBox::validate(){
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
    if(valid){
        action();
    }
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
