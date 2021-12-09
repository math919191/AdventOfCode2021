#include <iostream>
using namespace std;
#include <fstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>

const int BOARD_SIZE = 1000; // 1000
const int INPUT_SIZE = 200; // 200
vector<string> ReadTheInput(){
    vector<string> theInput(INPUT_SIZE);
    ifstream inFS;
    // Open filer
    inFS.open("input.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file" << endl;
        exit(1);
    }
    // read the  file
    for (unsigned int j = 0; j < INPUT_SIZE; j++) {
        string currStr;

        getline(inFS, currStr, '\n'  );
        //inFS >> currStr;
        theInput.at(j) = currStr;

    }


    inFS.close();

    return theInput;

}

int GiveOriginalIntBack(char theChar){
    if (theChar == 'a'){
        return 0;
    } else if (theChar == 'b'){
        return 1;
    } else if (theChar == 'c'){
        return 2;
    }else if (theChar == 'd'){
        return 3;
    }else if (theChar == 'e'){
        return 4;
    }else if (theChar == 'f'){
        return 5;
    }else if (theChar == 'g') {
        return 6;
    }

}

bool FindIfLetterIsThere(string digit, char fakeLetter, vector<char> key){

    char letterSearching = key.at( GiveOriginalIntBack(fakeLetter) );

    for (int i = 0; i < digit.size(); i++){
        if (digit.at(i) == letterSearching){
            return true;
        }
    }
    return false;

}

int GivesRealDigit(string digitStr, vector<char> key){
    // index #     0 1 2 3 4 5 6
    // real output a b c d e f g

    //using the answer key, I can find the original digit

    int size = digitStr.size();
    if (size == 2){ //1 is the only one that is 2 in length
        return 1;
    } else if (size == 4){ //4 is the only one that is 4 in length
        return 4;
    } else if (size == 3){ //7 is the only one that is 3 in length
        return 7;
    } else if (size == 7){
        return 8;
    } else if (size == 6){ // either 0 or 6 or 9
        if ( FindIfLetterIsThere( digitStr, 'e', key) != true  ){
            return 9; //9 is the only one that doesn't have e that is 6 long
        } else if (FindIfLetterIsThere( digitStr, 'c', key) != true){
            return 6; //6 is the only one that doesn't have c that is 6 long
        } else if (FindIfLetterIsThere( digitStr, 'd', key) != true){
            return 0; //0 is the only one that doesn't have d that is 6 long
        }
    } else if (size == 5){ //either 2 or 3 or 5 -- uses similar ideas as described above
        if (FindIfLetterIsThere( digitStr, 'f', key) != true){
            return 2;
        } else if (FindIfLetterIsThere( digitStr, 'b', key) != true){
            return 3;
        } else {
            return 5;
        }
    }


}

vector<int> FindLetterCount(vector<string> lineOfDigits) {
    vector<int> countOfEachLetter(7);
    for (int i = 0; i < 10; i++) { //all the characters
        string currDigit = lineOfDigits.at(i);
        for (int j = 0; j < currDigit.length(); j++) {
            char currCharacter = currDigit.at(j);
            if (currCharacter == 'a') {
                countOfEachLetter.at(0) = countOfEachLetter.at(0) + 1;
            } else if (currCharacter == 'b') {
                countOfEachLetter.at(1) = countOfEachLetter.at(1) + 1;
            } else if (currCharacter == 'c') {
                countOfEachLetter.at(2) = countOfEachLetter.at(2) + 1;
            } else if (currCharacter == 'd') {
                countOfEachLetter.at(3) = countOfEachLetter.at(3) + 1;
            } else if (currCharacter == 'e') {
                countOfEachLetter.at(4) = countOfEachLetter.at(4) + 1;
            } else if (currCharacter == 'f') {
                countOfEachLetter.at(5) = countOfEachLetter.at(5) + 1;
            } else if (currCharacter == 'g') {
                countOfEachLetter.at(6) = countOfEachLetter.at(6) + 1;
            }
        }

    }
    return countOfEachLetter;
}

char GiveOriginalCharacterBack(int num){
    if (num == 0){
        return 'a';
    } else if (num == 1){
        return 'b';
    } else if (num == 2){
        return 'c';
    }else if (num == 3){
        return 'd';
    }else if (num == 4){
        return 'e';
    }else if (num == 5){
        return 'f';
    }else if (num == 6) {
        return 'g';
    }

}

string GetTheDigitBasedOnLength(vector<string> lineOfDigits, int desiredLength){
    for (int i = 0; i < 10; i++){
        string currDig = lineOfDigits.at(i);
        if (currDig.length() == desiredLength){
            return currDig;
        }
    }
}


