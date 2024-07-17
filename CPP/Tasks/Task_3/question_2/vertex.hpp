#ifndef VERTEX_H
#define VERTEX_H

#include <string>

class Vertex
{
    private:
        int x;
        int y;

        void set_x();
        void set_y();
    public:
        Vertex();
        int get_x();
        int get_y();
        std::string toString();
};

#endif