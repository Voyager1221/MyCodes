#include<iostream>
#include<vector>

using namespace std;

int maxSumNonAdjacentElements_Tab_Opt(vector<int>&vec2, int NN){

    int maxSumTillLast2Index = vec2[0];
    int maxSumTillLast3Index = 0;
    int last = 0;
    if(NN>=1){
        maxSumTillLast3Index = vec2[1];
        last = vec2[1];
    }
    int maxSum = max(maxSumTillLast2Index, maxSumTillLast3Index);

    for(int index=2; index<NN; index++){
        int maxSum2Step = vec2[index]+maxSumTillLast2Index;
        int maxSum3Step = vec2[index]+maxSumTillLast3Index;
        
        int maxSumTillCurrStep = max(maxSum2Step, maxSum3Step);
        maxSum = max(maxSum, maxSumTillCurrStep);
        
        maxSum3Step = maxSum2Step;
        maxSum2Step = last;
        last = maxSumTillCurrStep;
    }
    return maxSum;
}

int maxSumNonAdjacentElements_Tab(vector<int>&vec, int N){
    vector<int>maxSumTillIndex(N, 0);

    // Base Condition
    maxSumTillIndex[0] = vec[0];
    if(N>=1)maxSumTillIndex[1] = vec[1];
    if(N>=2)maxSumTillIndex[2] = vec[2]+vec[0];
    int maxSum = -1;

    for(int index=3; index<N; index++){
        int maxSumCurrIndex2Step = vec[index] + maxSumTillIndex[index-2]; 
        int maxSumCurrIndex3Step = vec[index] + maxSumTillIndex[index-3]; 
        maxSumTillIndex[index] = max(maxSumCurrIndex2Step, maxSumCurrIndex3Step);
        maxSum = max(maxSum, maxSumTillIndex[index]);
    }
    return maxSum;
}

int main(){
    int N;
    cout<<"Enter the size of array: "<<endl;
    cin>>N;

    vector<int>vec(N, 0);
    vector<int>vec2(N+2, 0);
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<N; i++){
        cin>>vec[i];
        vec2[i] = vec[i];
    }
    cout<<"The max sum of non adjacent elements is : "<<maxSumNonAdjacentElements_Tab(vec,N)<<endl;
    cout<<"The max sum of non adjacent elements using optimized tabulation is : "<<maxSumNonAdjacentElements_Tab_Opt(vec2,N+2)<<endl;

    return 0;
}