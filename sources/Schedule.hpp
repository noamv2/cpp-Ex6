#pragma once
#include "Game.hpp"

class Schedule
{
private:
    Team ** teams;
     /*saves the schedule for the current round
    the group in index 0 play against 19
    1 vs 18
    2 vs 17
     ...
    9 vs 10
     */
    int indices[20];
    void roundRobin();
    void  play();
    
public:
    
    Schedule(Team ** g);
    void startSeason();

};
