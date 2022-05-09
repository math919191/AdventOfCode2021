//
// Created by rebek on 5/7/2022.
//

#include "Day19.h"

//void Day19::set(int x, int y, int z, bool toWhat){
//    map[x+1000][y+1000][z+1000] = toWhat;
//}
//
//void Day19::printMap(){
//    for (int i = 0; i < 2000; i++){
//        for (int j = 0; j < 2000; j++){
//            for (int k = 0; k < 2000; k++){
//                cout << map[i][j][k];
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//    cout << endl;
//}
//
//void Day19::setMap(){
//    vector<vector<int>> scanner0 = coordinates[0];
//
//    for (int i = 0; i < scanner0.size(); i++){
//        vector<int> coor = scanner0.at(i);
//        //set(coor[0], coor[1], coor[2], true);
//    }
//}
/*
//24 different orientations: facing positive or negative x, y, or z,
// and considering any of four directions "up" from that facing.
// x y z -- positive and negative (8 possibilities)
// + + +
// - + +
// + - +
// + + -
// - - +
// + - -
// - + -
// - - -
//
// x y z -- (3 possibilities)
// 1 2 3
// 2 3 1
// 3 1 2
ad */



//vector<vector<int>> Day19::changeScannerOrientation(vector<vector<int>> scanner){
//
//    vector<vector<int>> newScanner;
//    return scanner;
//
//
//}
//
//
//vector<int> Day19::findRelativeCenter(vector<vector<int>> scanner){
//    return {1,2,3};
//}
//
//vector<vector<vector<int>>> Day19::generateAllPossibilites(vector<vector<int>> &scanner){
//    int numOfBeacons = scanner.size();
//    int possibilities[24][numOfBeacons][3];
//    vector<vector<vector<int>>> possibilities2;
//    vector<int> test;
//    // [24][25][3]
//    for (int i = 0; i < scanner.size(); i++){
//        vector<vector<int>> possibilitiesOfCoor = changeSingleCoorOrientation(scanner.at(i));
//        for (int j = 0; j < 24; j++){
//            vector<int> myCoor =  possibilitiesOfCoor[j];
//
//            possibilities[0][0][0] = 0;
//            possibilities2[0][0][0] = 0;
////            possibilities[j][i] = {1,2,3};
//        }
//    }
//    return possibilities2;
//}

vector<int> Day19::changeSingleCoorOrientation(vector<int> coor, int whichIteration){
    vector<vector<int>> possibilitiesOfCoor;

    vector<int> newCoor;
    int var = 0;
    for (int q = 0; q < 3; q++) {

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    if (i == 0) newCoor.push_back(coor[0] * -1);
                    else  newCoor.push_back(coor[0]);

                    if (j == 0) newCoor.push_back(coor[1] * -1);
                    else newCoor.push_back(coor[1]);

                    if (k == 0) newCoor.push_back(coor[2] * -1);
                    else newCoor.push_back(coor[2]);

                    possibilitiesOfCoor.push_back(newCoor);
                    if (whichIteration == var){
                        return newCoor;
                    }
                    newCoor.clear();
                    var++;

                }
            }
        }
        //shifting coordinates
        int x = coor[0];
        int y = coor[1];
        int z = coor[2];
        coor[0] = y;
        coor[1] = z;
        coor[2] = x;
    }

    return newCoor;

    //return possibilitiesOfCoor;
}

vector<vector<int>> Day19::adjustOrientation(vector<vector<int>> scanner, int whatIter){
    vector<vector<int>> newScannerOrienation;
    for (int i = 0; i < scanner.size(); i++){
        newScannerOrienation.push_back(changeSingleCoorOrientation(scanner.at(i), whatIter));
    }
    return newScannerOrienation;
}

vector<vector<int>> Day19::adjustPosition(vector<vector<int>> scanner, int xAdj, int yAdj, int zAdj){
    for (int i = 0; i < scanner.size(); i++){
        scanner[i][0] = scanner[i][0] + xAdj;
        scanner[i][1] = scanner[i][1] + yAdj;
        scanner[i][2] = scanner[i][2] + zAdj;
    }
    return scanner;
}

bool Day19::coorInOtherScanner(vector<int> coor, vector<vector<int>> scanner){
    for (int i = 0; i < scanner.size(); i++){
        if (scanner.at(i) == coor) return true;
    }
    return false;
}

