/*
Q1. Program No 1:
AIM: Write a program to implement quick sort.
INPUT: Use array of 10 float items.
OUTPUT: Sorted Array.

The program should contain following function

void readArray(float* x, int size)  //This function will read array 'x' of size 'size'
void printArray(float* x, int size) //This function will print array 'x' of size 'size'
//partitionArray() function will divide the array in two parts required for quick sort
int partitionArray(float* x, int lowerBound, int upperBound)
void quicksort(float *x, int lowerBound, int upperBound)    //Write recursive quick sort function
int main()

*/

#include <iostream>
using namespace std;

//Takes the array elements from user
void readArray(float* x, int size){
    cout << "Enter the values of array\n" << endl;
    for(int m=0; m<size; m++){  //Looping to take repetitive inputs from user
        cout<< "Enter the " << (m+1) << "th value : ";
        cin>> x[m];
    }
}

//Prints sorted elements of the array
void printArray(float*x, int size){
    cout<< "\nStart -> ";
    for(int m=0; m<size; m++){
        cout<< x[m] << " -> ";
    }
    cout << "End" << endl;
}

/*Finding the pivot point/element to divide the array
  Pivot is then returned to quicksort function*/
int partitionArray(float*x, int low, int high){
    float pivot_element = x[high]; //Fixing the high/right-most index as pivot 
    int m = (low-1); //

    for(int n=low; n<high; n++){ //Traversing whole array
        if(x[n]< pivot_element){
            float temp;
            m++;
            //swapping the element smaller than pivot
            temp = x[m];    
            x[m] = x[n];
            x[n] = temp;
        }

    }
    float t;
    //Bringing the pivot to sorted index
    t = x[m+1];
    x[m+1] = x[high];
    x[high] = t;

    return (m+1);     
}

/*Dividing the array into two part across pivot
  which further divides into two part across respective pivot and so on*/
void quicksort(float*x, int lowerBound, int upperBound){
    if(lowerBound < upperBound){
        int partition_element = partitionArray(x, lowerBound, upperBound);
        quicksort(x, lowerBound, partition_element-1);
        quicksort(x, partition_element+1, upperBound);
    }   
}

int main(){
    int size;
    cout<< "Enter the size of array : ";
    cin>> size;

    float x[size];
    readArray(x, size);
    quicksort(x, 0, size-1);
    printArray(x, size);
}