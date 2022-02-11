//Disjoint Set, Union by Rank and Path Compression.

#include <iostream>
#include <vector>
using namespace std;

void makeSet(int n, vector<int>&parent, vector<int>&rank){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
int findPar(int node, vector<int>&parent){
    if(node == parent[node])return node;
    
    return parent[node] = findPar(node, parent);
}

void Union(int u, int v, vector<int>&parent, vector<int>&rank){
    u = findPar(u, parent);
    v = findPar(v, parent);

    if(rank[u]<rank[v]){
        parent[u] = v;
    }else if(rank[u]> rank[v]){
        parent[v] = u;
    }else{
        parent[u] = v;
        rank[v]++;
    }
}

void CheckComponent(int u, int v){
    if(findPar(u)!= findPar(v))cout<<"Elements of different components."<<endl;
    else cout<<"Elements of same component"<<endl;
}

void Solve(int n, int m, vector<int>&parent, vector<int>&rank){
    makeSet(n, parent, rank);
    while(m--){
        int u,v;
        cin>>u>>v;
        Union(u, v, parent, rank);
    }
    CheckComponent(1,7);

}



int main(){
    // int n,m;
    // cin>>n>>m;
    int n;
    cin>>n;
    vector<int>parent(n);
    vector<int>rank(n);
    Solve(n, m, parent, rank);

}