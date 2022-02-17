#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void createAdjList(int m, vector<vector<int>>&adjList, vector<vector<int>>&adjListTranspose){
    cout<<"\nIn Create AdjList."<<endl;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjListTranspose[v].push_back(u);
    }
}

void DFS(int node, stack<int>&st, vector<bool>&visited, vector<vector<int>>&adjList){
    visited[node] = true;
    for(int neigh: adjList[node]){
        if(visited[neigh]==0){
            DFS(neigh, st, visited, adjList);
        }
    }
    st.push(node);
}

void TopoSort(int n, stack<int>&st, vector<bool>&visited, vector<vector<int>>adjList){
    for(int i=1; i<=n; i++){
        if(visited[i]==0){
            DFS(i, st, visited, adjList);
        }
    }
}

void StronglyConnectedComponent(int node, stack<int>&st, vector<bool>&visited, vector<int>&scc, vector<vector<int>>&adjListTranspose){
    visited[node] = false;
    scc.push_back(node);
    for(int neigh: adjListTranspose[node]){
        if(visited[neigh]==true){
            StronglyConnectedComponent(neigh, st, visited, scc, adjListTranspose);
        }
    }

}

void KosarajusAlgo(int n, stack<int>&st, vector<bool>&visited, vector<vector<int>>&SCC_List, vector<vector<int>>&adjListTranspose){
    cout<<"\nIn Kosaraju's."<<endl;
    
    for(int i=1; i<=n; i++){
        vector<int>scc;
        if(visited[st.top()]==1){
            StronglyConnectedComponent(st.top(), st, visited, scc, adjListTranspose);
            SCC_List.push_back(scc);
        }
        st.pop();
        scc.clear();
    }
    cout<<"Size: "<<SCC_List.size()<<endl;
    cout<<"\nPrinting SCC_List."<<endl;
    for(int i=0; i<SCC_List.size(); i++){
        cout<<i<<": ";
        for(int y: SCC_List[i]){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}

void Solve(int n, int m, stack<int>&st, vector<bool>&visited, vector<vector<int>>&SCC_List, vector<vector<int>>&adjList, vector<vector<int>>&adjListTranspose){
    createAdjList(m, adjList, adjListTranspose);
    cout<<"\nCreated Adjacency List."<<endl;
    TopoSort(n, st, visited, adjList);

    //not clearing the visited vector caz it becomes null. While in case of erase it's equivalent to vanish vector.
    // visited.clear();

    //Here using default value as true for visited
    //ie when ever we visit a node in kosaraju we mark visited[node] = false
    //and search for neigh of node having visited[neigh]==true;
    KosarajusAlgo(n, st, visited, SCC_List, adjListTranspose);
}

int main(){

    int n,m;
    cin>>n>>m;

    stack<int>st;
    vector<bool>visited(n, false);
    vector<vector<int>>SCC_List;
    vector<vector<int>>adjList(n+1);
    vector<vector<int>>adjListTranspose(n+1);

    Solve(n, m, st, visited, SCC_List, adjList, adjListTranspose);

    return 0;
}