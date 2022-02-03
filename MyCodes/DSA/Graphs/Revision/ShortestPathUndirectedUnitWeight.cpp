#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void CreateAdjList(int m, vector<vector<int>>&adjList){
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
}

void ShortestPath(int n, int source, vector<int>&dist, vector<vector<int>>&adjList){
    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto itr: adjList[node]){
            if(dist[node]+1<dist[itr]){
                q.push(itr);
                dist[itr] = dist[node]+1;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;

}

void Solve(int n, int m, int source, int target, vector<int>&dist, vector<vector<int>>&adjList){
    CreateAdjList(m, adjList);
    dist[source]=0;
    ShortestPath(n, source, dist, adjList);
    cout<<"\nShortest path to "<<target<<" is: "<<dist[target]<<" units."<<endl;
}

int main(){
    int n,m, source, target;
    cin>>n>>m>>source>>target;

    vector<int>dist(n+1, INT_MAX);
    vector<vector<int>>adjList(n+1);
    Solve(n, m, source, target, dist, adjList);
    return 0;
}
