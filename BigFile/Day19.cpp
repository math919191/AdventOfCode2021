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


/*
 *
0: 1,2,3,
1: -1,2,3,
2: 1,-2,3,
3: 1,2,-3,
4: -1,-2,3,
5: 1,-2,-3,
6: -1,2,-3,
7: -1,-2,-3,
8: 2,3,1,
9: -2,3,1,
10: 2,-3,1,
11: 2,3,-1,
12: -2,-3,1,
13: 2,-3,-1,
14: -2,3,-1,
15: -2,-3,-1,
16: 3,1,2,
17: -3,1,2,
18: 3,-1,2,
19: 3,1,-2,
20: -3,-1,2,
21: 3,-1,-2,
22: -3,1,-2,
23: -3,-1,-2,
24: 1,3,2,
25: -1,3,2,
26: 1,-3,2,
27: 1,3,-2,
28: -1,-3,2,
29: 1,-3,-2,
30: -1,3,-2,
31: -1,-3,-2,
32: 3,2,1,
33: -3,2,1,
34: 3,-2,1,
35: 3,2,-1,
36: -3,-2,1,
37: 3,-2,-1,
38: -3,2,-1,
39: -3,-2,-1,
40: 2,1,3,
41: -2,1,3,
42: 2,-1,3,
43: 2,1,-3,
44: -2,-1,3,
45: 2,-1,-3,
46: -2,1,-3,
47: -2,-1,-3,
 * */

void printScannerInOrder(vector<vector<int>> scanner){
    for (int i = 0; i < scanner.size(); i++){
        cout << scanner[i][0] << " " << scanner[i][1] << " " << scanner[i][2] << " " << endl;
    }
}

int determineSwitch(int iteration){
    if (iteration < 8) return 0;
    if (iteration < 16) return 1;
    if (iteration < 24) return 2;
    if (iteration < 32) return 3;
    if (iteration < 40) return 4;
    if (iteration < 48) return 5;

    return -1;

}

vector<int> Day19::changeOrientationOfCoor(vector<int> coor, int whichIteration){

    int whatRotation = whichIteration % 8;
    int whatSwitch = determineSwitch(whichIteration);

    if (whatSwitch < 3){
        for (int i = 0; i < whatSwitch; i++){
            int x = coor[0];
            int y = coor[1];
            int z = coor[2];
            coor[0] = y;
            coor[1] = z;
            coor[2] = x;
        }
    } else if (whatSwitch == 3){
        int x = coor[0];
        int y = coor[1];
        int z = coor[2];
        coor[0] = x;
        coor[1] = z;
        coor[2] = y;
    } else if (whatSwitch == 4){
        int x = coor[0];
        int y = coor[1];
        int z = coor[2];
        coor[0] = z;
        coor[1] = y;
        coor[2] = x;
    } else if (whatSwitch == 5){
        int x = coor[0];
        int y = coor[1];
        int z = coor[2];
        coor[0] = y;
        coor[1] = x;
        coor[2] = z;
    }

    for (int i = 0; i < 3; i++){
        coor[i] = coor[i] * rotations[whatRotation][i];
    }

    return coor;

}

vector<vector<int>> Day19::adjustScannerOrientation(vector<vector<int>> scanner, int whatIter){
    vector<vector<int>> newScannerOrienation;
    for (int i = 0; i < scanner.size(); i++){
        newScannerOrienation.push_back(changeOrientationOfCoor(scanner.at(i), whatIter));
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
                //cout << "success!!" << endl;
                //cout << currCoor.at(0) << " " << currCoor.at(1) << " " << currCoor.at(2) << endl;
                return numSame;
                break;
            }
        }
    }
    return maxNumSame;
}

vector<int> Day19::giveCoorDifferencesBasedOnRelativeDistance(vector<vector<int>> scanner1, vector<vector<int>> scanner2){
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
                return currCoor;
                break;
            }
        }
    }
    return {0,0,0};
}

