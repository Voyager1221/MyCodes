#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
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
        ll ans=0;

        d_val.push_back(1);
        
        for(ll i=2; i*i<=N; i++){
            if(N%i*i==0)d_val.push_back(i);
        }
        for(ll i=1; i*i<=N; i++){
            long double num1 = (N-2*pow(i,2))/2;
            ll res1 = sqrt(num1);
            if(num1>0 && __gcd(res1, i)>1){
                if(m[{i,res1}]==-1)continue;
                if(res1*res1==num1){
                    if(i!=res1){
                    cout<<"i"<<i<<" res1: "<<res1<<endl;
                        m[{i, res1}] = 2;
                        m[{res1, i}] = -1;
                        ans+=2;
                    }else {
                        cout<<"i"<<i<<" res1: "<<res1<<endl;
                        ans++;
                    }
                }
            }
        }
        for(ll i=2; i<=sqrt(N); i++){
            long double num2 = (N-pow(i,2)-1)/(1+pow(i,2));
            ll res2 = sqrt(num2);
            if(num2>0 && res2!=i){
                if(m[{i,res2}]==-1)continue;
                if(num2>0 && res2*res2==num2){
                    if(res2!=num2){
                        cout<<"i"<<i<<" res2: "<<res2<<endl;
                        m[{i,res2}] = 2;
                        m[{res2, i}] = -1;
                        ans+=2;
                    }else{ 
                        cout<<"i"<<i<<" res2: "<<res2<<endl;
                        ans++;
                    }
                }
            }
        }
        cout<<"\nPrinting map: "<<endl;
        for(auto itr:m){
            cout<<itr.first.first<<" "<<itr.first.second<<" "<<itr.second<<endl;
        }
        cout<<"\nAnswer: "<<ans<<endl;
        // cout<<ans<<endl;
    }
    return 0;
}