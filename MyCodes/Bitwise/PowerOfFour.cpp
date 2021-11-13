#include <iostream>

using namespace std;

bool powerOfFour(int n){
    if(n<1) return false;
    while(n%4==0){
        n = n/4;
    }
    if(n==1) return true;
    else return false;
}

int main(){

    int n;
    cin>>n;

    bool result = powerOfFour(n);
    cout<<"The result is : "<<result<<endl;
    return 0;
}