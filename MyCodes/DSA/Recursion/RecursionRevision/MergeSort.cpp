#include <iostream>
#include <vector>

using namespace std;

void mergeVectors(vector<int>&vec, int low, int mid, int high){
    int left, right;
    left = low;
    right = mid+1;

    vector<int> temp;

    // Comparing the hypothetical 2 vectors
    while(left<=mid && right<=high){
        if(vec[left] > vec[right]){
            temp.push_back(vec[right++]);
        }
        else{
            temp.push_back(vec[left++]);
        }
    }
    while(left<=mid){
        temp.push_back(vec[left++]);
    } 

    while(right<=high){
        temp.push_back(vec[right++]);
    }

    for(int i=low; i<=high; i++){
        vec[i] = temp[i-low];
    }
}

void mergeSort(vector<int>&vec, int low, int high){
    // Base Condition-1
    if(low >= high){
        return;
    }
    int mid = (low+high)/2;
    mergeSort(vec, low, mid);

    mergeSort(vec, mid+1, high);

    mergeVectors(vec, low, mid, high);

}

void display(vector<int>&vec){
    for (auto itr:vec){
        cout<<itr<<" ";
    }
    cout<<endl;
}

int main(){

    int n;
    cout<<"Enter the size of array: "<<endl;
    cin>>n;

    vector<int>vec(n);

    cout<<"Enter the elements of array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>vec[i];
    }

    mergeSort(vec, 0, n-1);
    display(vec);

    return 0;
}