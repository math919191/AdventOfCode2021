//
// Created by rebek on 4/29/2022.
//

#ifndef BIGFILE_DAY16_H
#define BIGFILE_DAY16_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>


using namespace std;

class Day16 {
private:
    vector<string> myInput;
    vector<long long> literalNumbers;
    vector<int> versionNumbers;
    vector<int> versionNumbers2;
    stack<unsigned long long> myLiterals;

    string origString = "";
public:
    Day16(vector<string> input){
        for (int i = 0; i < input.size(); i++){
            myInput.push_back(input.at(i));
        }
        origString = myInput.at(0);
    }

    int solve();
    string parsePacket(string packet);
    string parseSubpacket(string subpacket);


    int addVersions();

    string parseLiteralPacket(string subpacket);

    int addVersions(vector<int> versions);

    void calcFromID(int id);

    void calcFromID(int id, int numOfLiterals);
};


#endif //BIGFILE_DAY16_H
