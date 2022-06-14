#pragma once
#include <string>
#include <random>
#include <iomanip>
#include "Team.hpp"
#include <iostream>

using std::cout;
using std::cin;
using std::string;


class Game
{
private:
    Team * home, *out;
public:

    Game(Team *home,Team * out);
    
    bool winner; // 0 for home 1 for out
    int pointsHome, pointsOut;
    
    
};


