#include <iostream>
#include <vector>
using namespace std;



void createAdjList(int m, vector<vector<int>>&adjList){
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void DFS(int node, int parent, int* timer, vector<int>&time, vector<int>&lowTime, vector<int>&isArticulationPoint, vector<vector<int>>&adjList){
    time[node] = lowTime[node] = *timer;
    (*timer)++;
    int child=0;
    for(int neigh: adjList[node]){
        if(neigh==parent)continue;
        if(lowTime[neigh]==-1){
            DFS(neigh, node, timer, time, lowTime, isArticulationPoint, adjList);
            if(lowTime[node]> lowTime[neigh]){
                lowTime[node] = lowTime[neigh];
            }
            if(lowTime[neigh]>=time[node] && parent!=-1){
                isArticulationPoint[node] = 1;
            }
            child++;
        }
        else{
            lowTime[node] = min(lowTime[node], time[neigh]);
        }
    }
    //This if for the starting node of a component of a graph
    if(child>1 && parent==-1){
        isArticulationPoint[node] = 1;
    }
}

void Solve(int n, int m, vector<int>&time, vector<int>&lowTime, vector<int>&isArticulationPoint, vector<vector<int>>&adjList){
    createAdjList(m, adjList);
    int timer=0;
    for(int i=0; i<m; i++){
        if(lowTime[i]==-1){
            DFS(i, -1, &timer, time, lowTime, isArticulationPoint, adjList);
        }
    }
    for(int i=1; i<=n; i++){
        if(isArticulationPoint[i]==1)cout<<i<<" ";
    }
}

int main(){

    int n, m;
    cin>>n>>m;

    vector<int>time(n+1, -1);
    vector<int>lowTime(n+1, -1);
    vector<int>isArticulationPoint(n+1, 0);
    vector<vector<int>>adjList(n+1);

    Solve(n, m, time, lowTime, isArticulationPoint, adjList);

    return 0;
}