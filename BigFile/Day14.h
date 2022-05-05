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
    vector<string> myPairs;
    map<string, string> polyPairs;
    map<string, map<string, long long unsigned int>> pairWithPairsAndFreqsAfterIter;
    map<string, unsigned long long int> pairsAndFreqOfTrueChain;
    map<string, unsigned long long int> lettersAndFreqs;
    int numOfIterationsSmall = 5;
    int numOfTotalIterations = 40;
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

    map<string, unsigned long long int> findNumOfPairsAfterIterations(string pair, int numIterations);

    unsigned long long int countPairs(string chain, string pair);

    void populatePairsFreqMap();

    int part1();

    void populateLettersAndFreq();

    void computeNumOfLetters();

    void populatePolyPairsAndMyPairs();

    int part1(int numIt);
};



#endif //BIGFILE_DAY14_H
