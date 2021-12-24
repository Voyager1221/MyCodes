#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){

        int a,b,n,S;
        cin>>a>>b>>n>>S;

        int rem_n,quotient_n;
        quotient_n = S/n;
        rem_n = S%n;

        if(quotient_n>a){
            int sum = S - a*n;
            if(sum<=b)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        if(quotient_n<=a){
            int sum = S - quotient_n*n;
            if(sum<=b)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}