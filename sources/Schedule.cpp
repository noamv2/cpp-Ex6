#include "Schedule.hpp"

Schedule::Schedule(Team ** t):teams{t}{
}

void resertIndices(int arr[]);

void Schedule::startSeason(){

    //hve the groups play a round robin
    cout<<"Start series 1\n";
    roundRobin();
    cout<<"Start series 2\n";
    roundRobin();
}

void Schedule::roundRobin(){
    resertIndices(indices);
    for(int i=0; i < 19; i++){
        play();
    }
}

void Schedule::play(){
    
    // play one round
    for(int i = 0 ; i < 10; i++){
        Game(teams[indices[i]],teams[indices[19 - i]]);
    }
    //indecrement all the indices but 0 in one array spot 
    int temp = indices[19];
    

    for(int i=19; i > 1; i--){

        indices[i] = indices[i - 1];
    }
    indices[1] = temp;
}

void resertIndices(int arr[]){
    for(int i = 0 ; i < 20; i++){
        arr[i] = i;
    }
}