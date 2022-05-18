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

bool Day23::moveHome(int x, int y){
    if (!checkIfCanMakeItHome(x,y)) return false;

    char amphipod = map[x][y];
    int xValRoom = (amphipod - 64) * 2 + 1;
    if (y == 3){
        move(UP, x, y);
        y = y - 1;
        move(UP, x, y);
        y = y - 1;

    } else if (y == 2) {
        move(UP, x, y);
        y = y - 1;

    }

    int distToRoom = xValRoom - x;
    if (distToRoom > 0) { // moving to the right
        for (int i = x; i < xValRoom; i++){
            move(RIGHT, x, y);
            x = x + 1;
        }
    } else { //moving to the left
        while (x > xValRoom){
            move(LEFT, x, y);
            x = x - 1;
        }
//        for (int i = xValRoom; i < x; i++){
//
//        }
    }

    move(DOWN, x, y);
    y = y + 1;
    if (y == 2) move(DOWN, x, y);
    return true;


}

bool Day23::moveHome2(int x, int y){
    char amphipod = map[x][y];
    int xValRoom = (amphipod - 64) * 2 + 1;
    map[x][y] = '.';
    if (map[xValRoom][3] == '.') {
        map[xValRoom][3] = amphipod;
    } else {
        map[xValRoom][2] = amphipod;
    }
    return true;
}

int Day23::getHallwayXCoor(int whichHall){
    if (whichHall == 1) return 1;
    if (whichHall == 2) return 2;
    if (whichHall == 3) return 4;
    if (whichHall == 4) return 6;
    if (whichHall == 5) return 8;
    if (whichHall == 6) return 10;
    if (whichHall == 7) return 11;

}

bool Day23::checkIfCanMoveToHallway(int x, int y, int whichHall){

    if (y == 3) {
        if (map[x][2] != '.') return false;
        if (map[x][1] != '.') return false;
    } else if (y == 2){
        if (map[x][1] != '.') return false;
    }
    //int xValRoom = (map[x][y] - 64) * 2 + 1;
    int distToRoom = x - getHallwayXCoor(whichHall);
    int dist = abs(distToRoom);
    if (distToRoom < 0) { // moving to the right
        for (int i = 0; i < dist; i++){
            if (!checkIfValidMove(RIGHT, x, 1)) return false;
            x = x + 1;
        }
    } else { //moving to the left

        for (int i = 0; i < distToRoom; i++){
            if (!checkIfValidMove(LEFT, x, 1)) return false;
            x = x - 1;
        }
    }
    return true;

}

bool Day23::moveToHallway(int x, int y, int whichHall){
/* //    #############
//    #12 3 4 5 67#
//    ###A#B#C#D###
//      #A#B#C#D#
//      ######### */
    if (!checkIfCanMoveToHallway(x, y, whichHall)) return false;
    //moveToHallway2(x, y, whichHall);
    //return true;
    bool keepGoing = true;
    while (keepGoing){
        keepGoing = move(UP, x, y);
        if (keepGoing) y = y - 1;
    }

    //int xValRoom = (map[x][y] - 64) * 2 + 1;
    int distToRoom = x - getHallwayXCoor(whichHall);
    if (distToRoom < 0) { // moving to the right
        for (int i = x; i < getHallwayXCoor(whichHall); i++){
            move(RIGHT, x, y);
            x = x + 1;
        }
    } else { //moving to the left
        for (int i = 0; i < distToRoom; i++){
            move(LEFT, x, y);
            x = x - 1;
        }
    }
    return true;
}

bool Day23::checkIfCanMakeItHome(int x, int y){
    char amphipod = map[x][y];

    //check if it can get out of the room if it's not in the hall.
    if (y != 1){
        if (y == 2){
            if (map[x][1] != '.') return false;
        } else if (y == 3) {
            if (map[x][1] != '.') return false;
            if (map[x][2] != '.') return false;
        }
    }

    //check room is empty
    // 'A' = 65 (char val) --> (3,2) (3,3) // 65 -> 3  (65 - 64) * 2 + 1
    int xValRoom = (amphipod - 64) * 2 + 1;
    if ( (map[xValRoom][3] == '.' || map[xValRoom][3] == amphipod) ){
        if ((map[xValRoom][2] == '.')){
            int var = 0;
        } else {
            return false;
        }
        //the room is empty or only has its buddy
    } else {
        return false;
    }

    //check if it is a straight shot to the room
    int distToRoom = xValRoom - x;
    if (distToRoom > 0) { // moving to the right
        for (int i = 0; i < distToRoom; i++){
            if (map[x+i+1][1] != '.'){
                return false;
            }
        }
    } else { //moving to the left
        for (int i = xValRoom; i < x; i++){
            if (map[i][1] != '.'){
                return false;
            }
        }
    }
    return true;
}

