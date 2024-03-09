#include <iostream>
#include <vector>
using namespace std;


int frogJump_k(vector<int>&height, int index, int K){

    // Base Condition
    if(index==0){
        return 0;
    }
    if(index==1){
        return height[1] - height[0];
    }
    int minEnergy = INT_MAX;
    for(int jump=1; jump<=K; jump++){
        if(index-jump>=0){
            int energyDiff = abs(height[index] - height[index-jump]);
            int minJumpTillCurrStep = frogJump_k(height, index-jump, K) + energyDiff;
            minEnergy = min(minEnergy, minJumpTillCurrStep);
        }
    }
    return minEnergy;
}

int main(){
    int N,K;
    cout<<"Enter the no. of steps and the range of jump: "<<endl;
    cin>>N >>K;

    vector<int>height(N, -1);
    for(int i=0; i<N; i++){
        cin>>height[i];
    }
    cout<<"The minimum energy required is: "<<frogJump_k(height, N-1, K)<<endl;

    return 0;
}