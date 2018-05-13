#ifndef SUDOKUCONTROLLER_HPP_INCLUDED
#define SUDOKUCONTROLLER_HPP_INCLUDED

#include "WidgetGroup.hpp"
#include "GUI.hpp"
#include "Label.hpp"
#include "SudokuBox.hpp"

class SudokuController : public WidgetGroup{
    Label* status;
    SudokuBox* sudoku;
    void win();
public:
    SudokuController(GUI* parent);
};

#endif // SUDOKUCONTROLLER_HPP_INCLUDED
