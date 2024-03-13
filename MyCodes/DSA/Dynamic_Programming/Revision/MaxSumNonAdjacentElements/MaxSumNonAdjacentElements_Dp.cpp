#include <iostream>
#include <vector>

using namespace std;


int maxSumNonAdjacentElements_Dp(vector<int>&vec, vector<int>&dp, int index){
    // Base Condition
    if(index<=1)return vec[index];
    
    if(dp[index]!=0)return dp[index];
    int maxSumCurrIndex2Step = -1; 
    int maxSumCurrIndex3Step = -1; 
    if(index-2>=0){
        maxSumCurrIndex2Step = vec[index] + maxSumNonAdjacentElements_Dp(vec, dp, index-2);
    }
    if(index-3>=0){
        maxSumCurrIndex3Step = vec[index] + maxSumNonAdjacentElements_Dp(vec, dp, index-3);
    }
    return dp[index] = max(maxSumCurrIndex2Step, maxSumCurrIndex3Step);

}


int main(){
    int N;
    cout<<"Enter the size of array: "<<endl; 
    cin>>N;

    vector<int>vec(N+2, 0);
    vector<int>dp(N+2, 0);

    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<N; i++){
        cin>>vec[i];
    }

    cout<<"The max sum of non adjacent elements is: "<<maxSumNonAdjacentElements_Dp(vec, dp, N+1)<<endl;
    for(auto itr:dp){
        cout<<itr<<" ";
    }
    cout<<endl;
    return 0;
}