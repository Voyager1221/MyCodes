#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e5 + 10;

vector<bool> visited(MAX);
vector<int> graph[MAX];

bool DFS(int child, int parent){

    visited[child] = true;
    for(int childOfChild : graph[child]){
        if(visited[childOfChild] && childOfChild == parent) continue;
        if(visited[childOfChild] && childOfChild != parent) return true;

        DFS(childOfChild, child);
    }
    return false;
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

    bool containsLoop = false;

    for(int i=1; i<=n; i++){
        if(visited[i]) continue;
        containsLoop |= DFS(i,0);
    }
    cout<<containsLoop<<endl;
}

int main(){
    solve();
    return 0;
}