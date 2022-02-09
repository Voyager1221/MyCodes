#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void CreateAdjList(int m, vector<vector<pair<int, int>>>&adjList){
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back({u,w});
    }
}

void BFS(int node, vector<bool>&MST, vector<int>&dist, vector<int>&parent, vector<vector<pair<int, int>>>&adjList){

}

void PrimsAlgo(int n, vector<bool>&MST, vector<int>&dist, vector<int>&parent, vector<vector<pair<int, int>>>&adjList){
    
    for(int i=0; i<n-1; i++){
        int min = INT_MAX, index;
        // vector<pair<int,int>>::iterator itr;
        for(int j =0; j<n; j++){
            // if(dist[itr->first]> dist[n]+itr->second){
            //     dist[itr->first] = dist[n] + itr->second;
            // }

            if(!MST[j] && dist[j]<min){
                min = dist[j];
                index = j;
            }
        }
        MST[index] = true;

        for(auto itr: adjList[index]){
            int v = itr.first;
            int w = itr.second;

            if(MST[v]==false && w<dist[v]){
                parent[v] = index;
                dist[v] = w;
            }
        }
    }   
    
    for(int i=0; i<n; i++){
        cout<<parent[i]<<" - "<<i<<endl;
    }
}

void Solve(int n, int m, vector<bool>&MST, vector<int>&dist, vector<int>&parent, vector<vector<pair<int, int>>>&adjList){
    CreateAdjList(m, adjList);
    dist[0] = 0;

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<bool>MST(n, false);
    vector<int>dist(n, INT_MAX);
    vector<int>parent(n, -1);
    vector<vector<pair<int, int>>>adjList(n);

    return 0;
}