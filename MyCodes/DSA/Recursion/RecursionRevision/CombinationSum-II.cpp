#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationSum_uniqueCombo(vector<vector<int>>&res, vector<int>&vec, vector<int>&temp, int index, int target, int n){
    // Base Condition
    if(index == n){
        if(target == 0){
            res.push_back(temp);
        }
        return;
    }

    for(int i=index+1; i<n-1; i++){
        if(vec[i] != vec[index]){
            target -= vec[i];
            temp.push_back(vec[i]);
            combinationSum_uniqueCombo(res, vec, temp, i+1, target, n);
            temp.pop_back();
        }
    }

    target -= vec[index+1];
    temp.push_back(vec[index+1]);
    combinationSum_uniqueCombo(res, vec, temp, index+1, target, n);

}


void display(vector<vector<int>>&res){

    cout<<"Printing all the unique combinations that sums to target... "<<endl;
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){


    int n, target;
    cout<<"Enter the size of array and the value of target:"<<endl;
    cin>>n>>target;

    vector<int>vec(n);
    vector<int>temp;
    vector<vector<int>>res;

    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    sort(vec.begin(), vec.end());    
    temp.push_back(vec[0]);
    combinationSum_uniqueCombo(res, vec, temp, 0, target, n);
    display(res);
    return 0;
}