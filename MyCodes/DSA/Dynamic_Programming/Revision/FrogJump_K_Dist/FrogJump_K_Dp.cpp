#include <iostream>
#include <vector>

using namespace std;

int FrogJump_K_Dp(vector<int>&height, vector<int>&dp, int index, int K){

    // Base Condition
    if(index == 0)return 0;
    if(index==1){
        return abs(height[1] - height[0]);
    }
    // if(dp[index]!=-1)return dp[index];
    if(dp[index]!=INT_MAX)return dp[index];
    
    // int minEnergy = INT_MAX;
    
    for(int jump=1; jump<=K; jump++){
        if(index-jump>=0){

            int energyDiff = abs(height[index] - height[index-jump]);
            int minEnergyTillCurrStep = FrogJump_K_Dp(height, dp, index-jump, K) + energyDiff;
            // minEnergy = min(minEnergy, minEnergyTillCurrStep);
            dp[index] = min(dp[index], minEnergyTillCurrStep);
        }
    }
    // return dp[index] = minEnergy;
    return dp[index];
}

void display(vector<int>&dp){
    for(auto itr:dp){
        cout<<itr<<" ";
    }
}

int main(){
    int N,K;
    cout<<"Enter the no. of steps and the range of jumps: "<<endl;
    cin>>N>>K;

    vector<int>height(N, -1);
    // vector<int>dp(N, -1);
    vector<int>dp(N, INT_MAX);
    for(int i=0; i<N; i++){
        cin>>height[i];
    }
    cout<<"The minimum energy required is: "<<FrogJump_K_Dp(height, dp, N-1, K)<<endl;
    
    display(dp);

    return 0;
}