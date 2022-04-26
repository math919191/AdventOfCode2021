//
// Created by rebek on 4/22/2022.
//

#include "Day20.h"

int Day20::determineIfZero(int x, int y){
    if (x < 0 || y < 0 || y >= currSize || x >= currSize) return 0;
    if (map.at(y).at(x) == '#') return 1;
    else return 0;
}

int Day20::getBinary(int x, int y){
    int total = 0;

    total += determineIfZero(x-1, y-1) * pow(2, 8);
    total += determineIfZero(x, y-1) * pow(2, 7);
    total += determineIfZero(x+1, y-1) * pow(2, 6);

    total += determineIfZero(x-1, y) * pow(2, 5);
    total += determineIfZero(x, y) * pow(2, 4);
    total += determineIfZero(x+1, y) * pow(2, 3);

    total += determineIfZero(x-1, y+1) * pow(2, 2);
    total += determineIfZero(x, y+1) * pow(2, 1);
    total += determineIfZero(x+1, y+1) * pow(2, 0);
    return total;

}

string Day20::convertFromBinary(int num){
    return key.at(num) + " ";
}

void Day20::extendMap(){
    for (int i = 0; i < map.size(); i++){
        map.at(i) = ".." + map.at(i) + "..";
    }
    string newLine = "";
    for (int i=0; i < map.at(0).length(); i++) newLine += '.';
    map.insert(map.begin(), newLine);
    map.insert(map.begin(), newLine);
    map.push_back(newLine);
    map.push_back(newLine);
    currSize+=2;
    sizeX = map.at(0).length();
    sizeY = map.size();


}

void Day20::enhance(){
    vector<string> tempMap;
    int width = map.at(0).length();
    for (int i = 0; i < map.size(); i++){
        string line = "";
        for (int j = 0; j < width; j++) {
            char currItem = key.at(getBinary(j,i));
            if (  currItem == '.') {
                line += '.';
            } else {
                line += '#';
            }
        }
        tempMap.push_back(line);
    }
    cout << "temp Map:" << endl;
    printMap(tempMap);
    currSize+=2;
    map = tempMap;
}

void Day20::printMap(vector<string> theMap){
    cout << endl;
    for (int i = 0; i < theMap.size(); i++){
        cout << theMap.at(i) << endl;
    }
    cout << endl << endl;
}

int Day20::findLitPixels(){
    int count = 0;
    for (int i = 0; i < map.size(); i++){
        for (int j = 0; j < map.at(0).length(); j++){
            if (map.at(i).at(j) == '#') count++;
        }
    }
    return count;

}

int Day20::solve(){
    extendMap();
    extendMap();
    enhance();

    extendMap();
    extendMap();
    enhance();
    printMap(map);
    cout << findLitPixels() << endl;

    return 222;
}

