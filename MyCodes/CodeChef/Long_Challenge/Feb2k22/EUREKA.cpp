#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;

        double res =  pow(0.143*n, n);
        cout<<round(res)<<endl;
    }
    return 0;
}