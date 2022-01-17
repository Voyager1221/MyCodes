#include <iostream>
#include <cmath>
typedef long long ll;

using namespace std;

int main(){
    ll n,sum=0;
    cin>>n;
    for(ll i=1; i<=n; i++){
        sum += pow(2,i);
    }
    cout<<sum<<endl;
    return 0;
}