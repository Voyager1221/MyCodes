#include <iostream>

typedef long long ll;

using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){
        ll x,n=1;
        bool flag=false;
        cin>>x;
        // while(n*n*n <x){
        //     for(ll y=1; y<=n; y++){
        //         ll sum = n*n*n + y*y*y; 
        //         if(sum==x){
        //             cout<<"YES"<<endl;
        //             n = 10000;
        //             flag = true;
        //             break;
        //         }
        //         if(sum>x){
        //             // y = n+1;
        //             break;
        //         }
        //     }
        //     n++;
        // }

        if(flag==false){
            cout<<"NO"<<endl;
        }
    }
    return 0;
}