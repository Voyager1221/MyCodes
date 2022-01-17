#include <iostream>
#include <map>

typedef long long ll;

using namespace std;

int main(){
    ll n;
    cin>>n;

    map<ll, ll> m;

    for(int i=0; i<n ; i++){
        int num;
        cin>>num;
        m[num]++;
    }
    m.insert({1,2});
    m.insert(make_pair(2,3));
    m.insert({3,4});
    map<int, int>::iterator it;

    for(it = m.begin(); it!=m.end(); it++){
        cout<<"First: "<<it->first<<" Second: "<<it->second<<endl;
    }

    // map<int, int>::reverse_iterator itr;
    // for(itr=m.rbegin(); itr!=m.rend(); itr++){
    //     cout<<"First: "<<itr->first<<" Second: "<<itr->second<<endl;
    // }

    return 0;
}