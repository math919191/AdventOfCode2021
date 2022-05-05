//
// Created by rebek on 5/3/2022.
//

#include "Day14.h"

string Day14::afterStep(string currString){
    unsigned long long int currPlace = 0;
    unsigned long long int startLeng = currString.length();
    while (currString.length() < (startLeng*2 - 1) ){
        string pair = currString.substr(currPlace, 2);
        string newLetter = polyPairs[pair];
        currString.insert(currPlace+1, newLetter);
        currPlace += 2;
    }
    return currString;
}

long long unsigned int Day14::countPairs(string chain, string pair){
    long long unsigned int total = 0;
    for (int i = 0; i < chain.length()-1; i++){
        if (chain.substr(i, 2) == pair) total++;
    }
    return total;
}

map<string, long long unsigned int> Day14::findNumOfPairsAfterIterations(string pair, int numIterations){
    map<string, long long unsigned int> pairsAndFreq;
    string currString = pair;

    for (int i = 0; i < numIterations; i++){
        currString = afterStep(currString);
    }

    for (int i = 0; i < myPairs.size(); i++){
        long long unsigned int freq = countPairs(currString, myPairs.at(i));
        pairsAndFreq.insert({myPairs.at(i), freq});
    }
    return pairsAndFreq;

}

void Day14::populatePairsFreqMap(){
    for (int i = 0; i < myPairs.size(); i++){
        map<string, long long unsigned int> pairsAndFreq = findNumOfPairsAfterIterations(myPairs.at(i), numOfIterationsSmall);
        pairWithPairsAndFreqsAfterIter.insert({myPairs.at(i), pairsAndFreq});
    }
}

unsigned long long int countLetter(string letter, string currChain){
    unsigned long long int total =0;
    for (unsigned long long int i =0; i < currChain.length(); i++){
        char currChar = letter.at(0);
        if (currChain.at(i) == currChar){
            total +=1;
        }
    }
    return total;
}

void Day14::addIfNotAlreadyExisting(string letter){
    for (int i = 0; i < myLetters.size(); i++){
        if (myLetters.at(i) == letter){
            return;
        }
    }
    myLetters.push_back(letter);
}


int Day14::part1(){

    int numIt = 10;
    string currString = chain;
    for (int i = 0; i < numIt; i++){
        currString = afterStep(currString);
    }
    vector<unsigned long long int> listOfQuantities;

    unsigned long long int max = 0;
    unsigned long long int min = 10000;

    for (int i =0; i < myLetters.size(); i++ ){
        unsigned long long int amount = countLetter(myLetters.at(i), currString);
        if (amount > max){
            max = amount;
        }
        if (amount < min){
            min = amount;
        }
        listOfQuantities.push_back(amount);

    }
    cout << "the answer is " << max - min << endl;
    return max - min;

}

void printMap(map<string, long long unsigned int> printedMap){
    map<string, long long unsigned int>::iterator it = printedMap.begin();
    // Iterate over the map using Iterator till end.
    while (it != printedMap.end())
    {
        // Accessing KEY from element pointed by it.
        string word = it->first;
        // Accessing VALUE from element pointed by it.
        long long unsigned int count = it->second;
        cout << word << " :: " << count << endl;
        // Increment the Iterator to point to next entry
        it++;
    }
}

void Day14::computeNumOfLetters(){

    map<string, unsigned long long int>::iterator it = pairsAndFreqOfTrueChain.begin();
    // Iterate over the map using Iterator till end.
    while (it != pairsAndFreqOfTrueChain.end()){
        string pair = it->first;
        long long unsigned int freq = pairsAndFreqOfTrueChain[pair];

        for (int i = 0; i < 2; i++){
            string currLetter = pair.substr(i,1);
            lettersAndFreqs[currLetter] = lettersAndFreqs[currLetter] + freq;
        }

        it++;
    }

    //we double counted everything -- have to divide everything by 2
    map<string, unsigned long long int>::iterator letterIter = lettersAndFreqs.begin();
    while (letterIter != lettersAndFreqs.end()){
        string letter = letterIter->first;
        lettersAndFreqs[letter] = lettersAndFreqs[letter] / 2;
        letterIter++;
    }

    // the first and last letter of the chain were not included
    lettersAndFreqs[chain.substr(0,1)] += 1;
    lettersAndFreqs[chain.substr(chain.length()-1,1)] += 1;

}

void Day14::populateLettersAndFreq(){
    for (int i = 0; i < myLetters.size(); i++){
        lettersAndFreqs.insert({myLetters[i], 0});
    }
}

void Day14::populatePolyPairsAndMyPairs(){

    for (int i = 0; i < myInput.size(); i++){
        string currString = myInput.at(i);
        string firstLetters = currString.substr(0, 2);
        string secondLetter = currString.substr(6, 1);
        addIfNotAlreadyExisting(secondLetter);
        myPairs.push_back(firstLetters);
        polyPairs.insert({firstLetters, secondLetter});
    }

}

int Day14::solve(){


    populatePolyPairsAndMyPairs();
    populateLettersAndFreq();
    populatePairsFreqMap();

    //setting up 2 maps
    // origMap -- isn't modified -- it's just referenced for the number of pairs
    // pairsAndFreqofTrueChain -- is modified -- the map keeps gets added to for each pair
    map<string, long long unsigned int> origMap;
    for (int i = 0; i < myPairs.size(); i++) {
        string currPair = myPairs.at(i);
        long long unsigned int freq = countPairs(chain, currPair);
        origMap.insert({currPair, freq});
        pairsAndFreqOfTrueChain.insert({currPair, 0});
    }

    for (int i = 0; i < (numOfTotalIterations/numOfIterationsSmall); i++) { // the pairs freq map is after 10 iterations ==> 4*10 = 40


        map<string, unsigned long long int>::iterator it = pairsAndFreqOfTrueChain.begin();
        // Iterate over the map using Iterator till end.
        while (it != pairsAndFreqOfTrueChain.end()) {
            // Accessing KEY from element pointed by it.
            string pair = it->first;
            long long unsigned int freqOfPair = origMap[pair];

            // this is the map with the number of pairs if the start was only the pair
            map<string, long long unsigned int> currMap = pairWithPairsAndFreqsAfterIter[pair];
            if (freqOfPair != 0) {

                map<string, unsigned long long int>::iterator currMapIter = currMap.begin();
                while (currMapIter != currMap.end()) {
                    string innerPair = currMapIter->first;
                    pairsAndFreqOfTrueChain[innerPair] =
                            pairsAndFreqOfTrueChain[innerPair] + (freqOfPair * currMap[innerPair]);
                    currMapIter++;
                }

            }


            it++;
        }
        origMap = pairsAndFreqOfTrueChain;
        //resetting the pairs and freq map back to all 0s
        for (int i = 0; i < myPairs.size(); i++) {
            string currPair = myPairs.at(i);
            pairsAndFreqOfTrueChain.insert({currPair, 0});
        }
    }

    printMap(pairsAndFreqOfTrueChain);

    computeNumOfLetters();
    cout << endl << "letters and counts: " << endl;
    printMap(lettersAndFreqs);


    return 14;
}

