//Quick Sort using low end as pivot
#include <iostream>
using namespace std;

void readArray(float*, int);
void printArray(float*, int);
int partitionArray(float*,int , int);
void quickSort(float*, int , int);


void readArray(float* arr, int size){
    cout<< "Enter the values of array"<<endl;
    for(int i=0; i<size; i++){
        cout<< "\nEnter the "<< i+1<< "th value : ";
        cin>>arr[i];         
    }
}

void printArray(float* arr, int size){
    cout<< "The sorted array is...\n" <<endl;
    for(int i=0; i<size; i++){
        cout<< arr[i]<< " ";
    }
}

int partitionArray(float* arr, int low, int high){
    int pivot_element = arr[low];
    int x = high+1;

    for(int y=high; y>low; y--){
        if(arr[y] > pivot_element){
            x--;
            float temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
        }
    }
    float t = arr[x-1];
    arr[x-1] = arr[low];
    arr[low] = t; 

    return x-1;
}

void quickSort(float* arr, int low, int high){
    if(low < high){
        int pivot = partitionArray(arr, low, high);

        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
}

int main(){
    int size;
    cout<< "Enter the size of array: ";
    cin>> size;

    float arr[size];
    readArray(arr,size);
    quickSort(arr, 0, size-1);
    printArray(arr, size);
}
