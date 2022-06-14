#include "Team.hpp"


Team::Team(double skill, string name):skill{skill}, name{name}, pointsScored{0}, winStreak{0}
, loseStreak{0},wins{0}, loses{0}{}

string Team::getName(){return this->name;}
double Team::getSkill(){return this->skill;}

    void Team::won(int scored, int suffered){
        pointsScored += scored;
        pointsSuffered += suffered;

        winStreak++;
        LongestwinStreak = (winStreak > LongestwinStreak) ? winStreak : LongestwinStreak;
        resetLoses();
    }

    void Team::lost(int scored, int suffered){
        pointsScored += scored;
        pointsSuffered += suffered;
        loseStreak++;
        longestloseStreak = (loseStreak > longestloseStreak) ? loseStreak : longestloseStreak;
        resetWins();
    }

    void Team::calcRatio(){
        winRatio = (double) wins / 39;
    }

