#include <iostream>
#include <vector>

using namespace std;
const int MAX = 1e5 + 10;

vector<bool> visited(MAX);
vector<int> graph[MAX];

void DFS(int node){
    visited[node] = true;
    for(int neigh: graph[node]){
        if(!visited[neigh]){
            DFS(neigh);
        }
    }
}

void solve(){
    
    int n,m;
    cin>>n>>m;
    for(int i=0 ; i<m; i++){
        int a,b;
        cin>>a>>b;
        // cout<<a<<" "<<b<<endl;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        cout<<i<<" : ";
        for(int j:graph[i]){
            cout<<" "<<j<<" ";
        }
        cout<<endl;
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        DFS(i);
        cnt++;
    }
    cout<<"No of connected components are: "<<cnt<<endl;
}
int main(){
    solve();
    return 0;
}