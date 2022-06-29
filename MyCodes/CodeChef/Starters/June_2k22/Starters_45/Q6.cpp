#include<iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll N;
        cin>>N;
        ll cnt_odd=0, cnt_even=0;
        // map<ll, ll>m;
        vector<ll>vec(2*N,-1);
        for(int i=0; i<2*N; i++){
            cin>>vec[i];
            if(vec[i]%2==0)cnt_even++;
            else cnt_odd++;
        }
        if(cnt_even==cnt_odd)cout<<0<<endl;
        else if(cnt_odd>cnt_even){
            cout<< (cnt_odd-cnt_even)/2<<endl;
        }else{
            ll ans=0;
            sort(vec.begin(), vec.end());
            ll diff= (cnt_even-cnt_odd)/2;
            for(auto itr:vec){
                if(itr%2==0 && diff>0){
                    ll ops=0;
                    while(itr>0){
                        itr/=2;
                        ops++;
                        if(itr%2==1){
                            ans+=ops;
                            diff--;
                            break;
                        }
                    }
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}