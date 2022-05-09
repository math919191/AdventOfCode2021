//
// Created by rebek on 5/7/2022.
//

#ifndef BIGFILE_DAY19_H
#define BIGFILE_DAY19_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Day19 {
private:
    vector<vector<vector<int>>> coordinates;
    static vector<vector<vector<bool>>> map;
    //static bool map[1900][1999][1999];



public:
    Day19(vector<string> input){

        vector<vector<int>> scannerWithCoors;
        for (int i = 0; i < input.size(); i++){
            string currLine = input.at(i);
            if (currLine.find("scanner") != string::npos && i !=0) {
                coordinates.push_back(scannerWithCoors);
                scannerWithCoors.clear();
            } else if (currLine.find(",") != string::npos) {
                vector<int> coordinate;
                int x = stoi(currLine.substr(0, currLine.find(",")) );
                int pos1 = currLine.find(",");
                currLine = currLine.substr(pos1+1);
                int y = stoi(currLine.substr(0, currLine.find(",")) );
                int pos2 = currLine.find(",");
                currLine = currLine.substr(pos2+1);
                int z = stoi(currLine.substr(0, currLine.find(",")) );

                coordinate.push_back(x);
                coordinate.push_back(y);
                coordinate.push_back(z);
                scannerWithCoors.push_back(coordinate);
            } else {
                continue;
            }

            //myInput.push_back(input.at(i));


        }
    }

    int solve();

    void setMap();

    void set(int x, int y, int z, bool toWhat);

    void printMap();

    vector<int> findRelativeCenter(vector<vector<int>> scanner);

    vector<vector<int>> changeScannerOrientation(vector<vector<int>> scanner);

    vector<int> changeSingleCoorOrientation(vector<int> coor);
};


#endif //BIGFILE_DAY19_H
