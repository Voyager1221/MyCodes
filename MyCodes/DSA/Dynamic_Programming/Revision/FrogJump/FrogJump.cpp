#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int frogJump(vector<int>&height, int index){
    // Base Condition
    if(index==0){
        return 0;
    }
    if(index==1){
       return abs(height[1] - height[0]);
    }
    int energyDiff1 = abs(height[index] - height[index-1]);
    int energyDiff2 = abs(height[index] - height[index-2]);
    int totalEnergyReqFor1StepJumpInCurrentStage = frogJump(height, index-1) + energyDiff1;
    int totalEnergyReqFor2StepJumpInCurrentStage = frogJump(height, index-2) + energyDiff2;
    return min(totalEnergyReqFor1StepJumpInCurrentStage, totalEnergyReqFor2StepJumpInCurrentStage);
}


int main(){
    int N;
    cout<<"Enter the no. of steps: "<<endl;
    cin>>N;
    
    vector<int>height(N,-1);
    cout<<"Enter the height of steps: "<<endl;
    for(int i=0; i<N; i++){
        cin>>height[i]; 
    }    
    
    cout<<"The result is : "<<frogJump(height, N-1)<<endl;
    return 0;
}