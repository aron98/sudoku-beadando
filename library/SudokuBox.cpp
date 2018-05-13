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
    action();
}

void SudokuBox::draw(canvas& out){
    out<<move_to(position.x,position.y)<<borderColor<<box(width, height)<<move_to(position.x+1,position.y+1)<<backgroundColor<<box(width-2,height-2);
    for(int i = 0; i < fields.size(); i++){
        for(int j = 0; j<fields[i].size(); j++){
            fields[i][j]->draw(out);
        }
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
