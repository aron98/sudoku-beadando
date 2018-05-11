#ifndef SUDOKUBOX_H_INCLUDED
#define SUDOKUBOX_H_INCLUDED

//#include "Widget.hpp"
#include "DigitBox.hpp"

#include <vector>

class SudokuBox : public Widget{
   std::vector<std::vector<DigitBox*>> fields;
public:
    SudokuBox(GUI* parent, Coord coords, std::vector<std::vector<int>> _fields, int _width=0, int _height=0);
    void eventHandler(const genv::event& ev);
    void draw(genv::canvas& out);
    bool validate();
    ~SudokuBox();
};

#endif // SUDOKUBOX_H_INCLUDED
