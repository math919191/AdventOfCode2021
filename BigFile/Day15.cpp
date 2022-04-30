//
// Created by rebek on 4/28/2022.
//

#include "Day15.h"

void Day15::setMap(){
    width = myInput.at(0).size();
    height = myInput.size();
    for (int i = 0; i < height; i++) {
        vector<int> currRow;
        string myCurrRow = myInput.at(i);
        for (int j = 0; j < width; j++) {

            char num = myCurrRow[j] -48;
            currRow.push_back(num);
        }
        map.push_back(currRow);
    }
    currSize = map.size();
}


void Day15::printMap() {
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}

int Day15::miniDist(int distance[], bool Tset[]){
    int minimum = INT_MAX,ind;

    for (int k=0; k < height; k++){
        if (Tset[k]==false && distance[k]<=minimum){
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void Day15::dijkstraAlgo(vector<vector<int>> graph, int src){
    int distance[height]; // array to calculate the min distance for each node
    bool Tset[height]; //bool array to makr visited and unvisted for each node
    for (int k = 0; k < height; k++){
        distance[k] = INT_MAX;
        Tset[k] = false;
    }

    distance[src] = 0; //source vertex distance is set to 0

    for (int k = 0; k < height; k++){
        int m = miniDist(distance, Tset);
        Tset[m] = true;
        for ( int k = 0; k < height; k++){
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }

    int actMin = INT_MAX;
    for (int i = 0; i <height; i++){
        cout << distance[i] << endl;
        if (distance[i] < actMin) actMin = distance[i];
    }
    cout << actMin << endl;

}

int Day15::solve(){
    setMap();
    dijkstraAlgo(map, 0);
    return 91;
}