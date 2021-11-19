#include <iostream>

using namespace std;

bool powerOfThree(int n){
    //if(n<1) return false;
    while(n%3==0){
        n=n/3;
    }
    if(n==1) return true;
    else return false;
}

int main(){
    int n;
    cin>>n;

    bool result = powerOfThree(n);
    cout<<"The result is: "<<result<<endl;
    return 0;
}