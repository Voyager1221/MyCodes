#include <iostream>
#include <vector>
using namespace std;

const int MX = 1e5 + 5;
vector<vector<int>> tree(MX);
vector<bool> visited(MX);

void DFS(int node){
    visited[node] = true;
    cout<<node<<' ';
    for(int neighbour:tree[node]){
        if(!visited[neighbour]){
            DFS(neighbour);
        }
    }
}

int main(){
    
    int n;
    cout<<"Enter the no. of nodes: ";
    cin>>n;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    DFS(1);
    return 0;
}