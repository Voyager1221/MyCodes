#include <iostream>

using namespace std;

int combination(int n, int r){
    int ans = 1;
    for(int i=1; i<=r; i++){
        ans *= (n-r+i);
        ans /= i;
    }
    return ans;
}

void solve(){
    int N,K;
    cin>>K>>N;
    cout<<combination(N+K-1, K-1)<<endl;
}

int main(){

    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}