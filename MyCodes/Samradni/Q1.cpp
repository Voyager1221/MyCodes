#include <iostream>
#include <vector>
using namespace std;

int PurchaseCheaply(int N, vector<vector<int>>&vec){
    int ans=1000000000; 
    for(int i=0; i<vec.size(); i++){
        cout<<"vec[i][0]: "<<vec[i][0]<<endl;
        if(vec[i][0]>=N){
            ans = min(ans, N*vec[i][1]+vec[i][2]);
        }
    }
    return ans;
}

int main(){
    int N;
    int S;
    cin>>N>>S;
    vector<vector<int>>vec(S, vector<int>(3,0));
    for(int i=0; i<S; i++){
        cin>>vec[i][0];
        cin>>vec[i][1];
        cin>>vec[i][2];
    }
    cout<<PurchaseCheaply(N, vec)<<endl;
}