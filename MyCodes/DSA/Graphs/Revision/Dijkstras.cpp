#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n,m,source;
    cin>>n>>m>>source;

    vector<int>dist(n+1, INT_MAX);
    // vector<pair<int, int>> adjList[n+1];
    vector<vector<pair<int, int>>>adjList(n+1);
    
    //Storing AdjList
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back(make_pair(v,w));
        adjList[v].push_back({u,w});
    }
    //Dijkstra's Algorithm starts here. 

    //Performing Min-Heap Priority queue.
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq; //In-pair ==> (dist, from)
    
    dist[source] = 0;
    pq.push(make_pair(0, source));
    
    while(!pq.empty()){
        int distance = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int,int>>::iterator itr;
        for(itr = adjList[prev].begin(); itr!=adjList[prev].end(); itr++){
            if(dist[prev]+ itr->second < dist[itr->first]){
                dist[itr->first] = dist[prev] + itr->second;
                pq.push(make_pair(dist[itr->first], itr->first));
            }
        }
    }
    cout<<"The distance from source, "<<source<<" are:  "<<endl;
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }
    return 0;   
}