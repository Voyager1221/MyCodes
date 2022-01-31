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

bool CheckBipartiteDFS(int node, int parent, vector<bool>&visited, vector<int>&color, vector<vector<int>>&adjList){
    cout<<node<<" ";
    visited[node] = true;
    //This code isn't efficient for checking Bipartite as we are doing bitwise And so that we can print the whole component and not returning false the moment we find it's not bipartite.
    bool res = true;
    for(int neigh: adjList[node]){
        if(!visited[neigh]){
            visited[neigh] = true;
            if(color[node]==1)color[neigh]=0;
            else color[neigh]=1;

            res = res&CheckBipartiteDFS(neigh, node, visited, color, adjList);
        }
        else if(neigh!=parent){
            //to make efficient we can return false instead of doing bitwise &.
            if(color[node]==color[neigh])res = res&false;
        }
    }
    return res;
}

void Solve(int n, int m, vector<bool>&visited, vector<int>&color, vector<vector<int>>&adjList){
    CreateAdjList(n, m, adjList);

    for(int i=1; i<=n; i++){
        color[1] = 0;
        // visited[1] = true;
        if(!visited[i]){
            bool result = CheckBipartiteDFS(i, -1, visited, color, adjList);
            cout<<"\nIs the component Bipartite: "<<result<<endl;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<bool> visited(n+1);
    vector<int> color(n+1);
    vector<vector<int>> adjList(n+1);
    Solve(n, m, visited, color, adjList);
    return 0;
}
