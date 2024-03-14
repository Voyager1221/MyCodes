#include <iostream>
#include <vector>

using namespace std;

int maxSumNonAdjacentElements_StdSoln(vector<int>&vec, int index){
    
    // Base Condition
    if(index==0)return vec[0];
    if(index<0)return 0;

    int pickElement = vec[index] + maxSumNonAdjacentElements_StdSoln(vec, index-2);
    int notPickElement = 0 + maxSumNonAdjacentElements_StdSoln(vec, index-1);
    
    return max(pickElement, notPickElement);
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


    cout<<"The maximum sum of non adjacent elements is: "<<maxSumNonAdjacentElements_StdSoln(vec, N-1)<<endl;

    return 0;
}