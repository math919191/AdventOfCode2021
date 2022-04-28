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


class Day21 {
private:
    vector<string> map;
    int currSize = 0;
public:
    Day21(vector<string> input){
        for (int i = 0; i < input.size(); i++){
            map.push_back(input.at(i));
        }
        currSize = map.size();
    }

    int solve();


};


#endif //BIGFILE_DAY21_H
