#include <iostream>
#include <algorithm>
using namespace std;

// int gcd(int a, int b){
//     int GCD=1,m = min(a,b);
//     for(int i=0; i<m; i++){
//         if(a%m==0 && b%m==0){
//             GCD = m;
//         }
//     }
//     return GCD;
// }

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

void solve(){
    int N,K;
    cin>>N>>K;
    cout<<N/gcd(N,K)<<endl;
}

int main(){
    // int T;
    // cin>>T;
    // while(T--){
    //     solve();
    // }
    long long N =  45999333;
    cout<<N*1000000<<endl;
    return 0;
}