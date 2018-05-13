#include "SudokuController.hpp"

using namespace genv;
using namespace std;

SudokuController::SudokuController(GUI* parent):WidgetGroup(parent){
    int h = gout.cascent() + gout.cdescent() + 7;
    status = new Label(gui,Coord(10+3+9*h+9/3*2+5,10),250,40,"Solve the puzzle!");
    widgets.push_back(status);
    sudoku = new SudokuBox(gui, Coord(10,10),[this](){validate();},3+9*h+9/3*2,3+9*h+9/3*2);
    sudoku->generator(30);

    textBox = new InputField(gui,Coord(10+3+9*h+9/3*2+5,10+40+20),165,40,"example.sudoku");
    widgets.push_back(textBox);
    loader = new Button(gui,Coord(10+3+9*h+9/3*2+5+175,10+40+20),75,40,[this](){loadBoard();},"Load!",true);
    widgets.push_back(loader);

    widgets.push_back(sudoku);
    vector<string> items;
    items.push_back("Easy");
    items.push_back("Medium");
    items.push_back("Hard");
    menu = new MenuSelect(gui,Coord(10+3+9*h+9/3*2+5,10+40+20+40+20),120,40,items,3);
    widgets.push_back(menu);
    generator = new Button(gui,Coord(10+3+9*h+9/3*2+5+130,10+40+20+40+20),120,40,[this](){generateBoard();},"Generate!",true);
    widgets.push_back(generator);
}

void SudokuController::win(){
    status->changeVal("Well done!");
}

void SudokuController::generateBoard(){
    status->changeVal("Solve the puzzle!");
    if(menu->getValue()=="Easy") sudoku->generator(30);
    else if(menu->getValue()=="Medium") sudoku->generator(40);
    else sudoku->generator(50);
}

void SudokuController::loadBoard(){
    if(!sudoku->loadMap("levels/"+textBox->getValue())) status->changeVal("File not found, or bad format!");
    else status->changeVal("Solve the puzzle!");
}

void SudokuController::validate(){
    for(int i=0; i<sudoku->fields.size(); ++i)
    {
        for(int j=0; j<sudoku->fields[i].size(); ++j)
        {
            sudoku->fields[i][j]->valid=true;
        }
    }


    for(int i=0; i<sudoku->fields.size(); ++i)
    {
        for(int j=0; j<sudoku->fields[i].size(); ++j)
        {
            if(sudoku->fields[i][j]->getValue() == 0) continue;
            for(int k=j+1; k<sudoku->fields[i].size(); ++k)
            {
                if(sudoku->fields[i][j]->getValue() == sudoku->fields[i][k]->getValue())
                {
                    sudoku->fields[i][j]->valid = false;
                    sudoku->fields[i][k]->valid = false;
                }
            }
        }
    }

    for(int i=0; i<sudoku->fields.size(); ++i)
    {
        for(int j=0; j<sudoku->fields[i].size(); ++j)
        {
            if(sudoku->fields[j][i]->getValue() == 0) continue;

            for(int k=j+1; k<sudoku->fields[i].size(); ++k)
            {
                if(sudoku->fields[j][i]->getValue() == sudoku->fields[k][i]->getValue())
                {
                    sudoku->fields[j][i]->valid = false;
                    sudoku->fields[k][i]->valid = false;
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
            if(sudoku->fields[i1][j1]->getValue()==0) continue;

            for(int l=k+1;l<9;++l)
            {
                int i2 = l/3 + i0;
                int j2 = l%3 + j0;
                if(sudoku->fields[i1][j1]->getValue() == sudoku->fields[i2][j2]->getValue())
                {
                    sudoku->fields[i1][j1]->valid = false;
                    sudoku->fields[i2][j2]->valid = false;
                }
            }

        }

    }
    bool valid=true;
    for(int i=0; i<sudoku->fields.size(); ++i)
    {
        for(int j=0; j<sudoku->fields[i].size(); ++j)
        {
            if(!sudoku->fields[i][j]->valid || sudoku->fields[i][j]->getValue()==0) valid=false;
        }
    }
    if(valid){
        win();
    }
}
