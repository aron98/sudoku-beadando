#include "SudokuController.hpp"
#include "SudokuBox.hpp"
#include "GUI.hpp"
#include "Label.hpp"

using namespace genv;
using namespace std;

SudokuController::SudokuController(GUI* parent):WidgetGroup(parent){
    int h = gout.cascent() + gout.cdescent() + 7;
    status = new Label(gui,Coord(10+3+9*h+9/3*2+5,10),200,40,"Solve the puzzle!");
    widgets.push_back(status);
    sudoku = new SudokuBox(gui, Coord(10,10), "levels/level.sudoku",[this](){win();},3+9*h+9/3*2,3+9*h+9/3*2);
    widgets.push_back(sudoku);
    vector<string> items;
    items.push_back("Easy");
    items.push_back("Medium");
    items.push_back("Hard");
    menu = new MenuSelect(gui,Coord(10+3+9*h+9/3*2+5,10+40+20),95,40,items,3);
    widgets.push_back(menu);
    generator = new Button(gui,Coord(10+3+9*h+9/3*2+5+105,10+40+20),95,40,[this](){generateBoard();},"Generate!",true);
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
