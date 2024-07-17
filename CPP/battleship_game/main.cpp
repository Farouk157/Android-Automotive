#include <iostream>
#include "battleship.hpp"


int main(void)
{
    Battleship bat;
    int x , y;
    bool temp = false;

    std::cout <<"Welcome to battleship!\n";
    std::cout <<"you have 5 guesses to find the battleship hidden in 5x5 grid\n";

    while(bat.game_over())
    {
        std::cout <<"Enter you guess (row then column): ";
        std::cin >> x >> y;
        
        temp = bat.guess(x, y);
        if(temp == true )
        {
            break;
        }
    }


    return 0;
}