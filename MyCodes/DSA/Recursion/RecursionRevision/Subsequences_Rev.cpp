#include <iostream>
#include <vector>

using namespace std;

void subsequences(vector<vector<int>>&res, vector<int>&vec, vector<int>&input, int index, int n){

    // Base Condition
    if(index == n){
        res.push_back(vec);
        return;
    }
    
    vec.push_back(input[index]);
    subsequences(res, vec, input, index+1, n);

    vec.pop_back();
    subsequences(res, vec, input, index+1, n);


// To Print the sequence in vertically reverse order.
    // subsequences(res, vec, input, index+1, n);
 
    // vec.push_back(input[index]);
    // subsequences(res, vec, input, index+1, n);
    // vec.pop_back();
}


int main(){
    int n;
    cout<<"Enter the no. of elements: "<<endl;
    cin>>n;
    vector<vector<int>>res;
    vector<int> vec;
    vector<int> input(n);
    vector<bool>visited(n,0);
    cout<<"Enter the elements: "<<endl;
    for(int i=0; i<n; i++){
        cin>>input[i];
    }
    
    subsequences(res, vec, input, 0, n);
    cout<<"Printing the subsequences..."<<endl;
    for(int i=0; i<res.size(); i++){
        for( int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}