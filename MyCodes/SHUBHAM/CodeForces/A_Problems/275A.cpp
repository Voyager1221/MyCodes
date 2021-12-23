#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sum(3, vector<int>(3));
vector<bool> visited[3];

void DFS(int i, int j,int neigh_sum, vector<vector<int>> &circuit){
    visited[i][j] = true;
    if(i<0 || j<0 || i>2 || j>2)return;
    
    sum[i][j] += neigh_sum + circuit[i][j]; 
    // sum += circuit[i][j];    
    cout<<"\nControl is here...tadaaaa"<<endl;
    DFS(i+1, j, circuit[i][j], circuit);
    DFS(i-1, j, circuit[i][j], circuit);
    DFS(i, j-1, circuit[i][j], circuit);
    DFS(i, j+1, circuit[i][j], circuit);
}

void input(vector<vector<int>> &circuit){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int toggles;
            cin>>circuit[i][j];
        }
    }
}

void solve(vector<vector<int>> &circuit){
    
    DFS(0,0,0,circuit);
        
}

void display(vector<vector<int>> &circuit){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<circuit[i][j];
        }
        cout<<endl;
    }
}


int main(){

    vector<vector<int>> circuit(3, vector<int> (3));
    input(circuit);
    solve(circuit);
    display(circuit);

    return 0;
}