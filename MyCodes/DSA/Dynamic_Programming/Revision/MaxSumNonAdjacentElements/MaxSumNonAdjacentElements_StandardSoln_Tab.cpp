#include <iostream>
#include <vector>

using namespace std;

int maxSumNonAdjacentElements_StdSoln_Tab(vector<int>&vec, int N){

    vector<int>maxSumTillIndex(N, 0);

    // Base Condition
    maxSumTillIndex[0] = vec[0];
    
    for(int index=1; index<N; index++){
        int pickElement = vec[index];
        if(index>=2) pickElement += maxSumTillIndex[index-2];
        
        int notPickElement = 0 + maxSumTillIndex[index-1];
        maxSumTillIndex[index] = max(pickElement, notPickElement);
    }
    return maxSumTillIndex[N-1];
}


int maxSumNonAdjacentElements_StdSoln_Tab_Opt(vector<int>&vec, int N){
    int last1 = vec[1];
    int last2 = vec[0];
    
    for(int index=2; index<N; index++){
        int pickElement = vec[index] + last2;
        int notPickElement = 0 + last1;

        int maxSumTillCurrIndex = max(pickElement, notPickElement);
        last2 = last1;
        last1 = maxSumTillCurrIndex;
    }
    return last1;
}


int main(){

    int N;
    cout<<"Enter the size of array: "<<endl;
    cin>>N;

    vector<int>vec(N,0);
    
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<N; i++){
        cin>>vec[i];
    }


    cout<<"The maximum sum of non adjacent elements is: "<<maxSumNonAdjacentElements_StdSoln_Tab(vec, N)<<endl;
    cout<<"The maximum sum of non adjacent elements using optimized tabulation is: "<<maxSumNonAdjacentElements_StdSoln_Tab_Opt(vec, N)<<endl;

    return 0;
}