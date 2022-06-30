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
            vector<ll>cnt;
            for(auto itr:vec){
                if(itr%2==0){
                    ll ops = 0;
                    while(itr>0){
                        itr/=2;
                        ops++;
                        if(itr%2==1)cnt.push_back(ops);
                    }
                }
            }
            ll diff = (cnt_even-cnt_odd)/2;
            sort(cnt.begin(), cnt.end());
            for(int i=0; i<diff; i++){
                ans+=cnt[i];
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}