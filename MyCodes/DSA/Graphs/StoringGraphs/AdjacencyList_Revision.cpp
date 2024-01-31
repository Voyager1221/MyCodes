#include <iostream>
#include "AdjacencyList_Header.h"
#include "AdjacencyList_Header.cpp"

using namespace std;



int main(){
    vector<vector<int>>* adjList = new vector<vector<int>>; 
    adjList = createAdjacencyList();
    displayAdjacencyList(adjList);
}