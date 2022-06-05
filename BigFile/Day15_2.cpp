//
// Created by rebek on 5/19/2022.
//

#include "Day15_2.h"


void Day15_2::setMap(){
    for (int i = 0; i < width; i++) {
        string myCurrRow = myInput.at(i);
        for (int j = 0; j < height; j++) {
            int num = myCurrRow[j] - 48;
            map[i][j] = num;
        }
    }
//    currSize = map.size();
}

void Day15_2::printMap() {
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}


void Day15_2::solve(){
    cout << "here sovling 15 attempt 2 " << endl;
    setMap();
    printMap();
}