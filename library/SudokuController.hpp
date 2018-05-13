#ifndef SUDOKUCONTROLLER_HPP_INCLUDED
#define SUDOKUCONTROLLER_HPP_INCLUDED

#include "GUI.hpp"
#include "WidgetGroup.hpp"
#include "Label.hpp"
#include "SudokuBox.hpp"
#include "MenuSelect.hpp"
#include "Button.hpp"

class SudokuController : public WidgetGroup{
    Label* status;
    SudokuBox* sudoku;
    MenuSelect* menu;
    Button* generator;
    void win();
    void generateBoard();
public:
    SudokuController(GUI* parent);
};

#endif // SUDOKUCONTROLLER_HPP_INCLUDED
