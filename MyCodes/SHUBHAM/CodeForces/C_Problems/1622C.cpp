#include <iostream>
#include <map>
typedef long long ll;

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll n,k,sum=0, min= INT_MAX;
        cin>>n>>k;

        map<ll,ll> m;

        for(ll i=0; i<n; i++){
            int num;
            cin>>num;
            m[num]++;
            if(num<min)min=num;
            sum += num;
        }
        ll cnt=0;
        map<ll,ll>::iterator itr;
        if(sum<k)cout<<cnt<<endl;
        else{
            for(itr=m.rbegin(); itr!=m.rend(); itr++){
                int x = (*itr).first;
                int y= (*itr).second;
                while(y!=0){
                    sum = sum -(x-min);    
                    cnt++;
                    if(sum<=k){
                        cout<<cnt<<endl;
                        itr = m.rend();
                        break;
                    }
                }
            }
        }
        // cout<<min<<endl;
    }

    return 0;
}