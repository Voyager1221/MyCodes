#include <iostream>
typedef long long ll;
using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){
        ll X;
        cin>>X;
        ll a=X, b = 0, c=X;
        for(int i=0; i<31; i++){
            if(!(c&(ll)1<<i)){
                c = c|((ll)1<<i);
                break;
            }
        }
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}