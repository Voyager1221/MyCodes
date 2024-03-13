#include <iostream>
#include <vector>

using namespace std;
// Main Concept of Number Theory
// Multiples of 2 makes up for all the even nos including 0
// Combination of 2 and 3 makes up for all the odd nos excluding 1 which needs to be handled specially.
// 2^x + 3 will make all the possible odd nos where x is an integer.
// Ex (2^1)+3 = 5, (2^2)+3 = 7, (2^3)+3 = 9
int maxSumNonAdjacentElements(vector<int>&vec, int index){

    // Base Condition
    if(index == 0)return vec[0];
    if(index == 1)return vec[1];
    int maxSum2Step = -1;
    int maxSum3Step = -1;
    if(index-2>=0){ 
        maxSum2Step = vec[index] + maxSumNonAdjacentElements(vec, index-2);   
    }

    if(index-3>=0){
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