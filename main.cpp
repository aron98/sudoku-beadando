#include "graphics.hpp"
#include "library/GUI.hpp"
#include "library/SudokuController.hpp"

using namespace genv;

int main()
{
    GUI * g = new GUI();
    SudokuController* sudoku = new SudokuController(g);
    g->addWidget(sudoku);
    g->eventLoop();
    delete g;
    return 0;
}
