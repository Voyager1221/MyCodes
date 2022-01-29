#include <iostream>
typedef long long ll;
using namespace std;
ll calculate(ll m ,string s){
    ll add=0;
    for(int i=m; i>=0; i++){
        ll v = (int(s[i])-int('0')+add)%10;
        if(v==0)continue;
        add+ = 10-v;
    }
    return add;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        ll n,k;
        cin>>n>>k;
        string S;
        cin>>S; 
        ll l=0, r=n-1, cnt=0;
        while(l<=r){
            ll m = (l+r)/2;
            if(cal(m,S)>k){
                r = m-1;
            }
            else{
                ans = m+1;
                l = m+1;
            }
        }
        
        cout<<cnt<<endl;
    }

    return 0;   
}