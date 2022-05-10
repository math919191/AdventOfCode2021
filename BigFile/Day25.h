//
// Created by rebek on 5/10/2022.
//

#ifndef BIGFILE_DAY25_H
#define BIGFILE_DAY25_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


class Day25 {
private:
    vector<vector<char>> map;
    int width = 0;
    int height = 0;

public:
    Day25(vector<string> input){


        width = input.at(0).size();
        height = input.size();
        for (int i = 0; i < height; i++) {
            string myCurrRow = input.at(i);
            vector<char> row;
            for (int j = 0; j < width; j++) {
                char dir = myCurrRow[j];
                row.push_back(dir);
                //map[i][j] = dir;
            }
            map.push_back(row);
            row.clear();
        }

    }


    void printMap();

    int solve();

    bool checkIfNewSpotIsEmpty(int heightSpot, int widthSpot, string dir);

    void moveEast();

    void moveSouth();

    bool checkIfSame(vector<vector<int>> currMap);

    bool checkIfSame(vector<vector<char>> currMap);
};


#endif //BIGFILE_DAY25_H
