#ifndef SUDOKUCONTROLLER_HPP_INCLUDED
#define SUDOKUCONTROLLER_HPP_INCLUDED

#include "WidgetGroup.hpp"
#include "Label.hpp"
#include "SudokuBox.hpp"
#include "MenuSelect.hpp"
#include "Button.hpp"
#include "InputField.hpp"

class SudokuController : public WidgetGroup{
    Label* status;
    SudokuBox* sudoku;
    InputField* textBox;
    Button* loader;
    MenuSelect* menu;
    Button* generator;
    void win();
    void generateBoard();
    void loadBoard();
    void validate();
public:
    SudokuController(GUI* parent);
};

#endif // SUDOKUCONTROLLER_HPP_INCLUDED
