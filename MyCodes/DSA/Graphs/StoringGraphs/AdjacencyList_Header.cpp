#include <iostream>
#include <vector>
#include <iterator>

#include "AdjacencyList_Header.h"

using namespace std;

graphFundamentals* getFundamentGraphInput(){
    graphFundamentals* graph = new graphFundamentals;
    cout<<"Please enter the number of nodes and edges"<<endl;
    int n,m;
    cin>>n>>m;
    graph->node = n;
    graph->edges = m;

    return graph;
}

vector<pair<int, int>>* getEdgesPairInput(graphFundamentals* graph){
    vector<pair<int,int>>* edgesPair = new vector<pair<int,int>>;
    
    cout<<"Please enter the edge-pair"<<endl;
    
    for(int i=0; i<graph->edges; i++){
        int a,b;
        cin>>a>>b;
        edgesPair->push_back(make_pair(a,b));
        // (*edgesPair).push_back(make_pair(a,b));
    }
    return edgesPair;
}

vector<vector<int>>* createNonDirectedGraph(graphFundamentals* graph, vector<pair<int,int>>* edgesPair){
    // In case of multi-dimensional vectors/arrays size needs to be pre-defined if the operations are carried out using indexing
    // Given that, 'new' keyword should be used to assign dynamic memory during runtime.
    vector<vector<int>>*adjList = new vector<vector<int>>(graph->node+1, vector<int>(0));
    
// Iterating using Indexing
    // for(size_t i=0; i<edgesPair->size(); ++i){
    //     pair<int,int>& currentPair = (*edgesPair)[i];
    //     // cout<< "(" << currentPair.first << ", " << currentPair.second<< ")"<<endl;
    //     int a = currentPair.first;
    //     int b = currentPair.second;

    //     (*adjList)[a].push_back(b);
    //     (*adjList)[b].push_back(a);
    // }

// Iterating using Iterator
    for(vector<pair<int,int>>::iterator itr = edgesPair->begin(); itr!=edgesPair->end(); itr++){
        
        // int a = itr->first;
        // int b = itr->second;

        pair<int,int>& edge_pair = *itr;
        int a = edge_pair.first;
        int b = edge_pair.second;

        // Don't know why this is not working
        // adjList->at[a].push_back(b);
        // adjList->at[b].push_back(a);
        (*adjList)[a].push_back(b);
        (*adjList)[b].push_back(a);
    }

    return adjList;    
}

vector<vector<int>>* createAdjacencyList(){
    graphFundamentals* graph = getFundamentGraphInput();
    vector<pair<int,int>>* edgesPair = getEdgesPairInput(graph);
    vector<vector<int>>* adjList = createNonDirectedGraph(graph, edgesPair);
    return adjList;
}

void displayAdjacencyList(vector<vector<int>>* adjList){
    
    cout<<"Printing the adjacency list"<<endl;
    for(int i = 1; i<adjList->size(); i++){
        cout<<i<<" --> ";
        for(int j=0; j<(*adjList)[i].size(); j++){
            cout<<(*adjList)[i][j]<<" ";
        }
        cout<<endl;
    }
}
