#include<iostream>
#include <vector>
using namespace std;

// Naive Method
void EdgeList(vector<pair<int,int>> &graph, int nodes, int edges){
    for(int i=0; i<edges; i++){
        int a,b;
        cin>>a>>b;
        graph.push_back({a,b});
        graph.push_back(make_pair(b,a));
    }
    cout<<"\nEdgeList Method"<<endl;
    
    cout<<"\nPrinting the pairs"<<endl;
    for(int i=0; i<graph.size(); i++){
        cout<<graph[i].first<<" "<<graph[i].second<<endl;
    }

}

//Adjacency List Method
void AdjacencyList(vector<vector<int>> graph, int nodes, int edges){
    for(int i=0; i<edges; i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    cout<<"\nAdjacency List Method"<<endl;
    
    cout<<"\nPrinting the pairs"<<endl;
    for(int i=0; i<nodes; i++){
        for(int j=0; j<graph[i].size(); j++)
            cout<<graph[i][j]<<" ";
        cout<<"\n";
    }
}

int main(){
    
    int nodes,edges;
    cout<<"Enter the no. of nodes and edges respectively : ";
    cin>>nodes>>edges;

    //vector <pair<int,int>> vec;
    //EdgeList(vec, nodes, edges);

    vector<vector<int>> vec(nodes+1);
    for(int i=0; i<edges; i++){
        int a,b;
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i=0; i<nodes+1; i++){
        for(auto j: vec[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}