#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e5 + 10;
vector<bool> visited(MAX);
vector<int> graph[MAX];
vector<int> curr_component;
vector<vector<int>> components;

void DFS(int node){
    visited[node] = true;
    curr_component.push_back(node);
    for(int neigh: graph[node]){
        if(!visited[neigh]){
            DFS(neigh);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(visited[i])continue;
        curr_component.clear();
        DFS(i);
        components.push_back(curr_component);
    }
    cout<<"\nThe no. of components are : "<<components.size()<<endl;
    for(int i=0; i<components.size() ; i++){
        cout<<i<<" : ";
        for(int j: components[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}
int main(){

    solve();
    return 0;
}