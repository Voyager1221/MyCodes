#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,res=0;
    cout<<"\nEnter the size of array :";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        arr[i] = num;
    }

    for(int i=0; i<n; i++){
        res = res^arr[i];
    }
    cout<<"\nres for first time: "<<res<<endl;
    vector<int> vec;
    for(int i=0; i<n; i++){
        if(res^arr[i]!=0){
            vec.push_back(arr[i]);
        }
        res = res^arr[i];
    }

    for(auto itr:vec){
        cout<<itr<<endl;
    }

    //cout<<"\nres for second time = "<<res<<endl;
}