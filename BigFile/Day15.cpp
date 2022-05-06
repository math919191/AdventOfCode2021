//
// Created by rebek on 4/28/2022.
//

#include "Day15.h"

#define V 9 //num of vertices

void Day15::setMap(){
    width = myInput.at(0).size();
    height = myInput.size();
    for (int i = 0; i < V; i++) {
        string myCurrRow = myInput.at(i);
        for (int j = 0; j < V; j++) {
            int num = myCurrRow[j] - 48;
            map[i][j] = num;
        }
    }
//    currSize = map.size();
}



void Day15::printMap() {
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cout << map[i][j];
        }
        cout << endl;
    }
}

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree

int Day15::minDistance(int distance[], bool sptSet[]){
    int minimum = INT_MAX,minIndex;

    for (int k = 0; k < V; k++){
        if (sptSet[k] == false && distance[k] <= minimum){
            minimum=distance[k];
            minIndex=k;
        }
    }
    return minIndex;
}


// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void Day15::dijkstra(int graph[V][V], int src){
    int dist[V]; // The output array. dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array
    printSolution(dist);
}


void Day15::printSolution(int dist[]) const
{
    cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<< dist[i]<< endl;
}

int Day15::solve(){
    setMap();
    //printMap();
    int graph[V][V]  =
                        { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(map, 0);
    return 91;
}

