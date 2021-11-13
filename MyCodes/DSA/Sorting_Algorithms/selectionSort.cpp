#include <iostream>
using namespace std;

int* selectionSort(int arr[], int n){
    int min;
    for(int i=0; i<n; i++){
        int temp = -1;
        min = arr[i];
        for(int j=i+1; j<n; j++){
            if(min > arr[j]){
                min = arr[j];
                temp = j;
            }
        }
        if(temp>=0){
            arr[temp] = arr[i];
            arr[i] = min;
        }
    }
    return arr;
}

void takeInput(int arr[], int n){
    cout<<"\nEnter the values of array.\n"<<endl;
    for(int i=0; i<n; i++){
        cout<<"Enter the value of "<< i+1<<"th element: ";
        cin>>arr[i];
    }
}

void display(int arr[], int n){
    cout<<"\nThe elements of the sorted array are: "<< endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>> n;
    int arr[n];
    
    takeInput(arr, n);
    selectionSort(arr, n);
    display(arr, n);
}