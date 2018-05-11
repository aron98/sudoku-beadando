#ifndef SUDOKU_HPP_INCLUDED
#define SUDOKU_HPP_INCLUDED

#include "graphics.hpp"
#include "GUI.hpp"
#include "Widget.hpp"

#include <vector>

class Sudoku : public Widget{
    std::vector<int> boxes;
public:
    Sudoku(GUI* parent, Coord coords, int _width, int _height);
};

#endif // SUDOKU_HPP_INCLUDED
