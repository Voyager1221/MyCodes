#include <iostream>
#include <vector>

using namespace std;
//This code is not working properly needs to be checked.
class LoopInDirectedGraph{
    private:
        bool CheckCycleDFS(int node, vector<int>&visited, vector<int>&DFS_Vis, vector<vector<int>>&adjList);
    public:
        int n, m;
        vector<int>visited;
        vector<int>DFS_Vis;
        vector<vector<int>>adjList;
        LoopInDirectedGraph(int n, int m){
            this.n = n;
            this.m = m;
            visited(n);
            DFS_Vis(n);
            adjList(n);
            memset(visited, 0, sizeof visited);
            memset(DFS_Vis, 0, sizeof DFS_Vis);
                
        };
        void CreateAdjList(int n, int m, vector<vector<int>>&adjList);
        bool isCyclic(vector<int>&visited, vector<int>&DFS_Vis, vector<vector<int>>&adjList);
        void solve(int n, int m, vector<int>&visited, vector<int>&DFS_Vis, vector<vector<int>>&adjList);
};

void LoopInDirectedGraph::CreateAdjList(int n , int m, vector<vector<int>>&adjList){
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
    }
}

bool LoopInDirectedGraph::CheckCycleDFS(int node, vector<int>&visited, vector<int>&DFS_Vis, vector<vector<int>>&adjList){
    visited[node] = 1;
    DFS_Vis[node] = 1;
    for(auto neigh: adjList[node]){
        if(!visited[neigh]){
            if(CheckCycleDFS(neigh, visited, DFS_Vis, adjList))return true;
        }else if(DFS_Vis[neigh]){
            return true;
        }
    }
    DFS_Vis[node]=0;
    return false;        
}

bool LoopInDirectedGraph::isCyclic(vector<int>&visited,, vector<int>&DFS_Vis, vector<vector<int>>&adjList){
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            if(CheckCycleDFS(i, visited, DFS_Vis, adjList))return true;
        }
    }
    return false;
}

void solve(int n, int m, vector<int>&visited, vector<int>&DFS_Vis, vector<vector<int>>&adjList){
    CreateAdjList(n, m, adjList);
    isCyclic(this.visited, this.adjList);
}

int main(){
    int n,m;
    cin>>n>>m;

    LoopInDirectedGraph obj1(n,m);
    solve(n, m, obj1.visited, obj1.adjList);
    return 0;
}