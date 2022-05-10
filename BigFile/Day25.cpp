//
// Created by rebek on 5/10/2022.
//

#include "Day25.h"


void Day25::printMap() {
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}

bool Day25::checkIfNewSpotIsEmpty(int heightSpot, int widthSpot, string dir){
    if (dir == "east"){
        if (map[heightSpot][ (widthSpot+1) % width] == '.'){
            return true;
        } else {
            return false;
        }
    } else if (dir == "south"){
        if (map[(heightSpot+1)%height][widthSpot] == '.'){
            return true;
        } else {
            return false;
        }
    } else {
        cout << "problem!";
        return true;
    }
}

void Day25::moveEast(){
    char newMap[height][width];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++) {
            if (map[i][j] == 'v'){
                newMap[i][j] = 'v';
            } else {
                newMap[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (map[i][j] == '>'){
                if (checkIfNewSpotIsEmpty(i, j, "east")){
                    newMap[i][(j+1) % width] = '>';
                } else {
                    newMap[i][j] = '>';
                }
            }
        }
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            map[i][j] = newMap[i][j];
        }
    }


}


void Day25::moveSouth(){
    char newMap[height][width];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++) {
            if (map[i][j] == '>'){
                newMap[i][j] = '>';
            } else {
                newMap[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (map[i][j] == 'v'){
                if (checkIfNewSpotIsEmpty(i, j, "south")){
                    newMap[(i + 1) % height][j] = 'v';
                } else {
                    newMap[i][j] = 'v';
                }
            }
        }
    }

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            map[i][j] = newMap[i][j];
        }
    }


}

bool Day25::checkIfSame(vector<vector<char>> currMap){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (map[i][j] != currMap[i][j]) return false;
        }
    }
    return true;
}



int Day25::solve(){
    int i = 0;
    while (true){
        vector<vector<char>> prevMap = map;
        //cout << endl << "After " << i << " steps:" << endl;
        //printMap();
        moveEast();
        moveSouth();
        if (checkIfSame(prevMap)) break;
        i++;
    }
    cout << "the answer is " << i+1 << endl;
    return 25;
}

//the east-facing herd moves first,
//then the south-facing herd moves.