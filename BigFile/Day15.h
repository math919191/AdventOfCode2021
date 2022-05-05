//
// Created by rebek on 4/28/2022.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


#ifndef BIGFILE_DAY21_H
#define BIGFILE_DAY21_H


class Day15 {
private:
    vector<vector<int>> map;
    int currSize = 0;
    int width = 0;
    int height = 0;
    vector<string> myInput;
public:

    Day15(vector<string> input){
        for (int i = 0; i < input.size(); i++){
            myInput.push_back(input.at(i));
        }
    }

    int solve();
    void printMap();
    void setMap();


    void dijkstraAlgo(vector<vector<int>> graph, int src);

    int miniDist(int *distance, bool *Tset);

    void printSolution(int *dist) const;
};


#endif //BIGFILE_DAY21_H
