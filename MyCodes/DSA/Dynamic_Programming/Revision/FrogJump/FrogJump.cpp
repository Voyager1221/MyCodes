#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int frogJump(vector<int>&height, int index, int energy, int minEnergy){
    // Base Condition
    if(index==0){
        return 0;
    }
    if(index==1){
       return abs(height[1] - height[0]);
    }
    int energyDiff1 = abs(height[index] - height[index-1]);
    int energyDiff2 = abs(height[index] - height[index-2]);
    return energy+= min(frogJump(height, index-1, energy, minEnergy)+energyDiff1,frogJump(height, index-2, energy, minEnergy)+energyDiff2);
}


int main(){
    int N;
    cout<<"Enter the no. of steps: "<<endl;
    cin>>N;
    int energy = 0;
    int minEnergy = INT_MAX;
    vector<int>height(N,-1);
    cout<<"Enter the height of steps: "<<endl;
    for(int i=0; i<N; i++){
        cin>>height[i]; 
    }    
    
    cout<<"The result is : "<<frogJump(height, N-1, energy, minEnergy)<<endl;
    return 0;
}