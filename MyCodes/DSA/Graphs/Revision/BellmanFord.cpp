#include<iostream>
#include<vector>
#include<climits>
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

void createAdjList(int m, vector<Capsule>&edges){
    cout<<"\nIn createAdjList"<<endl;
    for(int i=0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back(Capsule(u,v,wt));
    }
    cout<<"\nExiting createAdjList"<<endl;
}

void BellmanFordAlgo(int n, int m, vector<int>&dist, vector<Capsule>&edges){
    // cout<<"\nEntering BellmanFordAlgo"<<endl;
    
    for(int i=0; i<m-1; i++){
        // cout<<"\nIn nested for loop."<<endl;
        for(auto itr:edges){
            if(dist[itr.u]!=INT_MAX){
                if(dist[itr.u] + itr.wt<dist[itr.v]){
                    dist[itr.v] = dist[itr.u] + itr.wt;
                }
            }
        }
    }
    // cout<<"\nExited Nested for loop."<<endl;
    bool flag = false;
    for(auto itr:edges){
        if(dist[itr.u] + itr.wt < dist[itr.v]){
            cout<<"Contains negative cycle"<<endl;
            flag=true;
            break;
        }
    }
    if(!flag){
        for(int i=1; i<=n; i++){
            cout<<i<<" - "<<dist[i]<<endl;
        }
    }
    // cout<<"\nExiting BellmanFordAlgo"<<endl;
}

void Solve(int n, int m, int src, vector<int>&dist, vector<Capsule>&edges){
    createAdjList(m, edges);
    dist[src] = 0;
    BellmanFordAlgo(n, m, dist, edges);
}

int main(){

    int n,m,src;
    cin>>n>>m>>src;

    vector<int>dist(n+1, INT_MAX);
    vector<Capsule>edges;

    Solve(n, m, src, dist, edges);
    return 0;
}