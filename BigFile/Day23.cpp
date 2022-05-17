//
// Created by rebek on 5/17/2022.
//

#include "Day23.h"



void Day23::printMap(){
    cout << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << map[j][i];
        }
        cout << endl;
    }
    cout << endl;
}


bool Day23::checkIfValidMove(direction dir, int x, int y){
    if (dir == UP){
        if (map[x][y-1] == '.'){
            return true;
        }
    } else if (dir == DOWN){
        if (map[x][y+1] == '.'){
            return true;
        }
    } else if (dir == LEFT){
        if (map[x-1][y] == '.'){
            return true;
        }
    } else if (dir == RIGHT){
        if (map[x+1][y] == '.'){
            return true;
        }
    }
    cout << "bad move" << endl;
    return false;
}

void Day23::addEnergy(char amphipod){
    energyTotal += energy[amphipod];
}

bool Day23::move(direction dir, int x, int y){
    char currAmphipod = map[x][y];
    cout << "curr " << currAmphipod << endl;
    if (!checkIfValidMove(dir, x, y))  return false;

//    char currAmphipod = map[x][y];

    addEnergy(currAmphipod);

    map[x][y] = '.';

    if (dir == UP){
        map[x][y-1] = currAmphipod;
    } else if (dir == DOWN){
        map[x][y+1] = currAmphipod;
    } else if (dir == LEFT){
        map[x-1][y] = currAmphipod;
    } else if (dir == RIGHT){
        map[x+1][y] = currAmphipod;
    }
    return true;
}

void Day23::solve(){

    printMap();
    //map[3][2] = 'X';
    move(UP, 3, 2);

    printMap();
    move(RIGHT, 3, 1);
    printMap();

}

//never stop on the space immediately outside any room
//can't go into any room besides its own -- and only if it's empty or contains its buddy
//After it gets to a spot in the hallway, it's stuck there until it can move in a room

