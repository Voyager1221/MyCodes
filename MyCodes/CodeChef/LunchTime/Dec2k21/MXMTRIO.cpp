#include <iostream>
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

        vector<ll> vec;
        for(ll i=0; i<N; i++){
            ll num;
            cin>>num;
            vec.push_back(num);
        }

        sort(vec.begin(), vec.end(), greater<int>());

        cout<<max((vec[1]-vec[N-1])*vec[0], (vec[0]-vec[N-1])*vec[1])<<endl;
    }


    return 0;
}