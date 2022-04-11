#include <iostream>

typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll X;
        cin>>X;
        ll A = (X & ~(X-1));
        if(X&1 || X==A)cout<<-1<<endl;
        else cout<<A/2<<" "<<X/2<<" "<<(X-A)/2<<endl;
    }
    return 0;
}