#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void CreateAdjList(int n, int m, vector<vector<int>> &adjList){
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
}

void BFS(int node, vector<bool> &vis_BFS, queue<int> &q, vector<vector<int>>&adjList, vector<int> &Component){
    q.pop();
    Component.push_back(node);
    for(int neigh:adjList[node]){
        if(!vis_BFS[neigh]){
            q.push(neigh);
            vis_BFS[neigh] = true;
        }
    }
}

void DFS(int node, vector<bool> &vis_DFS, vector<vector<int>>&adjList, vector<int> & Component){
    vis_DFS[node] = true;
    Component.push_back(node);
    for(int neigh:adjList[node]){
        if(!vis_DFS[neigh]){
            DFS(neigh, vis_DFS, adjList, Component);
        }
    }
}

void solve(int n, int m, vector<bool> &vis_BFS, vector<bool>&vis_DFS, queue<int>&q, vector<vector<int>>&adjList){
    
    CreateAdjList(n, m, adjList);
    q.push(1);
    vis_BFS[1] = true;

    vector<int> Component;
    vector<vector<int>> listOfComponents;
    int cnt_BFS=0,cnt_DFS=0;
    
    // for(int i=1; i<=n; i++){
    //     if(!vis_BFS[i]){
    //         Component.clear();
    //         BFS(q.front(), vis_BFS, q, adjList, Component);
    //         cnt_BFS++;
    //         listOfComponents.push_back(Component);
    //         cout<<endl;
    //     }
    // }
    // //Printing Results for BFS
    // for(int i=0; i<=listOfComponents.size(); i++){
    //     cout<<i+1<<": ";
    //     for(int j:listOfComponents[i]){
    //         cout<<j<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"No. of components via BFS: "<<cnt_BFS<<endl;
    
    // listOfComponents.clear();
    
    for(int i=1; i<=n; i++){
        if(!vis_DFS[i]){
            Component.clear();
            DFS(i, vis_DFS, adjList, Component);
            cnt_DFS++;
            listOfComponents.push_back(Component);
            cout<<endl;
        }
    }
    //Printing Results for DFS
        for(int i=0; i<listOfComponents.size(); i++){
        cout<<i+1<<": ";
        for(int j:listOfComponents[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<"No. of components via DFS: "<<cnt_DFS<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<bool>vis_BFS(n+1), vis_DFS(n+1);
    queue<int> q;
    vector<vector<int>> adjList(n+1);
    solve(n, m, vis_BFS, vis_DFS, q, adjList);
    return 0;
}