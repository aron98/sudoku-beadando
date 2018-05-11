#ifndef SUDOKU_HPP_INCLUDED
#define SUDOKU_HPP_INCLUDED

#include "graphics.hpp"
#include "GUI.hpp"
#include "Widget.hpp"
#include "Digitbox.hpp"

#include <vector>

class Sudoku : public Widget{
    vector<vector<Digitbox*>> fields;
public:
    Sudoku(GUI* parent, Coord coords, int _width, int _height);
    void eventHandler(const genv::event& ev);
    void draw();
    void clearColor();
};

#endif // SUDOKU_HPP_INCLUDED
