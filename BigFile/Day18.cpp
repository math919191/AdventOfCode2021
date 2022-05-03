//
// Created by rebek on 4/30/2022.
//

#include "Day18.h"

string Day18::intToStr(int myInt){
    stringstream ss; //converting int to string
    ss << myInt;
    string strInt = ss.str();
    return strInt;
}

int Day18::findIfInside4Pairs(string snailFishNum){
    int howFar = 0;
    for (int i = 0; i < snailFishNum.length(); i++){
        if (snailFishNum.at(i) == '[') howFar++;
        else if (snailFishNum.at(i) == ']') howFar--;

        if (howFar >= 5 && isdigit(snailFishNum.at(i+1)) ){
            return i;
        }
    }
    return -1;
}

int Day18::findIfNeedsSplitting(string snailFishNum){
    for (int i = 0; i < snailFishNum.length(); i++){
        if (snailFishNum.at(i) != ']' && snailFishNum.at(i) != '[' && snailFishNum.at(i) != ','){
            //it's one of the numbers
            char nextChar = snailFishNum.at(i+1);
            if (isdigit(nextChar)){
                return i; //gives the index of the number needing splitting
            }
        }
    }
    return -1;
}

string Day18::split(string snailNum){
    int index = findIfNeedsSplitting(snailNum);
    string newPair = "[";

    int commaIndex = 0;
    bool actualIndex = true;
    while (true){
        if (snailNum.at(index+commaIndex) == ',') {
            commaIndex = commaIndex+index;
            break;
        }
        else {
            if (snailNum.at(index+commaIndex) == ']') {
                actualIndex = false;
                break; // it's on the other side
            }
            commaIndex++;
        }
    }
    if (actualIndex == false){

        commaIndex = 0;
        while (true){
            if (snailNum.at(index-commaIndex) == ',') {
                commaIndex = index-commaIndex;
                break;
            }
            else {
                commaIndex++;
            }
        }
    }



    int num = stoi(snailNum.substr(index, commaIndex-index));
    int half = num/2;
    string halfStr = intToStr(half);
    string halfStrPlus1 = intToStr(half+1);
    if (num % 2 == 1){
        newPair += halfStr;
        newPair += ",";
        newPair += halfStrPlus1;
        newPair += "]";
    } else {
        newPair += halfStr;
        newPair += ",";
        newPair += halfStr;
        newPair += "]";
    }
    string currCurrNum = snailNum;
    string item = snailNum.substr(index, commaIndex);
    if (index < commaIndex) snailNum.replace(snailNum.begin()+index, snailNum.begin()+commaIndex,newPair);
    else snailNum.replace(snailNum.begin()+commaIndex+1, snailNum.begin()+index+2,newPair);
    cout << currCurrNum << endl;
    cout << snailNum << endl;
    return snailNum;
}

string Day18::findNextLeftNumber(int index, string snailNum){
    //index is the left bracket
    int leftNumIndex = -1;
    int leftNumBegIndex = -1;
    for (int i = index; i >= 0; i--){
        if (isdigit(snailNum.at(i))){
            leftNumIndex = i;
            while (true){
                if (isdigit(snailNum.at(i))){
                    i--;
                } else {
                    leftNumBegIndex = i+1;
                    break;
                }
            }
            break;
        }
    }

    if (leftNumIndex > 0) {
        int commaIndex = 0;
        for (int i = 0; i < 20; i++){
            if (snailNum.at(index+i) == ','){
                commaIndex = index+i;
                break;
            }
        }


        int num1 = stoi(snailNum.substr(leftNumBegIndex, leftNumIndex-leftNumBegIndex+1));
        int num2 = stoi(snailNum.substr(index+1, commaIndex-index-1));
        int sum =  num1 + num2;
        string strSum = intToStr(sum);
        snailNum.replace(snailNum.begin()+leftNumBegIndex, snailNum.begin()+leftNumIndex+1,strSum);
    }

    return snailNum;
}

