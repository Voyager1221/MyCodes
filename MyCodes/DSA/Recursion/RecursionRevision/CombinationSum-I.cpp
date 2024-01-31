#include<iostream>
#include<vector>

using namespace std;

void combinationSum(vector<int>&vec, vector<int>&temp, int index, int target, vector<vector<int>>&res, int n){
    // Base Condition
    if(index>=n){
        if(target==0){
            res.push_back(temp);
        }
        return;
    }

    // Pick
    target -= vec[index];
    if(target>=0){
        temp.push_back(vec[index]);
        combinationSum(vec, temp, index, target, res, n);
        temp.pop_back();
    }  
    
    // Not Pick
    target += vec[index];
    combinationSum(vec, temp, index+1, target, res, n);
}

void display(vector<vector<int>>&res){
    for(auto i:res){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int n,target;
    cout<<"Enter the size of array and target : "<<endl;
    cin>>n>>target;

    vector<int>vec(n);
    vector<int>temp;
    vector<vector<int>>res;

    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    combinationSum(vec, temp, 0, target, res, n);
    display(res);
    return 0;
}