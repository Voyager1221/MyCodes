#include <iostream>

using namespace std;

int main(){
    string s;
    cin>>s;
    int cnt0=0,cnt1=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='1'){
            cnt1++;
            cnt0=0;
        }
        else{
            cnt0++;
            cnt1=0;
        }

        if(cnt0==7 || cnt1==7 ){
            cout<<"YES"<<endl;
            cnt0=-1;
            break;
        }
    }
    if(cnt0!=-1)cout<<"NO"<<endl;
}