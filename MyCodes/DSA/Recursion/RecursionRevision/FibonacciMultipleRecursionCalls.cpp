#include <iostream>

using namespace std;

int fibonacciUsingMultipleRecursionCalls(int n){
    if(n<=1){
        return n;
    }
    int last = fibonacciUsingMultipleRecursionCalls(n-1);
    int slast = fibonacciUsingMultipleRecursionCalls(n-2);

    return last + slast;
}

int main(){

    int n;
    cout<<"Enter the no.: "<<endl;
    cin>>n;

    cout<<"Result: "<<fibonacciUsingMultipleRecursionCalls(n);
}