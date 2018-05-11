#ifndef GLOBAL_HPP_INCLUDED
#define GLOBAL_HPP_INCLUDED

struct Coord{
    int x,y;
    Coord(int _x = 0, int _y = 0);
};

Coord operator- (const Coord& c1, const Coord& c2);
Coord operator+ (const Coord& c1, const Coord& c2);
int operator* (const Coord& c1, const Coord& c2);

#endif // GLOBAL_HPP_INCLUDED
