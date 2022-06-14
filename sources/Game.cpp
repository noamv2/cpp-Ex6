#include "Game.hpp"


Game::Game(Team *home,Team * out):home{home},out{out}, pointsHome{55}, pointsOut{50}{


    //calculate the results
    double oskill = out->getSkill();
    double homeskill = home->getSkill();
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::normal_distribution<> score{27, 7};
    std::normal_distribution<> bonus{5, 3};

    int ran;
    //calculate base score
    do{
        ran = score(gen);
    }while(ran > 45);
    pointsHome += ran;
    do{
        ran = score(gen);
    }while(ran > 50);
    pointsOut += ran;

    //calculate bocus score
     do{
        ran = score(gen);
    }while(ran > 10);
    pointsHome += ran * home->getSkill();   

    do{
        ran = score(gen);
    }while(ran > 10);
    pointsOut += ran * out->getSkill();

    cout<<home->getName()<<"[Home]: "<<pointsHome<<std::endl;
    cout<<out->getName()<<"[Out]: "<<pointsOut<<"\n~~~~~~~~~~~~~~~~~"<<std::endl;

    if(pointsHome >= pointsOut){
        winner = 0;
        home->wins++;
        out->loses++;
        home->won(pointsHome, pointsOut);
        out->lost(pointsOut, pointsHome);
    }
    else{
        winner = 1;
        home->loses++;
        out->wins++;
        home->lost(pointsHome, pointsOut);
        out->won(pointsOut, pointsHome);
    }

    
    
}