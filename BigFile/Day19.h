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
    vector<vector<int>> allCoorRelTo0;
    vector<vector<int>> scanner0;
    vector<vector<int>> scannerRelativePosToOtherScanner;
    // x y z scannerNum relativeScannerNum orientation
    vector<vector<int>> scannerRealtivePosToScanner0;

    vector<int> successfulScanners;

    vector<vector<int>> rotations = {
            {1,1,1},
            {-1,1,1},
            {1,-1,1},
            {1,1,-1},
            {-1,-1,1},
            {1,-1,-1},
            {-1,1,-1},
            {-1,-1,-1},
    };

    vector<vector<char>> switches = {
            {0,1,2},
            {1,2,0},
            {2,0,1},
            {0,2,1},
            {1,0,2},
            {2,1,0},

    };

    //static vector<vector<vector<bool>>> map;
    //static bool map[1900][1999][1999];

    vector<int> orderOfScannerstoBeAdded {25,10,23,13,17,20,1,2,4,5,7,9,11,12,15,19,21,22,26,27,29,3,6,16,18,24,28,8,14};
    //                                     1 2 3    4  5 6  7 8 9 10 11 13 14 15 16 17 18 19 20 21 222324 25 26 27 28
    //24 => 309
    //28 => 322
    //    345 too low
    //8 => 336

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
        coordinates.push_back(scannerWithCoors);
        scanner0 = coordinates.at(0);
    }

    int solve();

//    void setMap();
//
//    void set(int x, int y, int z, bool toWhat);
//
//    void printMap();

    vector<int> findRelativeCenter(vector<vector<int>> &scanner);

    //vector<vector<int>> changeScannerOrientation(vector<vector<int>> scanner);

    //vector<vector<vector<int>>> generateAllPossibilites(vector<vector<int>> &scanner);

    vector<int> changeSingleCoorOrientation(vector<int> coor, int whichIteration);

    vector<vector<int>> adjustScannerOrientation(vector<vector<int>> scanner, int whatIter);

    int findNumOverlappingBeacons(vector<vector<int>> scanner1, vector<vector<int>> scanner2);

    bool coorInOtherScanner(vector<int> coor, vector<vector<int>> scanner);

    vector<vector<int>> adjustPosition(vector<vector<int>> scanner, int xAdj, int yAdj, int zAdj);

    vector<int> diffInCoor(vector<int> coor1, vector<int> coor2);

    int numOfSameRelativeDistances(vector<vector<int>> scanner1, vector<vector<int>> scanner2);

    vector<int> actualRelativeCenter(vector<vector<int>> scanner);

    vector<int> actualRelativeCenter(int scannerNum);

    vector<int> giveCoorDifferencesBasedOnRelativeDistance(vector<vector<int>> scanner1, vector<vector<int>> scanner2);

    vector<int> changeOrientationOfCoor(vector<int> coor, int whichIteration);

    bool addBeacon(vector<int> beacon);

    int addAllBeacons();

    bool checkIfScannerAdded(int scannerNum);

    bool checkIfAllScannersAdded();

    vector<vector<int>> findOrientationAndRelPosWithListOfCoor(vector<vector<int>> scanner);

    vector<int> findOrientationAndRelPosWithListOfCoor(vector<vector<int>> scanner, int scannerNum);

    int goingThroughGeneratedListOfCoorsAndRelScanner();

    bool checkIfNotDuplicate(vector<vector<int>> nonDuplicates, vector<int> coor);

    int countNonDuplicates();
};


#endif //BIGFILE_DAY19_H
