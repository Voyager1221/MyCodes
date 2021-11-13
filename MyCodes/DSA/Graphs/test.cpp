#include<iostream>
#include<vector>
#include<iterator>
#include<queue>

using namespace std;

const int MX = 1e5 +5;

queue<int> que;
vector<vector<int>> vec(MX);
//vector<bool> visited(MX);
vector<vector<bool>> visited;

void DFS(int node){
    int num = node;
    vector <int> nON;
    que.pop();
    //visited[num] = true;
    for(int neigh: vec[node]){
        if(true){
            
            for( int neighOfNeigh : vec[neigh]){
                if(visited[num][neighOfNeigh]==false && (neighOfNeigh>num+1 || neighOfNeigh<num-1)){
                    visited[num][neighOfNeigh] = true;
                    visited[neighOfNeigh][num] = true;
                    //vec[num].push_back(nieghOfNeigh);
                    //vec[neighOfNeigh].push_back(num); 
                    nON.push_back(neighOfNeigh);
                }else{
                    visited[num][neighOfNeigh] = true;
                    visited[neighOfNeigh][num] = true;
                }
            }
            que.push(neigh);
        }
    }
    for(auto &itr:nON){
        vec[num].push_back(itr);
        vec[itr].push_back(num);
    }
    //visited[num] = false;

}

int main(){
    int N, M;
    cin>>N>>M;
    
    if(M==N-1){
        for(int i=1; i<=M; i++){
            cout<<i<<" "<<i+1<<endl;
        }
    }else{
        for(int i=1; i<N; i++){
            vec[i].push_back(i+1);
            vec[i+1].push_back(i);
        }
        
        que.push(1);
        int t = M;
        while(t-(N-1)>0){
            DFS(que.front());
            t--;
        }
        cout<<"\nPrinting the complex part"<<endl;
        for(int i = 1 ; i<=N; i++){
            for(int j=0; j<vec[i].size(); j++){
                cout<<i<<" "<<vec[i][j]<<endl;
            }
        }
    }
    return 0;
}