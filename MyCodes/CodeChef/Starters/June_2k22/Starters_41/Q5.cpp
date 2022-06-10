#include<iostream>

using namespace std;


bool DFS(int i, int j, int sum, int K, int N){
    if(i==N && j==N){
        cout<<"Sum : "<<sum<<endl;
        if(sum%2==K)return true;
        return false;
    }

    if(i+1<=N){
        if(DFS(i+1,j,sum + (i+1 + N*(j-1)), K, N))return true;
        // DFS(i+1,j,sum + (i+1 + N*(j-1)), K, N);
    }
    if(j+1<=N){
        if(DFS(i, j+1, sum + (i + N*(j+1-1)), K, N))return true;
        // DFS(i, j+1, sum + (i + N*(j+1-1)), K, N);
    }
    return false;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N>>K;

        if(DFS(1, 1, 1, K, N))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
};