bool Day19::addBeacon(vector<int> beacon){
    for (int i = 0; i < allCoorRelTo0.size(); i++){
        if (beacon == allCoorRelTo0.at(i)) return false;
    }
    allCoorRelTo0.push_back(beacon);
    return true;
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
        int xAdj = potentionalAdjusts[0];
        int yAdj = potentionalAdjusts[1];
        int zAdj = potentionalAdjusts[2];

//        int xAdj = 68;
//        int yAdj = -1246;
//        int zAdj = -43;

        cout << xAdj << " " << yAdj << " " << zAdj << endl;
        for (int i = 0; i < 48; i++) {

            vector<vector<int>> newScannerAdj = adjustScannerOrientation(scanner, i);
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

vector<int> Day19::actualRelativeCenter(int scannerNum){
    int orientation = -1;
    int overlappingScanner = -1;
    for (int k = 0; k < coordinates.size(); k++){ //k is what scanner we are comparing
        if (k != scannerNum){  //don't compare it to itself
            for (int i = 0; i < 48; i++){ // try all the orientations
                vector<vector<int>> newScannerAdj = adjustScannerOrientation(coordinates.at(scannerNum), i);
                int same = numOfSameRelativeDistances(coordinates.at(k), newScannerAdj);
                if (same > 11){
                    orientation = i;
                    overlappingScanner = k;
                    vector<int> coord = giveCoorDifferencesBasedOnRelativeDistance(coordinates.at(k), newScannerAdj);
                    coord.push_back(scannerNum);
                    coord.push_back(overlappingScanner);
                    coord.push_back(orientation);

                    scannerRelativePosToOtherScanner.push_back(coord);
                    return coord;
                    break;
                }
            }


        }
    }

    return {0,0,0};
}

bool Day19::checkIfScannerAdded(int scannerNum){
    for (int i = 0; i < successfulScanners.size(); i++){
        if (successfulScanners.at(i) == scannerNum) return true;
    }
    return false;
}

bool Day19::checkIfAllScannersAdded() {
    if (successfulScanners.size() == coordinates.size()) return true;
    return false;
}

vector<int> Day19::findOrientationAndRelPosWithListOfCoor(vector<vector<int>> scanner, int scannerNum){

    for (int i = 0; i < 48; i++){ // try all the orientations
        vector<vector<int>> newScannerAdj = adjustScannerOrientation(scanner, i);
        int same = numOfSameRelativeDistances(newScannerAdj, allCoorRelTo0);
        if (same > 11){
            vector<int> coord = giveCoorDifferencesBasedOnRelativeDistance(newScannerAdj, allCoorRelTo0);
            coord.push_back(scannerNum);
            //coord.push_back(overlappingScanner);
            coord.push_back(i); // orientation

            scannerRelativePosToOtherScanner.push_back(coord);
            return coord;
            break;
        }
    }
    return {0};

}



int Day19::addAllBeacons(){
    //add beacon 0
    int numScanners = coordinates.size();
    for (int i = 0; i < coordinates.at(0).size(); i++){
        addBeacon(  coordinates.at(0).at(i) );
    }
    successfulScanners.push_back(0);
    int i = 0;
    int numberOfTimesThrough = 0;
    while (!checkIfAllScannersAdded()){
        //cout << i << endl;
//        i++;
//        i = i % numScanners;
        if (numberOfTimesThrough < orderOfScannerstoBeAdded.size()){
            i = orderOfScannerstoBeAdded.at(numberOfTimesThrough);
            numberOfTimesThrough++;
        } else {
            if (numberOfTimesThrough == orderOfScannerstoBeAdded.size()){
                i = 0;
            }
            numberOfTimesThrough++;
            //cout << i << endl;
            i++;
            i = i % numScanners;
        }

        if (checkIfScannerAdded(i)) { // if it's already there, then keep going
            //do nothing
        } else {
            vector<vector<int>> currScanner = coordinates.at(i);
            vector<int> coors = findOrientationAndRelPosWithListOfCoor(currScanner, i);
            if (coors.size() > 1){
                currScanner = adjustScannerOrientation(currScanner, coors.at(4));

                currScanner = adjustPosition(currScanner, coors.at(0)*-1, coors.at(1)*-1, coors.at(2)*-1 );
                vector<int> distanceAway = {coors[0]*-1, coors[1]*-1,coors[2]*-1 };
//                masterCoorsList.push_back(changeOrientationOfCoor(distanceAway, coors[4]));
                masterCoorsList.push_back(distanceAway);

                for (int j = 0; j < currScanner.size(); j++){
                    addBeacon(currScanner.at(j));
                }
                successfulScanners.push_back(i);
                cout << "added scanner #" << i << endl;
                cout << allCoorRelTo0.size() << endl;
            }

            //        vector<int> currScannerPosAndInfo = scannerRelativePosToOtherScanner.at(i);


        }
    }


    //try adding beacon 1 after adjusting -- mark the vector if we do it successfully
    //continue, keep doing this until we get all of the beacons added.
    //
    return allCoorRelTo0.size();
}



int Day19::goingThroughGeneratedListOfCoorsAndRelScanner(){
    vector<int> scannersThatAreDone;
    vector<vector<int>> scannersCoorsThatNeedDoneAgain;
    for (int i = 0; i < scannerRelativePosToOtherScanner.size(); i++) {
        vector<int> currCoors = scannerRelativePosToOtherScanner[i];

        cout << "Scanner " << scannerRelativePosToOtherScanner[i][3] << " relative to "
             << scannerRelativePosToOtherScanner[i][4] << " orientation of " << scannerRelativePosToOtherScanner[i][5]
             << endl;
        cout << scannerRelativePosToOtherScanner[i][0] << " " <<
             scannerRelativePosToOtherScanner[i][1] << " " <<
             scannerRelativePosToOtherScanner[i][2] << " " << endl;

        vector<vector<int>> currScanner = coordinates.at(currCoors[3]);

        currScanner = adjustScannerOrientation(currScanner, currCoors.at(5));
        currScanner = adjustPosition(currScanner, currCoors.at(0)*-1, currCoors.at(1)*-1, currCoors.at(2)*-1 );

        for (int i = 0; i < currScanner.size(); i++){
             coordinates.at(currCoors.at(4)).push_back(currScanner.at(i));
        }
        if (currCoors[4] != 0) {
            scannersCoorsThatNeedDoneAgain.push_back(scannerRelativePosToOtherScanner.at(currCoors[4]));
        }
        scannersThatAreDone.push_back(currCoors[3]);
    }

    int k = 0;
    while (scannersCoorsThatNeedDoneAgain.size() != k){
        vector<int> currCoors = scannersCoorsThatNeedDoneAgain[k];
        vector<vector<int>> currScanner = coordinates.at(currCoors[3]);

        currScanner = adjustScannerOrientation(currScanner, currCoors.at(5));
        currScanner = adjustPosition(currScanner, currCoors.at(0)*-1, currCoors.at(1)*-1, currCoors.at(2)*-1 );

        for (int i = 0; i < currScanner.size(); i++){
            coordinates.at(currCoors.at(4)).push_back(currScanner.at(i));
        }
        if (currCoors[4] != 0) {
            scannersCoorsThatNeedDoneAgain.push_back(scannerRelativePosToOtherScanner.at(currCoors[4]));
        }
        scannersThatAreDone.push_back(currCoors[3]);

//        scannersCoorsThatNeedDoneAgain.erase(scannersCoorsThatNeedDoneAgain.begin()+3, 1)

        k++;
    }
    return countNonDuplicates();
}

bool Day19::checkIfNotDuplicate(vector<vector<int>> nonDuplicates, vector<int> coor){
    for (int i = 0; i < nonDuplicates.size(); i++){
        if (nonDuplicates.at(i) == coor) return false;
    }
    return true;
}

int Day19::countNonDuplicates(){
    vector<vector<int>> coordinates0 = coordinates.at(0);
    vector<vector<int>> nonDuplicates;

    for (int i = 0; i < coordinates0.size(); i++){
        if (checkIfNotDuplicate(nonDuplicates, coordinates0.at(i))){
            nonDuplicates.push_back(coordinates0.at(i));
        }
    }
    return nonDuplicates.size();
}

long long giveManhattan(vector<int> coor1, vector<int> coor2 ){
    long long total = 0;
    for (int i = 0; i < 3; i++){
        total += abs(coor1[i] - coor2[i]);
    }
    return total;

}

int Day19::solve(){

    //10562 too low part 2
    //12000 too high part 2
    //10895 is the answer

//    cout << addAllBeacons() << endl;
//
//
//    for (int i = 0; i < masterCoorsList.size(); i++){
//        cout << "{" << masterCoorsList[i][0] << "," << masterCoorsList[i][1] << "," << masterCoorsList[i][2] << "}"<<endl;
//    }
//
    //allRel = allRelSamp;
    long long maxManhattan = 0;
    for (int i = 0; i < allRel.size(); i++){
        for (int j = 0; j < allRel.size(); j++){
            long long currMan = giveManhattan(allRel.at(j), allRel.at(i));
            if ( currMan > maxManhattan){
                maxManhattan = currMan;
                cout << endl << maxManhattan << endl;
                cout << allRel[i][0] << " " << allRel[i][1]  << " " << allRel[i][2] << endl;
                cout << allRel[j][0] << " " << allRel[j][1]  << " " << allRel[j][2] << endl;
            }
        }
    }
    cout << maxManhattan << endl;
//    vector<vector<int>> scanner1 = coordinates.at(1);
//
//    for (int i = 0; i < 48; i++){
//        vector<int> coor = changeOrientationOfCoor({1,2,3}, i);
//        cout << i << ": "<< coor[0] << "," << coor[1] << "," << coor[2] << "," << endl;
//    }
//
//    for (int i = 1; i < coordinates.size(); i++){
//        actualRelativeCenter(i);
//
//
//        cout << "Scanner " << scannerRelativePosToOtherScanner[i][3] << " relative to "
//             << scannerRelativePosToOtherScanner[i][4] << " orientation of " << scannerRelativePosToOtherScanner[i][5]
//             << endl;
//        cout << scannerRelativePosToOtherScanner[i][0] << " " <<
//             scannerRelativePosToOtherScanner[i][1] << " " <<
//             scannerRelativePosToOtherScanner[i][2] << " " << endl;
//
//    }
//    cout << goingThroughGeneratedListOfCoorsAndRelScanner() << endl;
//
//    for (int i = 0; i < scannerRelativePosToOtherScanner.size(); i++) {
//        cout << "Scanner " << scannerRelativePosToOtherScanner[i][3] << " relative to "
//             << scannerRelativePosToOtherScanner[i][4] << " orientation of " << scannerRelativePosToOtherScanner[i][5]
//             << endl;
//        cout << scannerRelativePosToOtherScanner[i][0] << " " <<
//             scannerRelativePosToOtherScanner[i][1] << " " <<
//             scannerRelativePosToOtherScanner[i][2] << " " << endl;
//
//    }
    //450 too high
    //305 too low
    return 19;
}