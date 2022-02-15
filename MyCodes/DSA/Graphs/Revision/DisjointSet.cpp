//Disjoint Set, Union by Rank and Path Compression.

#include <iostream>
#include <vector>
using namespace std;

void makeSet(int n, vector<int>&parent, vector<int>&rank){
    for(int i=1; i<=n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
int findPar(int node, vector<int>&parent){
    if(node == parent[node]){
        return node;
    }
    
    return parent[node] = findPar(parent[node], parent);
}

void Union(int u, int v, vector<int>&parent, vector<int>&rank){
    u = findPar(u, parent);
    v = findPar(v, parent);

    if(rank[u]<rank[v]){
        parent[u] = v;
    }else if(rank[u]> rank[v]){
        parent[v] = u;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}

void CheckComponent(int u, int v, vector<int>&parent){
    if(findPar(u, parent)!= findPar(v, parent))cout<<"Elements of different components."<<endl;
    else cout<<"Elements of same component"<<endl;
}

void Solve(int n,int m, vector<int>&parent, vector<int>&rank){
    makeSet(n, parent, rank);
    while(m--){
        int u,v;
        cin>>u>>v;
        Union(u, v, parent, rank);
    }
    CheckComponent(1,7, parent);

}

int main(){
    int n,m;

    cin>>n>>m;
    
    vector<int>parent(n+1);
    vector<int>rank(n+1);
    Solve(n, m, parent, rank);

}