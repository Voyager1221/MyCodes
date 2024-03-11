#include <iostream>
#include <vector>

using namespace std;

int maxSumNonAdjacentElements(vector<int>&vec, int index){

    // Base Condition
    if(index == 0)return vec[0];
    if(index == 1)return vec[1];
    int maxSum2Step = INT_MAX;
    int maxSum3Step = INT_MAX;
    if(index-2>=0){ 
        maxSum2Step = vec[index] + maxSumNonAdjacentElements(vec, index-2);   
    }

    if(index-3>=0){
        cout<<"The value of index in 3steps is: "<<index-3<<endl;
        maxSum3Step = vec[index] + maxSumNonAdjacentElements(vec, index-3);
    }

    return max(maxSum2Step, maxSum3Step);
}

int main(){

    int N;
    cout<<"Enter the size of array: "<<endl;
    cin>>N;

    vector<int>vec(N+2, 0);
    
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<N; i++){
        cin>>vec[i];
    }

    cout<<"The max sum of non adjacent elemens in array is: "<<maxSumNonAdjacentElements(vec, N+1)<<endl;
    for(auto i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}