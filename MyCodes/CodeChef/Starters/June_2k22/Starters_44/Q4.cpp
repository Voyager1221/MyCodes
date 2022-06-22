#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    vector<int>pre_comp;
    int M = 1000000007;
    pre_comp.push_back(1);
        for(int i=0; i<1000000; i++){
            ll res = (pre_comp[pre_comp.size()-1]*2)%M;
            // res%= M;
            pre_comp.push_back(res);
        }
    while(T--){
        ll N,X;
        cin>>N>>X;
        // vector<ll>pre_comp(N+1,0);
        // pre_comp[1] = X;
        // for(int i=2; i<=N; i++){
        //     pre_comp[i] = (2*pre_comp[i-1])%M;
        // }
        // cout<<pre_comp[N]<<endl;
        cout<<"mkc"<<endl;

    }
    return 0;
}