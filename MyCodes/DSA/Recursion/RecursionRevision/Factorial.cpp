#include <iostream>

using namespace std;

int fact(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n*fact(n-1);
}

int main(){

    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;

    cout<<"The factorial of "<< n << " is : "<<fact(n)<<endl;
    return 0;
}