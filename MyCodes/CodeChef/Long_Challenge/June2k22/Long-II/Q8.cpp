#include <iostream>
#include <cmath>
#include <vector>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll N;
        cin>>N;
        map<pair<ll,ll>,ll>m;
        vector<ll>d_val;

        d_val.push_back(1);
        for(ll i=2; i*i<=N; i++){
            if(N%i*i==0)d_val.push_back(i);
        }

        
        ll ans=0;
        for(auto itr:d_val){
            long double num = (N-2*pow(itr,2))/2;
            ll res = sqrt(num);
            // cout<<"Res: "<<res<<endl;
            if(m[{itr, res}]==-1)continue;
            if(res*res==num){
                if(itr!=res){
                    m[{itr,res}]=2;
                    m[{res,itr}] = -1;
                    ans+=2;
                }
                else ans++;
            }
        }
        cout<<"\nPrinting Map: "<<endl;
        for(auto itr:m){
            cout<<itr.first.first<<" "<<itr.first.second<<" "<<itr.second<<endl;
        }
        cout<<endl;
        // for(auto i:m){
        //     for(auto j:m){
        //         if(i.first.first==j.first.second && i.first.second==j.first.first)ans-=2;
        //     }
        // }
        cout<<"\nAnswer: "<<ans<<endl;
    }
    return 0;
}