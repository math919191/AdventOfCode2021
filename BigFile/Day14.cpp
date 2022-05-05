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

map<string, vector<int>> Day14::findNumOfPairsAfter

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


int Day14::solve(){

    for (int i = 0; i < myInput.size(); i++){
        string currString = myInput.at(i);
        string firstLetters = currString.substr(0, 2);
        string secondLetter = currString.substr(6, 1);
        addIfNotAlreadyExisting(secondLetter);
        polyPairs.insert({firstLetters, secondLetter});
    }

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
        //cout << "letter " << myLetters.at(i) << " has " << amount << endl;
    }
    cout << "the answer is " << max - min << endl;
    return 14;
}

