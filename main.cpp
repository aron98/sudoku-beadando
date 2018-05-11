#include "graphics.hpp"
#include "library/GUI.hpp"

int main()
{
    GUI * g = new GUI();
    g->eventLoop();
    delete g;
    return 0;
}
