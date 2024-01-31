#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>&vec, int i, int j){
    int temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

void quickSort(vector<int>&vec, int pivot, int low, int high){
    // Base Condition
    if(low>=high){
        return;
    }

    int last = low;
    
    for(int i=low+1; i<=high; i++){
        if(vec[last] < vec[i]){
            swap(vec, i, last);
            last = i;
        }else{
            if(last==pivot){
                last = i;
            }
            swap(vec, i, pivot++);
        }
    }
    swap(vec, last, pivot);
    
    quickSort(vec, low, low, pivot-1);
    quickSort(vec, pivot+1, pivot+1, high);
}

void display(vector<int>&vec){
    for(auto itr: vec){
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

    quickSort(vec, 0, 0, n-1);
    display(vec);
    return 0;
}