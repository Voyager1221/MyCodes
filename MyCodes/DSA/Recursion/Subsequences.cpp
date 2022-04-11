#include<iostream>

using namespace std;

void printF(int index, vector<int>&ds, int arr[], int n){
    if(index==n){
        for(auto it : ds){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<int>ds;
    printF(0, ds, arr, n) 
    return 0;
}