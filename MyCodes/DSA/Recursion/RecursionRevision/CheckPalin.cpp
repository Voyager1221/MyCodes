#include <iostream>

using namespace std;

bool checkPalin(string s, int index, int len){
    if(index>=(len/2)){
        return true;
    }
    if(s[index] == s[len-1-index]){
        return checkPalin(s, index+1, len);
    }
    return false;
}


int main(){

    string str;
    cout<<"Enter the string: "<<endl;
    cin>>str;

    cout<<"Is the string Palindrome: "<<checkPalin(str, 0, str.length())<<endl;

    return 0;
}