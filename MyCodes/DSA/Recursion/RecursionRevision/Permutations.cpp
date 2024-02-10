#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void permutations(vector<vector<int>>&res, vector<int>&temp, vector<bool>&vis, vector<int>&vec, int n){
    // Base Condition
    if(temp.size() == n){
        res.push_back(temp);
        return;
    }

    for(int i=0; i<n; i++){
        if(!vis[i]){
            vis[i] = true;
            temp.push_back(vec[i]);
            permutations(res, temp, vis, vec, n);
            vis[i] = false;
            temp.pop_back();
        }
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
    vector<int>temp;
    vector<bool>vis(n,0);
    vector<vector<int>>res;

    cout<<"Enter the elements of array: "<<endl;

    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    permutations(res, temp, vis, vec, n);
    display(res);

    return 0;
}
