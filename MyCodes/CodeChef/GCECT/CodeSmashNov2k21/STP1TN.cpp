#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MX = 2e5 +5;
vector<vector<int>> vec(MX);
vector<vector<bool>> visited(MX);
//queue<int> q;
	
void DFS(int node, int A){
    int n = node;
    int cnt=0;
    //q.pop();
    for(int neigh:vec[n]){
        if(visited[n][neigh]==false){
            cnt++;
            
            visited[n][neigh] = true;
            visited[neigh][n] = true;
            
            if(cnt<=2 && neigh==A){
                cout<<"YES"<<endl;
            }
            
            for(int neighOfNeigh: vec[neigh]){
                cnt++;

                if(visited[neigh][neighOfNeigh]==false){
                    
                    visited[neighOfNeigh][neigh] = true;
                    visited[neigh][neighOfNeigh] = true;
                    
                    if(cnt<=2 && neighOfNeigh==A){
                        cout<<"YES"<<endl;
                    }
                    else cout<<"NO"<<endl;
                    
                }
            }

            
        }
    }
}

int main() {
	// your code goes here
	int A,B;
	cin>>A>>B;
	
	for(int k=0; k<B; k++){
	    int i,j;
	    cin>>i>>j;
	    
	    vec[i].push_back(j);
	    vec[j].push_back(i);
	}
// 	for(int i=1; i<=vec.size(); i++){
// 	    for(int j=0; j<vec[i].size(); j++){
// 	        cout<<i<<" "<<vec[i][j]<<endl;
// 	    }
// 	}
    //DFS(1, A);
	for(int i=1; i<=visited.size(); i++){
        for(int j=0; j<visited[i].size(); j++){
            cout<<i<<" "<<j<<endl;
        }
    }
	return 0;
}
