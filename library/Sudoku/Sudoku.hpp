#ifndef SUDOKU_HPP_INCLUDED
#define SUDOKU_HPP_INCLUDED

#include "Widget.hpp"

#include <vector>

class Sudoku : public Widget{
    std::vector<int> boxes;
};

#endif // SUDOKU_HPP_INCLUDED
