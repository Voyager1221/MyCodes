#include <iostream>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    int M = 1000000007;
    vector<ll>pre_comp(1000009,0);
    pre_comp[1] = 1;
    for(int i=2; i<=N; i++){
        pre_comp[i] = (2*pre_comp[i-1])%M;
    }

    while(T--){
        ll N,X;
        cin>>N>>X;
        cout<<pre_comp[i]*X<<endl;
    }
    return 0;
}