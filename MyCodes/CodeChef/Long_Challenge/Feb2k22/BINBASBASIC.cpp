#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n, k, cnt=0;
        cin>>n>>k;
        string s;
        cin>>s;
        // bool isPalin = true;
        // for(int i=0; i<n; i++){
        //     if(s[i]!=s[n-1-i]){
        //         cnt++;
        //         isPalin = false;
        //     }
        // }
        // if((isPalin) || ((cnt/2)==k))cout<<"Yes"<<endl;
        // else cout<<"No"<<endl;

        for(int i=0; i<n/2; i++){
            if(s[i]!=s[n-1-i])cnt++;
        }
        if(cnt<=k){
            if(n%2==1)cout<<"Yes"<<endl;
            else if((k-cnt)%2==0)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }else cout<<"No"<<endl;
    }
    return 0;
}