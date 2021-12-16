#include <iostream>

using namespace std;

void solve(){

    int N;
    cin>>N;
    // if(N%2020==0 || N%2020==1 || N%2021==0 || N%2021==2020){
    //     cout<<"YES"<<endl;
    // }else cout<<"NO"<<endl;
    int rem = N%2020;
    if(rem<= N/2020){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}

int main(){

    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}