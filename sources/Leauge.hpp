#pragma once
#include <vector>
#include "Game.hpp"
#include "Schedule.hpp"

class Leauge
{
private:
    
    Team * teams[20];
    Schedule * sc;

public:
    
    Leauge();
    void start();
    
    //statistics
    void printStats();
    void topTeams(int num);
    void longestWinStreak();
    void longestLoseStreak();
    void positiveBalnce();
    void negetiveBalnce();
    void botTeams(int num);
};




