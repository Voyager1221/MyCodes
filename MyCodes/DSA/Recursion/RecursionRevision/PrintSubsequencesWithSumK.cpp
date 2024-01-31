#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// Correct Logic
void subsequencesWithSumK(vector<vector<int>>&res, vector<int>&vec, vector<int>&temp , int sum, int index, int n, int k){
    // Base Condition-1
    if(index==n){
        if(sum==k){
            res.push_back(temp);
        }
        return;
    }

    temp.push_back(vec[index]);
    subsequencesWithSumK(res, vec, temp, sum+vec[index], index+1, n, k);

    temp.pop_back();
    subsequencesWithSumK(res, vec, temp, sum, index+1, n, k);

}

// The conditions used in this functions are not appropiate. Since we are returning from the function as soon as we achieve the target, without even visiting all the elements
void subsequencesWithSumK2(vector<vector<int>>&res, vector<int>&vec, vector<int>&temp , int sum, int index, int n, int k){
    // Base Condition-1
    if(sum == k){
        res.push_back(temp);
        // If we want to include 0 in our irrespective of 0's position in array then comment 'return'
        // else 0's position is after sum == k, then some or all of the case will be missed

        // Edge Cases
        // For zero and negative integers, we should comment return but again it leads to priting of multiple copies of a distinct solution 
        
        return;

    }
    // Base Condition-2
    if(index==n){
        return;
    }
    

    temp.push_back(vec[index]);
    subsequencesWithSumK2(res, vec, temp, sum+vec[index], index+1, n, k);

    temp.pop_back();
    subsequencesWithSumK2(res, vec, temp, sum, index+1, n, k);

}

void display(vector<vector<int>>&res){
    cout<<"Printing the results: "<<endl;
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){

    int n,k;
    cout<<"Enter the no. of elements and the required sum: "<<endl;
    cin>>n>>k;

    vector<vector<int>>res;
    vector<int> vec(n);
    vector<int>temp;
    
    cout<<"Enter the elements of array/vector:"<<endl;

    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    subsequencesWithSumK(res, vec, temp, 0, 0, n, k);
    display(res);
    vector<int> temp2;
    vector<vector<int>>res2;
    cout<<"Printing result of returning on the spot as the sum hits required target: "<<endl;
    subsequencesWithSumK2(res2, vec, temp2, 0, 0, n, k);
    display(res2);
}