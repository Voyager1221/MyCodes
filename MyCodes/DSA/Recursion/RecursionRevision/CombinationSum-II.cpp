#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinationSum_II(vector<vector<int>>&res, vector<int>&vec, vector<int>&temp, int index, int sum, int n, int target){
    // Base Condition - 1
    if(sum==target){
        res.push_back(temp);
        return;
    }

    for(int i=index; i<n; i++){
        
        if(i>index && vec[i]==vec[i-1])continue;
        if(sum+vec[i] > target)break;
        temp.push_back(vec[i]);
        combinationSum_II(res, vec, temp, i+1, sum+vec[i], n, target);
        temp.pop_back();
 

        // if( (i==index) || ((i-index)>=1 && (vec[i] != vec[i-1])) ){
        //     if(sum+vec[i] <= target){

        //         temp.push_back(vec[i]);
        //         sum += vec[i];
        //         combinationSum_II(res, vec, temp, i+1, sum, n , target);
        //         temp.pop_back();
        //         sum -= vec[i];
        //     }
        //     else{
        //         break;
        //     }
        // }
    }
}



void display(vector<vector<int>>&res){
    cout<<"Printing the result: "<<endl;
    for(auto i:res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}


int main(){
    int n,target;
    cout<<"Enter the size of array and the value of target: "<<endl;
    cin>>n>>target;

    vector<int>vec(n);
    vector<int>temp;
    vector<vector<int>>res;

    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }
    sort(vec.begin(), vec.end());
    
    combinationSum_II(res, vec, temp, 0, 0, n, target);
    display(res);

    return 0;
}