#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

const int MX = 1e5 + 5;
vector<vector<int>> graph(MX);
vector<bool> visited(MX);

void DFS(int Node){
    visited[Node] = true;
    cout<<Node<<" ";
    for(int neighbour : graph[Node]){
        if(!visited[neighbour]){
            DFS(neighbour);
        }
    }
}

int main(){
    vector <pair<int, int>> v1;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int a,b;

        cin>>a>>b;
        v1.push_back({a,b});
        v1.push_back(make_pair(b,a));
    }

    vector <vector<int>> v2(n+1);
    for(int i=0 ; i<m; i++){
        int a,b;

        cin>>a>>b;
        v2[a].push_back(b);
        v2[b].push_back(a);
    }

    vector <vector<int>> v3(n+1, vector<int>(n+1, 0));
    for(int i=0; i<m; i++){
        int a,b,c;
        cin>>a>>b;

        v3[a][b] = c;
        v3[b][a] = c;
    }
    DFS(1);
    //Breadth First Search
    queue<int> q;
    vector<bool> vis(MX);

    vis[1] = true;
    q.push(1);
    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(int neigh:graph[node]){
            if(!vis[neigh]){
                vis[neigh] = true;
                q.push(neigh);
            }
        }
    }

    //DFS using stack
    stack<int> s;
    vector<bool> vis_stack(MX);

    vis_stack[1] = true;
    while(!s.empty()){
        int node = s.top();
        cout<<node<<" ";
        s.pop();
        for(int neigh:graph[node]){
            if(!vis_stack[neigh]){
                vis_stack[neigh] = true;
                s.push(neigh);
            }
        }
    }

    return 0;
}