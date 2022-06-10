#include<iostream>
#include <map>

typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll N;
        cin>>N;

        ll A[N],B[N];
        map<ll,ll>m;
        for(ll i=0; i<N; i++){
            cin>>A[i];
        }
        for(ll i=0; i<N; i++){
            cin>>B[i];
        }
        for(ll i=0; i<N; i++){
            m[A[i]^B[i]]++;
        }
        ll ans=0;
        for(auto itr:m){
            if(itr.second>1){
                ans += (itr.second*(itr.second-1))/2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}