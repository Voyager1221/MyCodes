#include <iostream>

typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll X,M;
        cin>>X>>M;
        ll sum=0, cnt=0;
        while(sum<X){
            if(sum==0)sum =1;
            else sum = 2*sum;
            cnt++;
        }
        if(cnt<=M)cout<<(M-cnt) +1<<endl;
        else cout<<0<<endl;
    }
    return 0;
}