//This is the big algorithm -- it figures out which corresponds
vector<char> FindAnswerKey(vector<string> lineOfDigits){
/* 0:      1:      2:      3:      4:
    aaaa    ....    aaaa    aaaa    ....
    b    c  .    c  .    c  .    c  b    c
    b    c  .    c  .    c  .    c  b    c
    ....    ....    dddd    dddd    dddd
    e    f  .    f  e    .  .    f  .    f
    e    f  .    f  e    .  .    f  .    f
    gggg    ....    gggg    gggg    ....

    5:      6:      7:      8:      9:
    aaaa    aaaa    aaaa    aaaa    aaaa
    b    .  b    .  .    c  b    c  b    c
    b    .  b    .  .    c  b    c  b    c
    dddd    dddd    ....    dddd    dddd
    .   f   e    f  .    f  e    f  .
    .   f   e    f  .    f  e    f  .    f
    gggg    gggg    ....    gggg    gggg
    */
    vector<char> myAnswerKey(7);
    vector<char> possibleGs;

    // index #     0 1 2 3 4 5 6
    // real output a b c d e f g
    // example     b d a e g c f

    vector<int> eachLetterCount;
    eachLetterCount = FindLetterCount(lineOfDigits);
    //certain letters only show up so many times, for example looking at the example, 'F' shows up exactly 9 times
    //so, what ever letter shows up 9 times is my F and I can add it to the answer key
    //I can figure out 3 of the letters this way

    for (int i =0; i < eachLetterCount.size(); i++){
        int currCount = eachLetterCount.at(i);
        if (currCount == 9){ //that's my F!
            myAnswerKey.at(5) = GiveOriginalCharacterBack(i);
        } else if (currCount == 4){ //that's my E!
            myAnswerKey.at(4) = GiveOriginalCharacterBack(i);
        } else if (currCount == 6){ //that's my B!
            myAnswerKey.at(1) = GiveOriginalCharacterBack(i);
        } else if (currCount == 7){ //possible G
            char possibleG = GiveOriginalCharacterBack(i);
            //cout << possibleG;
            possibleGs.push_back(possibleG);
        }
    }

    //Find C
    //Only C and F show up for the number 1, and I know the number 1 because it is only 2 long
    //C will be what ever one F isn't
    string myOne = GetTheDigitBasedOnLength(lineOfDigits, 2);
    if (myOne.at(0) == myAnswerKey.at(5)){ //whatever one isn't f.
        myAnswerKey.at(2) = myOne.at(1); //that's my c!
    } else {
        myAnswerKey.at(2) = myOne.at(0); //that's my c!
    }

    char myF = myAnswerKey.at(5);
    char myC = myAnswerKey.at(2);


    //Find A
    //Only C and F and A show up for the number 7, and I know the number 7 because it is only 3 long
    //A will be where ever one F and C aren't
    string mySeven = GetTheDigitBasedOnLength(lineOfDigits, 3);
    if ( ( mySeven.at(0) )!= myF && ( mySeven.at(0) != myC )  ){ //whatever one isn't f or c.
        myAnswerKey.at(0) = mySeven.at(0); //that's my a!
    } else if ( ( mySeven.at(1) != myF  ) && ( mySeven.at(1) != myC ) ) {
        myAnswerKey.at(0) = mySeven.at(1); //that's my a!
    } else {
        myAnswerKey.at(0) = mySeven.at(2); //that's my a!
    }

    //Find D
    // | (b)   |
    // | __ (d)| (c)
    //         | (f)
    //Find D
    //Only B and D and C and F show up for the number 4, and I know the number 4 because it is only 4 long
    //D will be where ever one F and C and B aren't


    string myFour = GetTheDigitBasedOnLength(lineOfDigits, 4); //which ever one isn't f or c or b
    char myA = myAnswerKey.at(0);
    char myB = myAnswerKey.at(1);
    myF = myAnswerKey.at(5);
    myC = myAnswerKey.at(2);


    if (    (myFour.at(0) != myB) && (myFour.at(0) != myC) && (myFour.at(0) != myF) ){
        myAnswerKey.at(3) = myFour.at(0);
    } else if (    (myFour.at(1) != myB) && (myFour.at(1) != myC) && (myFour.at(1) != myF) ){
            myAnswerKey.at(3) = myFour.at(1);
    } else if (    (myFour.at(2) != myB) && (myFour.at(2) != myC) && (myFour.at(2) != myF) ){
        myAnswerKey.at(3) = myFour.at(2);
    } else {
        myAnswerKey.at(3) = myFour.at(3);
    }

    //Find G -- last man standing
    //G shows up 8 times, but so does D, so whatever isn't D with 8 length will be G
    char myD = myAnswerKey.at(3);
    //cout << possibleGs.at(1);
    if (possibleGs.at(0) == myD){
        myAnswerKey.at(6) = possibleGs.at(1);
    } else {
        myAnswerKey.at(6) = possibleGs.at(0);
    }


    return myAnswerKey;


}


int main() {
    vector<string> input = ReadTheInput();
    vector<char> answerKey;
    int total = 0;
    //how the answer key works:
    // index #     0 1 2 3 4 5 6 access different letters based on index
    // real output a b c d e f g what the letter corresponds to
    // example     b d a e g c f example of what it might look like


    //this loops through each line
    for (int i =0; i < input.size(); i++){

        vector<string> digits;
        string currInput = input.at(i);

        //this gets the first 10 digits we can use
        for (int q =0; q < 10; q++) {
            string currSubString;
            int pos = currInput.find(" ", 1);
            currSubString = currInput.substr(0, pos);
            digits.push_back(currSubString);
            currInput.erase(0, pos + 1);
        }
        //using the digits, get the key
        answerKey = FindAnswerKey(digits);


        currInput.erase(0,2);
        int smallTotal = 0;

        vector<string> fourDigits;
        //get the input and at the same time convert it and add it to the total
        for (int j =0; j < 4; j++){
            //getting input
            string currdigit;
            int pos = currInput.find(" ", 1);
            currdigit = currInput.substr(0, pos);

            //now convert the input to numbers and add it
            int myDig =  GivesRealDigit(currdigit, answerKey);
            fourDigits.push_back(currdigit);
            int mult = pow (10, 3 - j); //10 ^ (3-j)
            smallTotal += (myDig * mult);

            //inputting things
            currInput.erase(0, pos + 1);

        }
        //cout << endl << "gets " << smallTotal << " " << i << endl;

        total += smallTotal;

    }

    cout << "total " << total << endl;
    return 0;
}


