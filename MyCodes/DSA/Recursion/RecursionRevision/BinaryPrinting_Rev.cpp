#include <iostream>

using namespace std;

string binaryPrinting(int num){
    if(num == 0 || num == 1){
        return to_string(num);
    }
    
    return binaryPrinting(num/2) + to_string(num%2);    
}

// bp(10) = bp(5)+ to_string(10%2) --> bp(5) = bp(2)+to_string(5%2) --> bp(2) = bp(1)+to_string(2%2) --> bp(1) --> returns "1"

int main(){

    int num;
    cout<<"Enter the number to print in binary format:"<<endl;
    cin>>num;

    string res = binaryPrinting(num);
    cout<<"The binary equivalent is: "<<res<<endl;
    return 0;
}