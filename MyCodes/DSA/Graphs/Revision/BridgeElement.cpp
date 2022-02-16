#include <iostream>
#include <vector>

using namespace std;

void createAdjList(int m, vector<vector<int>>&adjList){
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void DFS(int node, int parent, int &cnt, vector<int>&time, vector<int>&lowTime, vector<vector<int>>&adjList, vector<pair<int, int>>&bridges){
    // cout<<"cnt: "<<cnt<<endl;
    time[node] = lowTime[node] = cnt++;

    for(int neigh: adjList[node]){
        if(neigh==parent)continue;

        if(lowTime[neigh]==-1){
            DFS(neigh, node, cnt, time, lowTime, adjList, bridges);
            if(lowTime[node]> lowTime[neigh]){
                lowTime[node] = lowTime[neigh];
            }
            if(lowTime[neigh]>time[node]){
                cout<<node<<" - "<<neigh<<endl;
            }
        }
        else{
            lowTime[node] = min(lowTime[node], time[neigh]);
        }  
    }
    // cout<<node<<" - "<<lowTime[node]<<endl;
}


void Solve(int n, int m, vector<int>&time, vector<int>&lowTime, vector<vector<int>>&adjList, vector<pair<int, int>>&bridges){
    createAdjList(m, adjList);
    // cout<<"\nCreated AdjList."<<endl;
    cout<<"The Bridge Elements are: "<<endl;
    int cnt=1;
    for(int i=1; i<=n; i++){
        if(lowTime[i]==-1){
            // cout<<i<<" ";
            DFS(i, -1, cnt, time, lowTime, adjList, bridges);
        }
    }
    // for(int i=1; i<=n; i++){
    //     cout<<i<<" - "<<time[i]<<" - "<<lowTime[i]<<endl;
    // }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int>time(n+1, -1);
    vector<int>lowTime(n+1, -1);
    vector<vector<int>>adjList(n+1);
    vector<pair<int, int>>bridges;

    Solve(n, m, time, lowTime, adjList, bridges);
    return 0;
}