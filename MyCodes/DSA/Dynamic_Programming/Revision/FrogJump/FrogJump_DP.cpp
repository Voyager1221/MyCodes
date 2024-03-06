#include <iostream>
#include <vector>

using namespace std;

int frogJump_DP(vector<int>&height, vector<int>&energy, int index){
    // Base Condition
    if(index == 0){
        return 0;
    }
    if(index == 1){
        return abs(height[1] - height[0]);
    }
    if(energy[index]!=INT_MAX)return energy[index];
    int energyDiff1 = abs(height[index] - height[index-1]);
    int energyDiff2 = abs(height[index] - height[index-2]);
    int totalEnergyReqFor1StepJumpInCurrentStage = frogJump_DP(height, energy, index-1) + energyDiff1;
    int totalEnergyReqFor2StepJumpInCurrentStage = frogJump_DP(height, energy, index-2) + energyDiff2;
    
    return energy[index] = min(totalEnergyReqFor1StepJumpInCurrentStage, totalEnergyReqFor2StepJumpInCurrentStage); 
}


int main(){

    int N;
    cout<<"Enter the no. of steps: "<<endl;
    cin>>N;

    vector<int>height(N, -1);
    vector<int>energy(N, INT_MAX);
    
    for(int i=0; i<N; i++){
        cin>>height[i];
    }

    cout<<"The minimum energy required is: "<<frogJump_DP(height, energy, N-1)<<endl;

    return 0;
}

