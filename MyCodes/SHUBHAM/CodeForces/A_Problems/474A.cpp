#include <iostream>

using namespace std;

int main(){
    char ch;
    cin>>ch;
    string kb="qwertyuiopasdfghjkl;zxcvbnm,./";
    string s;
    cin>>s;
    string decoded="";
    if(ch=='R'){
        for(int i=0; i<s.length(); i++){
            decoded += kb[kb.find(s[i])-1];
        }
    }else{
       for(int i=0; i<s.length(); i++){
            decoded += kb[kb.find(s[i])+1];
        } 
    }
    cout<<decoded<<endl;

}