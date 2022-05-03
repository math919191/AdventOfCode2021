//
// Created by rebek on 4/30/2022.
//

#ifndef BIGFILE_DAY18_H
#define BIGFILE_DAY18_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

class Day18 {
private:
    vector<string> myInput;

public:
    Day18(vector<string> input){
        for (int i = 0; i < input.size(); i++){
            myInput.push_back(input.at(i));
        }
    }

    int solve();

    string add(string pair1, string pair2);

    int findIfInside4Pairs(string snailFishNum);

    int findIfNeedsSplitting(string snailFishNum);

    string explode(int index, string snailNum);

    string findNextLeftNumber(int index, string snailNum);

    string findNextRightNumber(int index, string snailNum);

    string split(string snailNum);

    int findMagnitude(string snailNum);

    void part2();

    string intToStr(int myInt);

    int findMagOfTwoNum(string num1, string num2);

    int part1();
};


#endif //BIGFILE_DAY18_H
