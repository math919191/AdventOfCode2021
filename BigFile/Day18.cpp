//
// Created by rebek on 4/30/2022.
//
#define MAGIC_NUM -1;

#include "Day18.h"
int Day18::findIfInside4Pairs(string snailFishNum){
    int howFar = 0;
    for (int i = 0; i < snailFishNum.length(); i++){
        if (snailFishNum.at(i) == '[') howFar++;
        else if (snailFishNum.at(i) == ']') howFar--;

        if (howFar >= 5 && isdigit(snailFishNum.at(i+1)) ){
            return i;
        }
    }
    return MAGIC_NUM;
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
    string newPair = "[,]";
    int num = stoi(snailNum.substr(index, 2));
    if (num % 2 == 1){
        newPair.insert(newPair.begin()+1, num/2 + 48);
        newPair.insert(newPair.begin()+3, num/2 + 49);
    } else {
        newPair.insert(newPair.begin()+1, num/2 + 48);
        newPair.insert(newPair.begin()+3, num/2 + 48);
    }
    snailNum.replace(snailNum.begin()+index, snailNum.begin()+index+2,newPair);
    return snailNum;
}

string Day18::findNextLeftNumber(int index, string snailNum){
    int leftNumIndex = -1;
    for (int i = index; i >= 0; i--){
        if (isdigit(snailNum.at(i))){
            leftNumIndex = i;
            break;
        }
    }

    if (leftNumIndex > 0){

        int num1 = snailNum.at(leftNumIndex ) - 48;
        int num2 = snailNum.at(index+1) - 48;
        int sum =  num1 + num2;
        stringstream ss;
        ss << sum;
        string strSum = ss.str();
        snailNum.replace(snailNum.begin()+leftNumIndex, snailNum.begin()+leftNumIndex+1,strSum);

        //if (isdigit((leftNumIndex-1))){}
    }
//    else {
//        snailNum.at(index+1) = '0';
//        if (isdigit(snailNum.at(index+2))){
//            snailNum.erase(snailNum.begin() + index+2);
//        }
//    }
    return snailNum;
}

string Day18::findNextRightNumber(int index, string snailNum){
    int rightNumIndex = -1;
    index = findIfInside4Pairs(snailNum)+4;
    for (int i = index; i < snailNum.length(); i++){
        char item = snailNum.at(i);
        if (isdigit(snailNum.at(i))){
            rightNumIndex = i;
            break;
        }
    }

    if (rightNumIndex  > 0){
//        char a = '4';
//        int ia = a - '0';
//        char item = snailNum.at(rightNumIndex);
//        int num1 = snailNum.at(rightNumIndex ) - 48;
//        int num2 = snailNum.at(index-1) - 48;
//        int sum =  num1+num2 +48;
//        snailNum.at(rightNumIndex) = sum;
//        //if (isdigit((leftNumIndex-1))){}
        int num1 = snailNum.at(rightNumIndex ) - 48;
        int num2 = snailNum.at(index-1) - 48;
        int sum =  num1 + num2;
        stringstream ss;
        ss << sum;
        string strSum = ss.str();



        snailNum.replace(snailNum.begin()+rightNumIndex, snailNum.begin()+rightNumIndex+1,strSum);



    }
    return snailNum;
}

string Day18::explode(int index, string snailNum){
    snailNum = findNextLeftNumber(index, snailNum);
    //cout << "after left "<< snailNum << endl;
    snailNum = findNextRightNumber(index+4, snailNum);
    //cout << "after right "<< snailNum << endl;
    index = findIfInside4Pairs(snailNum);
    snailNum.replace(snailNum.begin()+index, snailNum.begin()+index+5,"0");
    //cout << "after replace "<< snailNum << endl;
    return snailNum;
}

string Day18::add(string pair1, string pair2){
    string newPair = "[";
    newPair = newPair + pair1 + "," + pair2 + "]";
    return newPair;
}



int Day18::solve(){
    //string currTest = "[[[[[9,8],1],2],3],4]";
    //string currTest = "[7,[6,[5,[4,[3,2]]]]]";
    //string currTest = "[[6,[5,[4,[3,2]]]],1]";
    //string currTest = "[[3,[2,[8,0]]],[9,[5,[4,[3,2]]]]]";
    //string currTest = "[[3,[2,[1,[7,3]]]],[6,[5,[4,[3,2]]]]]";
    string currTest = "[[[[0,7],4],[[7,8],[0,13]]],[1,1]]";
//    int index = findIfInside4Pairs(currTest);
//    cout << explode(index, currTest) << endl;
    string currNum = myInput.at(0);
    for (int i = 0; i < myInput.size(); i++){
        cout << currNum << endl;
        if (i != myInput.size()-1){
            currNum = add(currNum, myInput.at(i+1));
        }
        //cout << "after addition: " << currNum << endl;
        while (true){
            while (true){
                if (findIfInside4Pairs(currNum) > 0){
                    currNum = explode(findIfInside4Pairs(currNum), currNum);
                //    cout << "after explode:  "<< currNum << endl;
                } else {
                    break;
                }
            }
            if (findIfNeedsSplitting(currNum) > 0){
                currNum = split(currNum);
            //    cout << "after split:    "<< currNum << endl;
            }
            if (findIfNeedsSplitting(currNum) < 0 && findIfInside4Pairs(currNum) < 0){
                break;
            }
        }
    }
    cout << "final answer: " << currNum << endl;
    //    cout << "input: " << endl << currTest << endl;
//    cout << split(currTest) << endl;
//    string expected = "[[[[0,7],4],[[7,8],[0,[6,7]]]],[1,1]]";
//    cout << expected << endl;

    cout << endl << endl;
    return 18;
}