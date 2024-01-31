#include <iostream>
#include <vector>

using namespace std;

int countSubsequenceWithSumK(vector<int>&vec, int index, int sum, int n, int k){

    if(index == n){
        // Base Condition-1
        if(sum == k){
            return 1;
        }
        // Base Condition-1
        return 0;
    }

    return (countSubsequenceWithSumK(vec, index+1, sum+vec[index], n, k) 
    + countSubsequenceWithSumK(vec, index+1, sum, n , k));

}



int main(){
    int n,k;
    cout<<"Enter the no. of elements of array and the value of sum: "<<endl;
    cin>>n>>k;

    vector<int>vec(n);

    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    cout<<"The no. of subsequences with sum "<< k <<" are: ";
    cout<<countSubsequenceWithSumK(vec, 0, 0, n, k);
    return 0;
}