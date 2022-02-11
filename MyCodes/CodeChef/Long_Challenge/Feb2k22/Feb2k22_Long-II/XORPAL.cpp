#include <iostream>

using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt0=0, cnt1=0;
        
        for(int i=0; i<n; i++){
            if(s[i]=='0')cnt0++;
            else cnt1++;
        }
        if(n%2==0){
            if(cnt0%2==0 || cnt0==n/2)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}