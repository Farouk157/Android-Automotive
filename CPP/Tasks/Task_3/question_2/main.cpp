
#include <iostream>
#include "vertex.hpp"




int main(void)
{
    Vertex v;

    // Access and print the vertex using member functions
    std::cout << "Vertex coordinates:" << std::endl;

    int i = 5;
    while(i)
    {
        std::cout << "x = " << v.get_x() << ", y = " << v.get_y() << std::endl;
        std::cout << "String representation: " << v.toString() << std::endl;
        i--;
    }
    

    return 0;
}