int Day19::findNumOverlappingBeacons(vector<vector<int>> scanner1, vector<vector<int>> scanner2){
    int sameBeacons = 0;
    for (int i = 0; i < scanner1.size(); i++){
        if (coorInOtherScanner(scanner1.at(i), scanner2)) sameBeacons++;
    }
    return sameBeacons;
}

vector<int> Day19::diffInCoor(vector<int> coor1, vector<int> coor2 ){
    return {coor1[0] - coor2[0],
            coor1[1] - coor2[1],
            coor1[2] - coor2[2] };
}

int Day19::numOfSameRelativeDistances(vector<vector<int>> scanner1, vector<vector<int>> scanner2){
    vector<vector<int>> differences;
    for (int i = 0; i < scanner2.size(); i++){
        for (int j = 0; j < scanner1.size(); j++){
            differences.push_back(diffInCoor(scanner1.at(j), scanner2.at(i)));
        }
    }

    int maxNumSame = 0;
    for (int i = 0; i < differences.size(); i++){
        vector<int> currCoor = differences.at(i);
        int numSame = 0;
        for (int j = i; j < differences.size(); j++){
            if (currCoor == differences.at(j)) numSame++;

            if (numSame > maxNumSame) maxNumSame = numSame;
            if (numSame > 11){
                cout << "success!!" << endl;
                cout << currCoor.at(0) << " " << currCoor.at(1) << " " << currCoor.at(2) << endl;
            }
        }
    }

    return maxNumSame;

}


vector<int> Day19::findRelativeCenter(vector<vector<int>> &scanner) {

    int numOver = findNumOverlappingBeacons(scanner, scanner0);
    if ( numOver > 11){
        return {0,0,0};
    }
    vector<vector<int>> scannerAdj;
    vector<int> potentionalAdjusts = diffInCoor(scanner.at(0), scanner0.at(0));
    int iter = 0;
    //while (true) {
//        int xAdj = potentionalAdjusts[0];
//        int yAdj = potentionalAdjusts[1];
//        int zAdj = potentionalAdjusts[2];
//
        int xAdj = 68;
        int yAdj = -1246;
        int zAdj = -43;

        cout << xAdj << " " << yAdj << " " << zAdj << endl;
        for (int i = 0; i < 24; i++) {

            vector<vector<int>> newScannerAdj = adjustOrientation(scanner, i);
            scannerAdj = adjustPosition(newScannerAdj, xAdj, yAdj, zAdj);

            int numOver2 = findNumOverlappingBeacons(scannerAdj, scanner0);
            if (numOver2 > 11) {
                cout << "got it!!" << endl;
                int myNum = numOfSameRelativeDistances(scannerAdj, scanner0);
                int myNum2 = numOfSameRelativeDistances(newScannerAdj, scanner0);
                cout << myNum << myNum2 << endl;
                return {68, -1246, -43};
            }
        }
        iter++;
        potentionalAdjusts = diffInCoor(scanner.at(iter), scanner0.at(0));
    //}

    return {1, 2, 3};
}


int Day19::solve(){
    //setMap();
    //printMap();
    vector<vector<int>> scanner1 = coordinates.at(1);

    //vector<vector<vector<int>>> scanner0Poss = generateAllPossibilites(scanner);
    //vector<vector<int>> newscanner = adjustOrientation(scanner, 0);
    //cout << findNumOverlappingBeacons(scanner, newscanner) << endl;

    findRelativeCenter(scanner1);
    //68 -1246 -43

//    for (int k = 0; k < 24; k++){
//        scanner1 = adjustOrientation(scanner1, k);
//        for (int i = 0; i < scanner0.size(); i++){
//            for (int j = 0; j < scanner1.size(); j++){
//                vector<int> coor = diffInCoor(scanner1.at(j), scanner0.at(i));
//                cout << coor[0] << " " << coor[1] << " " << coor[2] << " " << endl;
//            }
//        }
//    }

    //cout << newscanner[0][0] << endl;

    cout << "trying 1 and 4" << endl;
    for (int i = 0; i < 24; i++){
        vector<vector<int>> newScannerAdj = adjustOrientation(coordinates.at(4), i);

        cout << numOfSameRelativeDistances(coordinates.at(1), newScannerAdj) << endl;
    }

    cout << "here" << endl;

    return 19;
}