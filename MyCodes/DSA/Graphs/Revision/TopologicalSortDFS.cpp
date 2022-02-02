#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void CreateAdjList(int n, int m, vector<vector<int>>&adjList){
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
    }
}

void DFS(int node, stack<int>&st, vector<bool>&visited, vector<vector<int>>&adjList){
    visited[node] = true;
    for(auto neigh: adjList[node]){
        if(!visited[neigh]){
            // visited[neigh] = true;
            DFS(neigh, st, visited, adjList);
        }
    }
    st.push(node);
}

void TopologicalSort(int n, stack<int>&st, vector<bool>&visited, vector<vector<int>>&adjList){
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            // visited[i] = true;
            DFS(i, st, visited, adjList);
        }
    }
    cout<<"Topological Sort: ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void Solve(int n, int m, stack<int>&st, vector<bool>&visited, vector<vector<int>>&adjList){
    CreateAdjList(n, m, adjList);
    TopologicalSort(n, st, visited, adjList);
}

int main(){
    int n, m;
    cin>>n>>m;
    stack<int>st;
    vector<bool>visited(n+1);
    vector<vector<int>>adjList(n+1);

    Solve(n, m, st, visited, adjList);

    return 0;
}