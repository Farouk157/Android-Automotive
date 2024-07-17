#include <iostream>
#include "battleship.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>


Battleship:: Battleship() : v(5, std::vector<bool>(5,0))
{
    srand(static_cast<unsigned int>(time(nullptr)));
    guesses = 0;
    max_guesses = 5;
    location_x = rand() %6; 
    location_y = rand() %6;
    v[location_x][location_y] = true;
}

Battleship:: ~Battleship()
{

}

bool Battleship:: guess(int x, int y)
{
    
    // if((x > 5) || (y > 5))
    // {
    //     throw std::string ("sorry out of game range");
    // }

    guesses++;
    
    if(v[x][y] == true)
    {
        std::cout << "you won in: "<<guesses<<" guesses!\n";
        return true;
    }
    
    if( (x == location_x) && (y != location_y))
    {
        std::cout << "you missed ... you have " << max_guesses-guesses<<" guesses left\n"; 
        std::cout << "you are at the right row only\n";
        return false; 
    }

    if( (x != location_x) && (y == location_y))
    {
        std::cout << "you missed ... you have " << max_guesses-guesses<<" guesses left\n"; 
        std::cout<<"you are at the right column only\n";
        return false;
    }      

    if( (x != location_x) && (y != location_y))
    {
        std::cout << "you missed ... you have " << max_guesses-guesses<<" guesses left\n"; 
        return false;
    }

    return true;
    
}

bool Battleship:: game_over() const
{
    if(guesses == max_guesses)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int Battleship:: get_guesses() const
{
    return guesses;
}