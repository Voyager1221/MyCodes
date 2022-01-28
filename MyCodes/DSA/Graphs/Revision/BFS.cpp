#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void CreateAdjList(int n, int m, vector<vector<int>>& adjList){
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
}

void BFS(int node,vector<bool>& vis, queue<int> &q, vector<vector<int>> &adjList){
    q.pop();
    cout<<node<<' ';
    for(int neigh: adjList[node]){
        if(!vis[neigh]){
            vis[neigh] = true;
            q.push(neigh);
        }
    }
}

void solve(int n, int m, vector<bool>& vis, queue<int> &q, vector<vector<int>>&adjList){
    q.push(1);
    vis[1] = true;
    while(!q.empty()){
        BFS(q.front(), vis, q, adjList);
    }
}


int main(){
    int n,m;
    cin>>n>>m;

    queue<int>q;
    vector<bool>vis(n+1);
    vector<vector<int>> adjList(n+1);
    CreateAdjList(n,m, adjList);

    // for(int i=1; i<=n; i++){
    //     cout<<i<<": ";
    //     for(int neigh:adjList[i]){
    //         cout<<neigh<<" ";
    //     }
    //     cout<<endl;
    // }
    solve(n, m, vis, q, adjList);
    return 0;
}