string Day18::findNextRightNumber(int index, string snailNum){
    int rightNumIndex = -1;
    index = findIfInside4Pairs(snailNum);
    //adjusting the index if they moved because of numbers
    int i = 0;
    while (true){
        if (snailNum.at(index+i) == ']') break;
        else i++;
    }
    index += i;
    //index is the right bracket
    int rightNumEndIndex = 0;

    for (int i = index; i < snailNum.length(); i++){
        char item = snailNum.at(i);
        if (isdigit(snailNum.at(i))){
            rightNumIndex = i;
            while (true){
                if (isdigit(snailNum.at(i))){
                    i++;
                } else {
                    rightNumEndIndex = i-1;
                    break;
                }
            }
            break;
        }
    }

    if (rightNumIndex  > 0){ // if it is negative one, there is no number to the right

        int commaIndex = 0;
        for (int i = 0; i < 20; i++){
            if (snailNum.at(index-i) == ','){
                commaIndex = index-i;
                break;
            }
        }

        int num1 = stoi(snailNum.substr(rightNumIndex, rightNumEndIndex-rightNumIndex+1));

        int num2 = stoi(snailNum.substr(commaIndex+1, index-commaIndex-1));
//        int num1 = snailNum.at(rightNumIndex ) - 48;
//        int num2 = snailNum.at(index-1) - 48;
        int sum =  num1 + num2;
        string strSum = intToStr(sum);
        snailNum.replace(snailNum.begin()+rightNumIndex, snailNum.begin()+rightNumEndIndex+1,strSum);

    }
    return snailNum;
}

string Day18::explode(int index, string snailNum){
    snailNum = findNextLeftNumber(index, snailNum);
    //cout << "after left "<< snailNum << endl;

    snailNum = findNextRightNumber(index, snailNum);
    //cout << "after right "<< snailNum << endl;
    index = findIfInside4Pairs(snailNum);
    int distToBracket = 0;
    while (true){
        if (snailNum.at(index+distToBracket) == ']') break;
        else distToBracket++;
    }
    snailNum.replace(snailNum.begin()+index, snailNum.begin()+index+distToBracket+1,"0");
    //cout << "after replace "<< snailNum << endl;
    return snailNum;
}

string Day18::add(string pair1, string pair2){
    string newPair = "[";
    newPair = newPair + pair1 + "," + pair2 + "]";
    return newPair;
}

int Day18::findMagnitude(string snailNum){

    int mag = 0;
    int i = 0;
    int size = snailNum.length();
    while (i < size){
        if (snailNum.at(i) == ']'){
            int commaIndex = 0;
            for (int k = 0; k < 50; k++){
                if (snailNum.at(i - k ) == ','){
                    commaIndex = i-k;
                    break;
                }
            }
            int openBracketIndex = 0;
            for (int k = 0; k < 50; k++){
                if (snailNum.at(commaIndex - k ) == '['){
                    openBracketIndex = commaIndex - k;
                    break;
                }
            }
            mag = 0;
            mag += stoi(snailNum.substr(openBracketIndex+1, openBracketIndex-commaIndex) ) * 3;
            mag += stoi(snailNum.substr(commaIndex+1, commaIndex-i) ) * 2;

            string strMag = intToStr(mag);

            snailNum.replace(snailNum.begin()+openBracketIndex, snailNum.begin()+i+1,strMag);
            i = 0; // resets back to the beginning of the string
            size = snailNum.length(); // prevents going out of range
        }
        i++;
    }
    return mag;
}

void Day18::test(){
    cout << findMagnitude("[[[[6,6],[7,6]],[[7,7],[7,0]]],[[[7,7],[7,7]],[[7,8],[9,9]]]]") << endl;
}

int Day18::solve(){

    //string currTest = "[[3,[2,[8,0]]],[9,[5,[4,[3,2]]]]]";
    //cout << "exploding: " << explode(findIfInside4Pairs(currTest), currTest);

//#if 0
    string currNum = myInput.at(0);
    for (int i = 0; i < myInput.size(); i++){
        cout << currNum << endl << endl;
        if (i != myInput.size()-1){
            currNum = add(currNum, myInput.at(i+1));
        }

        while (true){
            while (true){
                if (findIfInside4Pairs(currNum) > 0){
                    currNum = explode(findIfInside4Pairs(currNum), currNum);
                    cout << "after explode " << currNum << endl << endl;
                } else {
                    break;
                }
            }
            if (findIfNeedsSplitting(currNum) > 0){
                currNum = split(currNum);
                cout << "after split " << currNum << endl << endl;
            }
            if (findIfNeedsSplitting(currNum) < 0 && findIfInside4Pairs(currNum) < 0){
                break;
            }
        }
    }
    cout << "final answer: " << currNum << endl;
    cout << "final answer: " << findMagnitude(currNum) << endl;
//#endif
    cout << endl << endl;

    return 18;
}