#include <iostream>
#include <vector>

using namespace std;


int frogJump_Tabulation(vector<int>&height, int N){
    vector<int>energy(N, INT_MAX);
    
    // Base Condition
    energy[0] = 0;
    energy[1] = abs(height[1] - height[0]);

    for(int i=2; i<N; i++){
        int energyDiff1 = abs(height[i] - height[i-1]);
        int energyDiff2 = abs(height[i] - height[i-2]);
        energy[i] = min(energy[i-1]+energyDiff1, energy[i-2]+energyDiff2);
    }
    return energy[N-1];
}

int frogJump_TabulationOptimized(vector<int>&height, int N){
    
    // Base Condition
    int minEnergyReqTillLast2Step = 0;
    int minEnergyReqTillLast1Step = abs(height[1] - height[0]);
    

    for(int i=2; i<N; i++){
        int energyDiff1 = abs(height[i] - height[i-1]);
        int energyDiff2 = abs(height[i] - height[i-2]);
        int minEnergyReqTillCurrentStep = min(minEnergyReqTillLast1Step+energyDiff1, minEnergyReqTillLast2Step+energyDiff2);
        
        minEnergyReqTillLast2Step = minEnergyReqTillLast1Step;
        minEnergyReqTillLast1Step = minEnergyReqTillCurrentStep;
    }
    return minEnergyReqTillLast1Step;
}


int main(){

    int N;
    cout<<"Enter the no. of steps: "<<endl;
    cin>>N;

    vector<int>height(N, INT_MAX);
    for(int i=0; i<N; i++){
        cin>>height[i];
    }

    cout<<"The minimum energy required is: "<<frogJump_Tabulation(height, N)<<endl;
    cout<<"The minimum energy required is: "<<frogJump_TabulationOptimized(height, N)<<endl;
    return 0;
}