//
// Created by rebek on 4/22/2022.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#ifndef BIGFILE_DAY20_H
#define BIGFILE_DAY20_H

class Day20 {
private:
    string key = "";
    vector<string> map;
    vector<string> newMap;
    int sizeX = 0;
    int sizeY = 0;
    int currSize = 0;

public:
    Day20(vector<string> input){
        key = input.at(0);
        for (int i = 0; i < input.size(); i++){
            if (i > 1) map.push_back(input.at(i));
        }

        sizeX = map.at(0).length();
        sizeY = map.size();
        currSize = sizeY;
    }
    int getBinary(int x, int y);
    int solve();
    int determineIfZero(int x, int y);
    string convertFromBinary(int num);
    void extendMap();
    void enhance();
    void printMap(vector<string> theMap);
    int findLitPixels();


    };


#endif //BIGFILE_DAY20_H
