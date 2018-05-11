#include "graphics.hpp"
#include "GUI.hpp"
#include "Widget.hpp"
#include "Sudoku.hpp"

using namespace genv;
using namespace std;

Sudoku::Sudoku(GUI* parent, Coord coords) : Widget(parent,coords,227,227){
    backgroundColor=gui->getBackgroundColor();
    borderColor=gui->getBorderColor();
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){

        }
    }
}

void clearColor(){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j)
        {
            //int d = board->fields[i][j]->GetValue()+1;
           fields[i][j]->setStatus(false);
            //else board->fields[i][j]->SetStatus(0);
        }
    }
}
