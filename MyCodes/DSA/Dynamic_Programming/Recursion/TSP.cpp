#include <iostream>
#include <vector>
#include <set>

using namespace std;

void takeInputAsAdjList(int m, vector<vector<pair<int,int>>>&adjList){
    //Storing Adjacency List
        //Considering unequal cost in bi-directional route
        for(int i=0; i<m; i++){
            int u,v,wt_fwd, wt_bwd;
            cin>>u>>v>>wt_fwd>>wt_bwd;
            adjList[u].push_back({v,wt_fwd});
            adjList[v].push_back({u,wt_bwd});
        }
}

void takeInputAtAdjMatrix(int m, vector<vector<int>>&adjMatrix){
        
        //Storing Adjacencey Matrix
        for(int i=0; i<m; i++){
            int u, v, wt_fwd, wt_bwd;
            cin>>u>>v>>wt_fwd>>wt_bwd;
            adjMatrix[u][v] = wt_fwd;
            adjMatrix[v][u] = wt_bwd;
        }
}

int TSP(int index, int n, int m, int source, vector<int>&vis, vector<int>&route, vector<vector<int>>&path, vector<vector<int>>&adjMatrix){


    for(int i=1; i<=n; i++){
        if(i!=source && !vis[i]){
            vis[i] = 1;
            int val = TSP(i, n, m, source, vis, route, path, adjMatrix);
            if(val){
                return adjMatrix[index][i] + val;
            }
            vis[i] = 0;
        }
    }

    return adjMatrix[index][source] + ;
}

void Solve(){
    int n,m, source;
    cin>>n>>m>>source;

    vector<vector<pair<int,int>>>adjList(n+1);
    vector<vector<int>>adjMatrix(n+1 , vector<int>(n+1, -1));
    
    vector<int>vis(n+1,0);
    vector<int>route;
    vector<vector<int>>path;
    
    set<int>st;
    
    for(int i=1; i<=n; i++){
        if(i!=source){
            st.insert(i);
        }
    }

    // takeInputAsAdjList(m, adjList);
    takeInputAtAdjMatrix(m, adjMatrix);
    int cost = TSP(0, n, m, source, vis, route, path, adjMatrix);

}

int main(){
    int T;
    cin>>T;
    while(T--){
        Solve();
    }
    return 0;
}