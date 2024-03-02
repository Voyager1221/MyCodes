#include <iostream>
#include <vector>
using namespace std;

int climbingStairs_DP(vector<int>&dp, int index){
    // Base Condition
    // We are returning 1 in case of index = 0 because to reach 0 a step needs to be taken. Special Case when N=0. In this solution index=0 can be interpreted as the difference between current and target step.
    if(index==0 || index==1)return 1;

    // Resolving Overlapping Sub-problems
    if(dp[index]!=-1)return dp[index];
    dp[index] = climbingStairs_DP(dp, index-1) + climbingStairs_DP(dp, index-2);
    return dp[index]; 
}

int main(){
    int N;
    cout<<"Enter the stair number: "<<endl;
    cin>>N;

    vector<int>dp(N+1, -1);

    cout<<"The total no. of ways to climb are: "<<climbingStairs_DP(dp, N)<<endl;
    return 0;
}