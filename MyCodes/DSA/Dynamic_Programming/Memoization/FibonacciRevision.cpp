//Find the nth fibonacci number  
#include<iostream>
#include <vector>

typedef long long ll;
using namespace std;

ll fibo_dp(ll n, vector<int>&dp){
    cout<<"N: "<<n<<endl;
    if(n<=1){
        dp[n] = n;
        return n;
    }

    if(dp[n]!=-1)return dp[n];
    dp[n-1] = fibo_dp(n-1, dp);
    dp[n-2] = fibo_dp(n-2, dp);
    cout<<"dp["<<n-1<<"]: "<<dp[n-1]<<"dp["<<n-2<<"]: "<<dp[n-2]<<endl;
    return dp[n] = dp[n-1] + dp[n-2];
}

int main(){

    int T;
    cin>>T;
    while(T--){
        ll N;
        cin>>N;
        vector<int>dp(N+1);
        // ll dp[N+1];
        for(int i=0; i<=N; i++){
            dp[i] = -1;
        }
        cout<<"Result: "<<fibo_dp(N, dp)<<endl;
        
        cout<<"Printing dp"<<endl;
        for(auto i : dp){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}