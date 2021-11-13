#include <iostream>
using namespace std;

void readArray(float*, int);
void printArray(float*, int);
int partitionArray(float*, int , int);
void quickSort(float*, int, int);

void readArray(float* arr, int size){
    cout<< "\nEnter the values in array."<<endl;
    for(int i =0; i<size; i++){
        cout<<"\nEnter the "<<i+1<<"th value : ";
        cin>>arr[i];
    }
}

void printArray(float* arr, int size){
    cout<< "\nSorted array is..."<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

int partitionArray(float* arr, int low , int high){
    //float pivot_element = arr[int(low+high)/2];

    float tv = arr[int(low+high)/2];
    arr[int(low+high)/2] = arr[high];
    arr[high] = tv;

    float pivot_element = arr[high];
    cout<<"\npivot_element: "<<arr[high]<<endl;
    int x = low-1;
    for(int y=0; y<high; y++){
        if(arr[y]<pivot_element){
            x++;
        
            float temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
        }
    }
    float t = arr[x+1]; 
    arr[x+1] = arr[high];
    arr[high] = t;
    cout<<"\nthe partition index is : "<<x+1<<endl;
    return x+1;
}
/*

12  453  67  34  681  87  23


*/
void quickSort(float* arr, int low , int high){
    if(low<high){
        int partition = partitionArray(arr, low, high);
        quickSort(arr, low, partition-1);
        quickSort(arr, partition+1, high);
    }
}

int main(){
    int size;
    cout<<"\nEnter the size of array : ";
    cin>>size;

    float arr[size];
    readArray(arr, size);
    quickSort(arr, 0, size-1);
    printArray(arr, size);
}