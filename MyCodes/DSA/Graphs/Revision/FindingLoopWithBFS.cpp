#include <iostream>
#include <vector>
#include <queue>

using namespace std;
void CreateAdjList(int n, int m, vector<vector<int>>&adjList){
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
}

void PrintAdjacencyList(vector<vector<int>>&adjList){
    for(int i=1; i<adjList.size(); i++){
        cout<<i<<": ";
        for(int j:adjList[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

bool CheckCycleBFS(int node, int parent, vector<bool> &vis, vector<vector<int>>&adjList){
    queue <pair<int,int>> q;
    q.push({node, -1});
    while(!q.empty()){
        int n = q.front().first;
        int p = q.front().second;
        q.pop();
        for(auto it: adjList[n]){
            if(!vis[it]){
                vis[it] = true;
                q.push({it, n});
            }else if(it!=p){
                return true;
            }
        }
    }
    return false;        
}



void solve(int n, int m, vector<bool>&vis, vector<vector<int>> &adjList){
    CreateAdjList(n, m, adjList);
    PrintAdjacencyList(adjList);
    int result=1;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            result = CheckCycleBFS(i, -1, vis, adjList);
            cout<<"Does the graph contains loop: "<<result<<endl;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<bool> vis(n+1);
    vector<vector<int>> adjList(n+1);
    solve(n, m, vis, adjList);
    return 0;
}