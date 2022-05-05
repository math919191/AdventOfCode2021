//
// Created by rebek on 5/3/2022.
//

#ifndef BIGFILE_DAY14_H
#define BIGFILE_DAY14_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <map>
using namespace std;

class Day14 {
private:
    vector<string> myInput;
    string chain = "";
    vector<string> myLetters;
    map<string, string> polyPairs;
    map<string, map<string, int>> numOfPairsAfter5Iters;
    //  original Pair : (otherPairs : numOfTimes)

public:
    Day14(vector<string> input){
        chain = input.at(0);
        for (int i = 2; i < input.size(); i++){
            myInput.push_back(input.at(i));
        }
    }

    int solve();

    void addIfNotAlreadyExisting(string letter);

    string afterStep(string currString);
};



#endif //BIGFILE_DAY14_H
