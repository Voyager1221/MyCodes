#include <iostream>
typedef long long ll;
using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){

        ll n;
        cin>>n;
        if(n&1){
            cout<<"YES"<<endl;
        }else{
            int flag=1,rem=0;
            while(n>1){
                rem = n%2;
                if(rem==1 && n!=1){
                    cout<<"YES"<<endl;
                    flag=0;
                    break;
                }
                n = n/2;
            }
            if(flag==1)cout<<"NO"<<endl;
            // if(rem==1)cout<<"YES"<<endl;
            // else cout<<"NO"<<endl;
        }
    }
}