//
// Created by rebek on 5/19/2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


#ifndef BIGFILE_DAY15_2_H
#define BIGFILE_DAY15_2_H


class Day15_2 {
private:
    vector<string> myInput;
    vector<vector<int>> map;
    int height = 0;
    int width = 0;

public:
    Day15_2(vector<string> input){
        for (int i = 0; i < input.size(); i++){
            myInput.push_back(input.at(i));
        }
        height = myInput.size();
        width = myInput.at(0).size();
    }


    void setMap();

    void printMap();

    void solve();
};


#endif //BIGFILE_DAY15_2_H
