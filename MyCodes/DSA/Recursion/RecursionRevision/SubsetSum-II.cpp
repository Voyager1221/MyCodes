#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void subsetSumII(vector<vector<int>>&res, vector<int>&temp, vector<int>&vec, int index, int n){
    res.push_back(temp);
    
    // Base Condition
    if(index == n){
        return;
    }

    for(int i=index; i<n; i++){
        if(i>index && (vec[i] == vec[i-1]) )continue;
        temp.push_back(vec[i]);
        subsetSumII(res, temp, vec, i+1, n);
        temp.pop_back();
    }

}

void display(vector<vector<int>>&res){
    cout<<"Printing the results: "<<endl;
    for (auto i : res){
        for (auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;

    vector<int>vec(n);
    vector<int>temp;
    vector<vector<int>>res;
    
    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    sort(vec.begin(), vec.end());
    subsetSumII(res, temp, vec, 0, n);
    display(res);

    return 0;
}