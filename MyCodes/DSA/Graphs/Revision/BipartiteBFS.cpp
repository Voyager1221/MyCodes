#include <iostream>
#include <queue>
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

bool CheckBipartiteBFS(int node, int parent, vector<bool>&visited, vector<int>&color, vector<vector<int>>&adjList){
    queue<pair<int,int>>q;
    q.push({node, parent});
    visited[node] = true;
    //This code isn't efficient for checking Bipartite as we are doing bitwise And so that we can print the whole component and not returning false the moment we find it's not bipartite.
    bool res = true;
    while(!q.empty()){
        int n = q.front().first;
        int p = q.front().second;
        q.pop();
        cout<<n<<" ";
        for(int neigh:adjList[n]){
            if(!visited[neigh]){
                visited[neigh] = true;
                q.push({neigh, n});
                if(color[n]==1)color[neigh]=0;
                else color[neigh] = 1;
            }
            else if(neigh!=p){
                //to make efficient we can return false instead of doing bitwise &.
                if(color[n]==color[neigh])res = res&false;
            }
        }
    }
    return res;
}

void Solve(int n, int m, vector<bool>&visited, vector<int>&color, vector<vector<int>>&adjList){
    CreateAdjList(n, m, adjList);
    // visited[1] = true;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            color[i] = 0;
            bool result = CheckBipartiteBFS(i, -1, visited, color, adjList);
            cout<<"Is the component Bipartite: "<<result<<endl;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<bool>visited(n+1);
    vector<int>color(n+1);
    vector<vector<int>>adjList(n+1);
    Solve(n, m, visited, color, adjList);
    return 0;
}