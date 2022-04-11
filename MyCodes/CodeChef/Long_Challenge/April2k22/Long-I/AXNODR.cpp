#include <iostream>

typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll N,B=1;
        cin>>N;
        if(N%4==2 || N%4==3)cout<<3<<endl;
        else if(N%4==0)cout<<N+3<<endl;
        else cout<<N<<endl;
    }
    return 0;
}