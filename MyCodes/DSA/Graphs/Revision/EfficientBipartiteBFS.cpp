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

bool CheckBipartiteBFS(int node, vector<int>&color, vector<vector<int>>&adjList){
    queue<int>q;
    q.push(node);
    bool res = true;
    while(!q.empty()){
        int n = q.front();
        q.pop();
        cout<<n<<" ";
        for(int neigh:adjList[n]){
            if(color[neigh]==-1){
                color[neigh] = 1 - color[n];
                q.push(neigh);
            }
            // else if(color[n]==color[neigh])return false;
            else if(color[n]==color[neigh])res = res & false;
        }
    }
    // return true;
    return res;
}

void Solve(int n, int m, vector<int>&color, vector<vector<int>>&adjList){
    CreateAdjList(n, m, adjList);
    for(int i=1; i<=n; i++){
        if(color[i]==-1){
            color[i] = 0;
            bool result = CheckBipartiteBFS(i, color, adjList);
            cout<<"Is the component Bipartite: "<<result<<endl;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    // vector<bool>visited(n+1);
    vector<int>color(n+1, -1);
    vector<vector<int>>adjList(n+1);
    Solve(n, m, color, adjList);
    return 0;
}