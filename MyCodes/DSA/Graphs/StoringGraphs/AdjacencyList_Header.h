#ifndef ADJACENCYLIST_HEADER
#define ADJACENCYLIST_HEADER

#include <vector>

struct graphFundamentals{

    int node;
    int edges;

};

graphFundamentals* getFundamentGraphInput();

std::vector<std::pair<int,int>>* getEdgesPairInput(graphFundamentals*); 

std::vector<std::vector<int>>* createNonDirectedGraph(std::vector<std::pair<int,int>>*);

std::vector<std::vector<int>>* createAdjacencyList();

void displayAdjacencyList(std::vector<std::vector<int>>*);


#endif