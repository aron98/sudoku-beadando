#include "SudokuController.hpp"
#include "SudokuBox.hpp"
#include "GUI.hpp"
#include "Label.hpp"

using namespace genv;
using namespace std;

SudokuController::SudokuController(GUI* parent):WidgetGroup(parent){
    int h = gout.cascent() + gout.cdescent() + 7;
    status = new Label(gui,Coord(10+3+9*h+9/3*2+5,10),100,40,"Solve the puzzle");
    widgets.push_back(status);
    sudoku = new SudokuBox(gui, Coord(10,10), "level.sudoku",[this](){win();},3+9*h+9/3*2,3+9*h+9/3*2);
    widgets.push_back(sudoku);
}

void SudokuController::win(){
    status->changeVal("You Win!");
}
