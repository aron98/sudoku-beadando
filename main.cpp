#include "graphics.hpp"
#include "library/GUI.hpp"
#include "library/SudokuController.hpp"

#include <stdlib.h>
#include <time.h>

using namespace genv;

int main()
{
    srand(time(NULL));
    GUI * g = new GUI(450,400);
    SudokuController* sudoku = new SudokuController(g);
    g->addWidget(sudoku);
    g->eventLoop();
    delete g;
    return 0;
}
