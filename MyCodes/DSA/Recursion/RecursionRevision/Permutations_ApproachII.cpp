#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>&temp, int i, int j){
    int t = temp[i];
    temp[i] = temp[j];
    temp[j] = t;
}

void permutations_approachII(vector<vector<int>>&res, vector<int>&vec, int pivot, int n){
    // Base Condition
    if(pivot == n){
        res.push_back(vec);
        return;
    }

    for(int i=pivot; i<n; i++){
        swap(vec, i, pivot);
        permutations_approachII(res, vec, pivot+1, n);
        swap(vec, i, pivot);
    }

}

void display(vector<vector<int>>&res){
    cout<<"Printing the results: "<<endl;
    for(auto i:res){
        for(auto j:i){
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
    vector<vector<int>>res;

    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>> vec[i];
    }
    vector<int>temp = vec;

    permutations_approachII(res, vec, 0, n);
    display(res);
    return 0;
}