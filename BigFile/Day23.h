//
// Created by rebek on 5/17/2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

#ifndef BIGFILE_DAY23_H
#define BIGFILE_DAY23_H
enum direction { UP, DOWN, LEFT, RIGHT };


class Day23 {
private:
    vector<string> myInput;
    vector<vector<char>> map;
    int width = 13;
    int height = 5;
    std::map<char, int> energy;
    int energyTotal = 0;
    int leastTotalEnergy = INT_MAX;

public:
    Day23(vector<string> input){

        //set up energy values
        energy['A']=1;
        energy['B']=10;
        energy['C']=100;
        energy['D']=1000;

        //create the map with the hallways
        for (int i = 0; i < input.size(); i++){
            myInput.push_back(input.at(i));
        }

        for (int i = 0; i < width; i++) {
            //string myCurrRow = myInput.at(i);
            vector<char> row;
            for (int j = 0; j < height; j++) {
                char myChar = myInput.at(j).at(i);
                row.push_back(myChar);
                //map[i][j] = ;
            }
            map.push_back(row);
            row.clear();

        }
    }

    void solve();

    void printMap();

    bool checkIfValidMove(direction dir, int x, int y);

    bool move(direction dir, int x, int y);

    void addEnergy(char amphipod);
};


#endif //BIGFILE_DAY23_H
