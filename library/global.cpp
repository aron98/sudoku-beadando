#include "global.hpp"

using namespace std;

Coord::Coord(int _x, int _y){
    x=_x;
    y=_y;
}

Coord operator- (const Coord& c1, const Coord& c2){
    return Coord(c1.x-c2.x, c1.y-c2.y);
}

Coord operator+ (const Coord& c1, const Coord& c2){
    return Coord(c1.x+c2.x, c1.y+c2.y);
}

int operator* (const Coord& c1, const Coord& c2){
    return c1.x*c2.x+c1.y*c2.y;
}
