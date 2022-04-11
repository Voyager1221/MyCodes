#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll A,B;
        cin>>A>>B;
        if(A==1 || B==1)cout<<-1<<endl;
        else if(__gcd(A,B)==1)cout<<1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}