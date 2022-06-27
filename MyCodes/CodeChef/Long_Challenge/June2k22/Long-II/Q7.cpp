#include <iostream>
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll N,M;
        cin>>N>>M;
        if(N>=M){
            ll cd = M+1;
            for(ll i=1; i<=N; i++){
                for(ll j=1; j<=M; j++){
                    cout<<i+(j-1)*cd<<" ";
                }
                cout<<endl;
                cd++;
            }
        }
        else{
            for(ll i=1; i<=N; i++){
                ll k=1+(i-1)*(N+1);
                for(ll j = 0; j<M; j++){
                    cout<<k<<" ";
                    k+=i;
                }
                cout<<endl;
            }
        }
    }
    return 0;
}



