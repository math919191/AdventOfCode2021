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


vector<vector<vector<int>>> Day19::generateAllPossibilites(vector<vector<int>> scanner){
    vector<vector<vector<int>>> possibilities;
    for (int i = 0; i < 24; i++){
        vector<vector<int>> newCoors;
        possibilities[i] = newCoors;
    }
}

vector<int> Day19::changeSingleCoorOrientation(vector<int> coor){


    for (int q = 0; q < 3; q++) {
        //shifting coordinates
        int x = coor[0];
        int y = coor[1];
        int z = coor[2];
        coor[0] = y;
        coor[1] = z;
        coor[2] = x;
        cout << endl;

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    if (i == 0) cout << coor[0] * -1 << ", ";
                    else cout << coor[0] << ", ";

                    if (j == 0) cout << coor[1] * -1 << ", ";
                    else cout << coor[1] << ", ";

                    if (k == 0) cout << coor[2] * -1;
                    else cout << coor[2];

                    cout << endl;
                }
            }
        }
    }
    return coor;
}

vector<vector<int>> Day19::changeScannerOrientation(vector<vector<int>> scanner){

    vector<vector<int>> newScanner;
    return scanner;


}


vector<int> Day19::findRelativeCenter(vector<vector<int>> scanner){
    return {1,2,3};
}

int Day19::solve(){
    //setMap();
    //printMap();
    changeSingleCoorOrientation({1,2,3});



        return 19;
}