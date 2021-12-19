#include <iostream>

using namespace std;

bool isLowercase(string s){
    for(int i=0; i<s.length(); i++){
        if(s[i]<97) return false;
    }
    return true;
}

string toLowercase(string s){
    string res="";
    for(int i=0; i<s.length(); i++){
        if(s[i]<97){
            res += s[i] +32;
        }else res += s[i];
    }
    return res;
}

int main(){
    string s;
    cin>>s;
    
    // if(!isLowercase(s)){
        s = toLowercase(s);
        for(int i=0; i<s.length(); i++){
            
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u'|| s[i]=='y'){
                continue;
            }
            cout<<"."<<s[i];
        }
    // }else{
    //     for(int i=0; i<s.length(); i++){
            
    //         if(s[i]=='a' || s[i]=='e' || s[i]=='o'|| s[i]=='u'|| s[i]=='y'){
    //             continue;
    //         }
    //         cout<<"."<<s[i];
    //     }
    // }

}