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
#define V 9 //num of vertices

#ifndef BIGFILE_DAY21_H
#define BIGFILE_DAY21_H


class Day15 {
private:
//    vector<vector<int>> map;
    int map[V][V];
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


    int minDistance(int *distance, bool *sptSet);


    void dijkstra(int graph[V][V], int src);
    void printSolution(int dist[]) const;

};


#endif //BIGFILE_DAY21_H
