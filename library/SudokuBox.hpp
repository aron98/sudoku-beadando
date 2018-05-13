#ifndef SUDOKUBOX_H_INCLUDED
#define SUDOKUBOX_H_INCLUDED

#include "Widget.hpp"
#include "DigitBox.hpp"
#include "SudokuGenerator.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <functional>

class SudokuBox : public Widget{
   std::vector<std::vector<DigitBox*>> fields;
   std::function<void()> action;
public:
    SudokuBox(GUI* parent, Coord coords, std::function<void()> _action, int _width=0, int _height=0);
    void eventHandler(const genv::event& ev);
    void draw(genv::canvas& out);
    void validate();
    bool loadMap(std::string filename);
    void generator(int k);
    ~SudokuBox();
};

#endif // SUDOKUBOX_H_INCLUDED
