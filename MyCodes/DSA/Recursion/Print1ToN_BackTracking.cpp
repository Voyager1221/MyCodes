#include <iostream>

using namespace std;

void Print_1ToN_BackTracking(int num){
    if (num==0) return;
    Print_1ToN_BackTracking(num-1);
    cout<<num<<endl;
}

int main(){
    int n;
    cin>>n;
    Print_1ToN_BackTracking(n);
    return 0;
}