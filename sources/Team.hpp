#include <string>
#pragma once
using std::string;

class Team
{
private:
    
    string name;    
    double skill, winRatio;
    int LongestwinStreak, longestloseStreak;
    int winStreak, loseStreak;
    int pointsScored, pointsSuffered;
    

public:
     
    Team(double skill, string name);
    int wins, loses;
    // getters/setters
    string getName();
    double getSkill();
    double getRatio(){return winRatio;}
    int pointsDiff(){return pointsScored - pointsSuffered;}
    int getWinStreak(){return LongestwinStreak;}
    int getLoseStreak(){return longestloseStreak;}

    void resetWins(){winStreak = 0;}
    void resetLoses() {loseStreak = 0;}
    
    void won(int scored, int suffered);
    void lost(int scored, int suffered);
    void calcRatio();
};


