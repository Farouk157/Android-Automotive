#ifndef BATTLE_H
#define BATTLE_H

#include <vector>


class Battleship
{
    private:
        std::vector<std::vector<bool>> v; 
        int guesses;
        int max_guesses;
        int location_x;
        int location_y;

    public:
    Battleship();
    ~Battleship();
    bool guess(int x, int y);
    bool game_over() const;
    int get_guesses() const;


};


#endif