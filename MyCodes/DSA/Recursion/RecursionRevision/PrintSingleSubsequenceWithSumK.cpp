#include <iostream>
#include <vector>
using namespace std;

bool printSingleSubsequenceWithSumK(vector<int>&res, vector<int>&vec, int sum, int index, int n, int k ){
    // Base Condition-1
    if(index==n){
        return false;
    }
    if(sum == k){
        return true;
    }
    res.push_back(vec[index]);
    if(printSingleSubsequenceWithSumK(res, vec, sum+vec[index], index+1, n, k)){
        return true;
    }    
    res.pop_back();
    if(printSingleSubsequenceWithSumK(res, vec, sum, index+1, n, k)){
        return true;
    }
    return false;
}

void display(vector<int>&res){
    for(auto itr:res){
        cout<<itr<<" ";
    }
    cout<<endl;
}

int main(){
    
    int n, k;
    cout<<"Enter the no. of elements of array and the sum: "<<endl;
    cin>>n>>k;

    vector<int>res;
    vector<int>vec(n);

    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    printSingleSubsequenceWithSumK(res, vec, 0, 0, n, k);
    display(res);


    return 0;   
}