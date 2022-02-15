#include <iostream>
#include <vector>
#include <algorithm>
// #include <climits>
using namespace std;

struct Capsule{
    int u;
    int v;
    int wt;

    Capsule(int u1, int v1, int wt1){
        u = u1;
        v = v1;
        wt = wt1;
    }
};

bool comp(Capsule a, Capsule b){
    return a.wt<b.wt;
}

void makeSet(int n, int m, vector<int>&parent, vector<Capsule>&edges){
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(Capsule(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);
}

int findPar(int node, vector<int>&parent){
    if(parent[node]==node)return node;

    //Doing path compression in the below line. This way we reduce traversing
    return parent[node] = findPar(parent[node], parent);
}

void Union(int u, int v, vector<int>&parent, vector<int>&rank){
    u = findPar(u, parent);
    v = findPar(v, parent);

    if(rank[u]>rank[v]){
        parent[v] = u;
    }else if(rank[u]<rank[v]){
        parent[u] = v;
    }else{
        parent[v] = u;
        rank[u]++;
    }
}

void makeConnections(int *cost, vector<int>&parent, vector<int>&rank, vector<pair<int,int>>&MST, vector<Capsule>&edges){
    for(auto itr: edges){
        if(findPar(itr.u, parent)!=findPar(itr.v, parent)){
            *cost = *cost+itr.wt;
            MST.push_back({itr.u, itr.v});
            Union(itr.u, itr.v, parent, rank);
        }
    }    
}

void Solve(int n, int m, vector<int>&parent, vector<int>&rank, vector<pair<int,int>>&MST, vector<Capsule>&edges){
    makeSet(n, m, parent, edges);
    int cost=0;
    makeConnections(&cost, parent, rank, MST, edges);
    cout<<"The cost of MST is : "<<cost<<endl;
    for(auto itr: MST){
        cout<<itr.first<<" - "<<itr.second<<endl;
    }
}

int main(){

    int n,m;
    cin>>n>>m;

    vector<int>parent(n+1);
    vector<int>rank(n+1, 0);
    vector<pair<int,int>>MST;
    vector<Capsule>edges;

    Solve(n, m, parent, rank, MST, edges);
    return 0;
}