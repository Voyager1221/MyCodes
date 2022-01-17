#include <iostream>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll n, k, sum=0, min=INT_MAX, max=INT_MIN;
        cin>>n>>k;
        
        map<ll,ll> m;

        for(ll i=0; i<n; i++){
            ll num;
            cin>>num;
            m[num]++;
            if(num<min)min=num;
            if(num>max)max=num;
            sum += num;
        }
        ll cnt=0;
        bool flag = true;
        if(sum<=k)cout<<cnt<<endl;
        else{
            while(flag){
                if(min==max){
                    cnt += n*min-k;
                    cout<<cnt<<endl;
                    flag=false;
                    break;    
                }else{
                    // map<ll, ll>::reverse_iterator itr;
                    for(auto itr = m.rbegin(); itr != m.rend(); itr++){
                        ll x = itr->first;
                        ll y = itr->second;
                        while(y>0){
                            sum = sum - (x - min);
                            cnt++;
                            if(sum<=k){
                                cout<<cnt<<endl;
                                itr = m.rend();
                                flag=false;
                                break;
                            }
                            y--;
                        }    
                    }
                    max = min;
                }
            }
        }
    }
}