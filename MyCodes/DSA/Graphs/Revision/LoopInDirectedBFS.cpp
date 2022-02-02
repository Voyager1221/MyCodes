#include <iostream>
#include <queue>
#include <vector>

using namespace std;
class TopologicalSort{
    public:
        void CreateAdjList(int M, vector<int>&in_deg, vector<vector<int>>&adjList);
        void TopoSort(int N, vector<int>&in_deg, vector<int>&topo, vector<vector<int>>&adjList);
        void Display(vector<int>&topo);
};
void TopologicalSort::CreateAdjList(int M, vector<int>&in_deg, vector<vector<int>>&adjList){
    for(int i=0; i<M; i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        in_deg[b]++;
    }
}

void TopologicalSort::TopoSort(int N, vector<int>&in_deg, vector<int>&topo, vector<vector<int>>&adjList){
    queue<int>q;
    //There will be atleast one element that will have In-degree=0, otherwise the graph won't be DAG.    
    for(int i=1; i<=N; i++){
        if(in_deg[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;
        topo.push_back(node);
        for(auto neigh: adjList[node]){
            in_deg[neigh]--;
            if(in_deg[neigh]==0){
                q.push(neigh);
            }
        }
    }

    if(cnt==N)cout<<"Not Directed Cyclic"<<endl;
    else cout<<"It is Directed Cyclic"<<endl;
}

void TopologicalSort::Display(vector<int>&topo){
    cout<<"\nTopological sort using BFS: ";
    for(int i=0; i<topo.size(); i++){
        cout<<topo[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int N, M;
    cin>>N>>M;

    vector<int>in_deg(N+1);
    vector<int>topo;
    vector<vector<int>>adjList(N+1);

    TopologicalSort obj1;
    obj1.CreateAdjList(M, in_deg, adjList);
    obj1.TopoSort(N, in_deg, topo, adjList);
    obj1.Display(topo);
    return 0;
}