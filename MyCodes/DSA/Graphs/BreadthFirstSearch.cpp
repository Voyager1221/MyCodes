#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MX = 1e5 + 5;
vector<vector<int>> tree(MX);
vector<bool> visited(MX);
queue<int> q;

int main(){
    int n;
    cout<<"Enter the no. of nodes: ";
    cin>>n;

    //Adjacency List
    for(int i=0; i<n-1; i++){
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    //BFS
    q.push(1); //Where 1 is the position of the node. It can also be considered as label
    visited[1] = true;
    while(!q.empty()){
        int node = q.front();
        cout<<node<<' ';
        q.pop();
        for(int neighbour:tree[node]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }
    return 0;
}