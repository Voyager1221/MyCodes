#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
typedef long long ll;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<ll> vec;
        ll d_odd, d_even;
        for(int i=0; i<n; i++){
            ll num;
            cin>>num;
            vec.push_back(num);
        }
        d_even = vec[0];
        d_odd = vec[1];
        int j=1;
        for(int i=0; i<n; i+=2){
            d_even = __gcd(d_even, vec[i]);
            if(j<n){
                d_odd = __gcd(d_odd, vec[j]);
                j+=2;
            }
        }
        if(d_even!=d_odd){
            bool flag_even=true, flag_odd=true;
            for(int i=0; i<n; i+=2){
                if(i+1<n){
                    if(vec[i+1]%d_even==0)flag_even=false;
                }
                if(vec[i]%d_odd==0)flag_odd=false;
            }
            if(flag_odd==true)cout<<d_odd<<endl;
            else if(flag_even==true)cout<<d_even<<endl;
            else cout<<0<<endl;
        }else cout<<0<<endl;
    }
    return 0;
}