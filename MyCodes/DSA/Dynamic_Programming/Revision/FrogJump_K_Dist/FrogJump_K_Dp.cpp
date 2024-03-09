#include <iostream>
#include <vector>

using namespace std;

int FrogJump_K_Dp(vector<int>&height, vector<int>&dp, int index, int K){

    // Base Condition
    if(index == 0)return 0;
    if(index==1){
        return height[1] - height[0];
    }
    if(dp[index]!=-1)return dp[index];
    
    int minEnergy = INT_MAX;
    
    for(int jump=1; jump<=K; jump++){
        if(index-jump>=0){

            int energyDiff = abs(height[index] - height[index-jump]);
            int minJumpTillCurrStep = FrogJump_K_Dp(height, dp, index-jump, K) + energyDiff;
            minEnergy = min(minEnergy, minJumpTillCurrStep);
        }
    }
    return dp[index] = minEnergy;
}


int main(){
    int N,K;
    cout<<"Enter the no. of steps and the range of jumps: "<<endl;
    cin>>N>>K;

    vector<int>height(N, -1);
    vector<int>dp(N, -1);
    for(int i=0; i<N; i++){
        cin>>height[i];
    }
    cout<<"The minimum energy required is: "<<FrogJump_K_Dp(height, dp, N, K)<<endl;
    return 0;
}