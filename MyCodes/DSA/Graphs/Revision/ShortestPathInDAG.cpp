#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void CreatedAdjList(int m, vector<vector<pair<int, int>>>&adjList){
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;

        adjList[u].push_back({v,w});
    }
}

void DFS(int node, vector<bool>&visited, stack<int>&st, vector<vector<pair<int, int>>>&adjList){
    visited[node] = true;
    for(auto neigh:adjList[node]){
        if(!visited[neigh.first]){
            DFS(neigh.first, visited, st, adjList);
        }
    }
    st.push(node);
}

void BFS(int node, vector<int>&dist, vector<vector<pair<int, int>>>&adjList){
    for(auto neigh:adjList[node]){
        if((dist[node]+neigh.second)<dist[neigh.first]){
            dist[neigh.first] = dist[node]+neigh.second;
        }
    }
}

void TopoSort(int n, vector<bool>&visited, stack<int>&st, vector<vector<pair<int, int>>>&adjList){
    for(int i=0; i<n; i++){
        if(!visited[i]){
            DFS(i, visited, st, adjList);
        }
    }
    //Printing the topological order
    // for(int i=0; i<n; i++){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }
}

void ShortestPathInDAG(int n, int destination, vector<int>&dist, stack<int>&st, vector<vector<pair<int, int>>>&adjList){
    for(int i=0; i<n; i++){
        BFS(st.top(), dist, adjList);
        st.pop();
    }
    cout<<"Shortest Path Dist: "<<dist[destination];
}

void Solve(int n, int m, int source, int destination, vector<bool>&visited, vector<int>&dist, stack<int>&st, vector<vector<pair<int, int>>>&adjList){
    CreatedAdjList(m, adjList);
    TopoSort(n, visited, st, adjList);
    ShortestPathInDAG(n, destination, dist, st, adjList);
}

int main(){

    int n, m, source, destination;
    cin>>n>>m>>source>>destination;

    stack<int>st;
    vector<int>dist(n+1, INT_MAX);
    vector<bool>visited(n+1);
    vector<vector<pair<int, int>>>adjList(n+1);

    dist[source]=0;
    Solve(n, m, source, destination, visited, dist, st, adjList);
    return 0;
}