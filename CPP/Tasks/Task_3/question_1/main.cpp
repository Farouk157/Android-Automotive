#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

struct Point
{
    int x; 
    int y;
};


int main(void)
{
    srand(static_cast<unsigned int>(time(nullptr)));
    Point point;
    int i = 5;
    int u = 1;
    while(i)
    {
        point.x = rand()% 201 - 100; 
        point.y = rand()% 201 - 100;
        cout << "the point number[" << u<<"] = ("<<point.x<<", "<<point.y<<")\n";
        i--;
        u++;
    }
    

    return 0;
}