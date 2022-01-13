#include <iostream>
typedef long long ll;
using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){
        ll n,k;
        cin>>n>>k;

        if(n%2 == k%2){
            if(k*k<=n)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }else cout<<"NO"<<endl;
    }
    return 0;
}