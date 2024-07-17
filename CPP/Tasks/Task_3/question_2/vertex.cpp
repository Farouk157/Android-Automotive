#include "vertex.hpp"
#include <cstdlib>
#include <ctime>
#include <string>

Vertex:: Vertex()
{
    srand(static_cast<unsigned int>(time(nullptr)));
}

void Vertex:: set_x()
{
    x = rand()% 201 - 100;
}

void Vertex:: set_y()
{
    y = rand()% 201 - 100;
}


int Vertex:: get_x()
{
    set_x();
    return x;
}
int Vertex:: get_y()
{
    set_y();
    return y;
}

std::string Vertex::toString(){
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}


