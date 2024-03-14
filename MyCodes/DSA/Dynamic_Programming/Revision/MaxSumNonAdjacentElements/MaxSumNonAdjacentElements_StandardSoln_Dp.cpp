#include <iostream>
#include <vector>

using namespace std;

int maxSumNonAdjacentElements_StdSoln_Dp(vector<int>&vec, vector<int>&dp, int index){

    // Base Condition
    if(index ==0)return vec[0];
    if(index<0) return 0;
    if(dp[index]!=0)return dp[index];

    int pickElement = vec[index] + maxSumNonAdjacentElements_StdSoln_Dp(vec, dp, index-2);
    int notPickElement = 0 + maxSumNonAdjacentElements_StdSoln_Dp(vec, dp, index-1);

    return dp[index] = max(pickElement, notPickElement);
}



int main(){

    int N;
    cout<<"Enter the size of array: "<<endl;
    cin>>N;

    vector<int>vec(N,0);
    vector<int>dp(N,0);
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<N; i++){
        cin>>vec[i];
    }


    cout<<"The maximum sum of non adjacent elements is: "<<maxSumNonAdjacentElements_StdSoln_Dp(vec, dp, N-1)<<endl;

    return 0;
}