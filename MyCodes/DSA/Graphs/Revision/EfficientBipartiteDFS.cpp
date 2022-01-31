#include <iostream>
#include <vector>

using namespace std;

void CreateAdjList(int n, int m, vector<vector<int>>&adjList){
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
}

bool CheckBipartiteDFS(int node, vector<int>&color, vector<vector<int>>&adjList){
    bool res = true;
    cout<<node<<" ";
    for(int neigh:adjList[node]){
        if(color[neigh]==-1){
            color[neigh] = 1 - color[node];
            res = res & CheckBipartiteDFS(neigh, color, adjList);
        }
        // else if(color[n]==color[neigh])return false;
        else if(color[node]==color[neigh])res = res & false;
    }
    
    // return true;
    return res;
}

void Solve(int n, int m, vector<int>&color, vector<vector<int>>&adjList){
    CreateAdjList(n, m, adjList);
    for(int i=1; i<=n; i++){
        if(color[i]==-1){
            color[i] = 0;
            bool result = CheckBipartiteDFS(i, color, adjList);
            cout<<"Is the component Bipartite: "<<result<<endl;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>color(n+1, -1);
    vector<vector<int>>adjList(n+1);
    Solve(n, m, color, adjList);
    return 0;
}