#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void subsetSumI(vector<int>&res, vector<int>&vec, int sum, int index, int n){
    
    // Base Condition
    if(index == n){
        res.push_back(sum);
        return;
    }

    // Pick
    subsetSumI(res, vec, sum+vec[index], index+1, n);
    
    // Not Pick
    subsetSumI(res, vec, sum, index+1, n);

}

void display(vector<int>&res){
    sort(res.begin(), res.end());
    for(auto itr:res){
        cout<<itr<<" ";
    }
    cout<<endl;
}


int main(){
    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;

    vector<int>vec(n);
    vector<int>res;

    cout<<"Enter the elements of array: "<<endl;
    for (int i=0; i<n; i++){
        cin>>vec[i];
    }

    subsetSumI(res, vec, 0, 0, n);
    display(res);
    return 0;
}