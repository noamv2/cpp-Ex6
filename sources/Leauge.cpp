#include<algorithm>
#include "Leauge.hpp"

std::vector<string> names {

  "Boston Celtics", "Brooklyn Nets" , "New York Knicks" , "Philadelphia 76ers",
  "Toronto Raptors", "Chicago Bulls" , "Cleveland Cavaliers" , "Detroit Pistons",
  "Indiana Pacers", "Milwaukee Bucks" , "Atlanta Hawks" , "Charlotte Hornets",
  "Miami Heat", "Orlando Magic" , "Washington Wizards" , "Denver Nuggets",
  "Golden State Warriors", "Dallas Mavericks" , "Minnesota Timberwolves" , "LA Clippers"
};

bool cmp(Team * t1, Team *t2){

    //sort by win ratio as primary condition
    if(t1->getRatio() > t2->getRatio()) return true;
    if(t1->getRatio() < t2->getRatio()) return false;
    
    //secodery condition points diff

    return (t1->pointsDiff() > t2->pointsDiff()); 
}

Leauge::Leauge(){

    // Generate random teams
    for(size_t i =0; i <20; i++){
        teams[i] = new Team((double) rand() / (RAND_MAX), names.at(i));
    }
    sc = new Schedule(teams);
}

void Leauge::start(){

    sc->startSeason();
    //calculate win rate
    for(auto t: teams){
        t->calcRatio();
    }
    // sort by win ratio and points balance
    std::sort(teams, teams + 20, cmp);
}

void Leauge::printStats(){

    for(Team* t: teams){

        cout<<t->getName()<<" | Wins:"<<t->wins<<" | Loses:"<<t->loses<<" | Win ratio:"<<t->getRatio()
        <<" | "<<"points balance:"<<t->pointsDiff()<<std::endl;  
    }
}


    void Leauge::topTeams(int num){

        num = std::min(num, 20);
        for(int i = 0 ; i < num; i++){
            cout<<i<<") "<<teams[i]->getName()<<std::endl;
        }

    }
    void Leauge::longestWinStreak(){

        int i = 0, longest = -1, index = 0;
        for(; i < 20; i++){
            
            if(teams[i]->getWinStreak() > longest){
                longest = teams[i]->getWinStreak();
                index = i;
            }

        }
            cout<<"The longest win streak is: "<<longest<<", and was set by "<<teams[index]->getName()<<std::endl;
    }
    void Leauge::longestLoseStreak(){

        int i = 0, longest = -1, index = 0;
        for(; i < 20; i++){
            
            if(teams[i]->getLoseStreak() > longest){
                longest = teams[i]->getLoseStreak();
                index = i;
            }

        }
            cout<<"The longest Lose streak is: "<<longest<<", and was set by "<<teams[index]->getName()<<std::endl;
    }
 
    void Leauge::positiveBalnce(){

        int posTeams = 0;

        for(int i = 0; i < 20; i++){
            if(teams[i]->pointsDiff() > 0) posTeams++;
        }        

        cout<<posTeams<<" teams have positive points balance"<<std::endl;
    }

    void Leauge::negetiveBalnce(){

        int posTeams = 0;

        for(int i = 0; i < 20; i++){
            if(teams[i]->pointsDiff() < 0) posTeams++;
        }        

        cout<<posTeams<<" teams have negetive points balance"<<std::endl;
    }
    void Leauge::botTeams(int num){
        
        num = std::min(num, 20);
        for(int i = 0 ; i < num; i++){
            cout<<i<<") "<<teams[19 - i]->getName()<<std::endl;
        } 
    }