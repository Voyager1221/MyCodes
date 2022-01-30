#include <iostream>
#include <vector>

using namespace std;

void CreateAdjList(int n, int m, vector<vector<int>>&adjList){
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
}

bool DFS(int node, int parent, vector<bool>&visited, vector<vector<int>>&adjList){
    visited[node] = true;
    for(int neigh: adjList[node]){
        if(visited[neigh] && neigh==parent)continue;
        if(visited[neigh] && neigh!=parent)return true;
        DFS(neigh, node, visited, adjList);
    }
    return false;
}

void solve(int n, int m, vector<bool>&visited, vector<vector<int>>&adjList){
    CreateAdjList(n, m, adjList);
    // bool result = false;
    bool result;
    for(int i=1; i<=n; i++){
        // result |= DFS(i,-1, visited, adjList);
        if(!visited[i]){
            result = DFS(i,-1, visited, adjList);
            cout<<"Is there a loop in component: "<<result<<endl;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<bool> visited(n+1);
    vector<vector<int>> adjList(n+1);
    solve(n, m, visited, adjList);

    return 0;
}