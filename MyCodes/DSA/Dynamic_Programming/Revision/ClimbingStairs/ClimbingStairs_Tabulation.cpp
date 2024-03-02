#include <iostream>
#include <vector>
using namespace std;

int climbingStairs_Tabulation(int N){
    vector<int>dp(N+1, -1);
    
    // Base Condition/Case
    dp[0] = 1;
    if(N>1)dp[1] = 1;

    // Bottom-Up Calculation
    // Interpretation: If N=3, then it means we can take step_no-2 or step_no-1 from step_no-3, then afterwards the possible ways to reach to step_no-0 will be dp[2] and dp[1] respectively.  
    for(int i=2; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[N];
}

int main(){
    int N;
    cout<<"Enter the stair number: "<<endl;
    cin>>N;

    cout<<"The total no. of ways to climb are: "<<climbingStairs_Tabulation(N)<<endl;

    return 0;
}