bool Day23::checkIfValidMove(direction dir, int x, int y){
    if (dir == UP){
        if (map[x][y-1] != '.'){
            return false;
        } else {
            return true;
        }
    } else if (dir == DOWN){
        if (map[x][y+1] != '.'){
            return false;
        } else {
            return true;
        }
    } else if (dir == LEFT){
        if (map[x-1][y] != '.'){
            return false;
        } else {
            return true;
        }
    } else if (dir == RIGHT){
        char var = map[x+1][y];
        if (map[x+1][y] != '.'){
            return false;
        } else {
            return true;
        }
    }
    return true;
}

void Day23::addEnergy(char amphipod){
    energyTotal += energy[amphipod];
}

bool Day23::move(direction dir, int x, int y){
    char currAmphipod = map[x][y];

    if (!checkIfValidMove(dir, x, y)){
        //cout << "error";
        return false;
    }

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

    //printMap();
    return true;
}

int Day23::solveExample(){
    //for each of the 8 amphipods
        // it can go to 7 different hallway spots
        // in any order
        // and back home
        // in any order
    //after 1 amphipod moves to its home or a hallway
    //any other amphipod can move to its home or a hallway
    //and any other amphipod can move to its home or a hallway
    //but it's in any order...
    // 1 2 3
    // 1 3 2
    // 2 1 3
    // 2 3 1
    // 3
    cout << "Starting: " << endl;
    printMap();
    moveToHallway(7,2,3);  //B to hallway
    printMap();
    moveHome(5,2); // C to home
    printMap();
    moveToHallway(5,3,4); //D to hallway
    printMap();
    moveHome(4,1); // B to home
    printMap();
    moveHome(3,2); // B to home
    printMap();
    moveToHallway(9, 2, 5); // D out
    printMap();
    moveToHallway(9, 3, 6); // A out
    printMap();
    moveHome(8,1); // D to home
    printMap();
    moveHome(6,1); // other D to home
    printMap();
    moveHome(10,1); // A to home
    printMap();
    cout << energyTotal << endl;

    return 0;

}

void Day23::keepTrackSomehow(){
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char currChar = map[j][i];
            if (currChar != '.' && currChar != '#'){
                cout << currChar << " is at " << j << ", " << i << endl;
            }
        }
    }
}


vector<vector<int>> Day23::amphipodsWhoAreAllowedToMove(){
    vector<vector<int>> possibleSpots;

    //top of room
    possibleSpots.push_back({2, 3});
    possibleSpots.push_back({2, 5});
    possibleSpots.push_back({2, 7});
    possibleSpots.push_back({2, 9});
    //bottom of room
    possibleSpots.push_back({2, 3});
    possibleSpots.push_back({2, 5});
    possibleSpots.push_back({2, 7});
    possibleSpots.push_back({2, 9});
    //hallway spots
    possibleSpots.push_back({1, 1});
    possibleSpots.push_back({1, 2});
    possibleSpots.push_back({1, 4});
    possibleSpots.push_back({1, 6});
    possibleSpots.push_back({1, 8});
    possibleSpots.push_back({1, 10});
    possibleSpots.push_back({1, 11});
    return possibleSpots;
}

void Day23::solveMySolution(){
    //get c in the hallway -- probably @ 6
    moveToHallway(9,2,6);
    printMap();
    cout << energyTotal << endl;

    //get a in the hallway -- probably @ 1
    moveToHallway(9,3,1);
    printMap();
    cout << energyTotal << endl;

    //get d home (from row 2)
    moveHome(5,2);
    printMap();
    cout << energyTotal << endl;

    //get b in the hallway -- probably @ 3
    moveToHallway(7,2,3);
    printMap();
    cout << energyTotal << endl;

    //get d home (from row 3)
    moveHome(7,3);
    printMap();
    cout << energyTotal << endl;


    //get other c home (from row 2)
    moveHome(5,3);
    printMap();
    cout << energyTotal << endl;

    //get c home (from hallway)
    moveHome(10,1);
    printMap();
    cout << energyTotal << endl;

    //get b home from hallway
    moveHome(4,1);
    printMap();
    cout << energyTotal << endl;

    //get a in hallway (from row 1 probably @ 2)
    moveToHallway(3,2,2);
    printMap();
    cout << energyTotal << endl;

    //move b home from row 1
    moveHome(3,3);
    printMap();
    cout << energyTotal << endl;

    //move a home from hallway 2
    moveHome(2,1);
    printMap();
    cout << energyTotal << endl;

    //move a home from hallway 1
    moveHome(1,1);
    printMap();
    cout << energyTotal << endl;
    //13000 is too low
    //13338 is too high
}

void Day23::solve(){
    //solveHelper();
    keepTrackSomehow();
    solveMySolution();

}

//never stop on the space immediately outside any room
//can't go into any room besides its own -- and only if it's empty or contains its buddy
//After it gets to a spot in the hallway, it's stuck there until it can move in a room

