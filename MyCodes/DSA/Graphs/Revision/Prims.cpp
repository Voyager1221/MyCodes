#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void CreateAdjList(int m, vector<vector<pair<int, int>>>&adjList){
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;

        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back({u,w});
    }
}

void PrimsAlgo(int n, vector<bool>&MST, vector<int>&key, vector<int>&parent, vector<vector<pair<int, int>>>&adjList){
    
    key[0] = 0;

    for(int i=0; i<n; i++){
        int min = INT_MAX, index;

        for(int j=0; j<n; j++){
            if(MST[j]==false && key[j]<min){
                min = key[j];
                index = j;
            }
        }
        MST[index] = true;
        for(auto itr: adjList[index]){
            int v = itr.first;
            int w = itr.second;

            if(w<key[v]){
                key[v] = w;
                parent[v] = index;
            }
        }
    }

    for(int i=1; i<n; i++){
        cout<<parent[i]<<" - "<<i<<"\n";
    }
    
}

void Solve(int n, int m, vector<bool>&MST, vector<int>&key, vector<int>&parent, vector<vector<pair<int, int>>>&adjList){
    CreateAdjList(m, adjList);
    PrimsAlgo(n, MST, key, parent, adjList);
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<bool>MST(n, false);
    vector<int>key(n, INT_MAX);
    vector<int>parent(n, -1);
    vector<vector<pair<int, int>>>adjList(n);

    Solve(n, m, MST, key, parent, adjList);
    return 0;
}