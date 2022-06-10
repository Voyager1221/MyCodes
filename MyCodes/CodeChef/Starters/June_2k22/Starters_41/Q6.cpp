#include <iostream>
using namespace std;

typedef long long ll;

int main() {
	int T;
	cin>>T;
	while(T--){
	    ll N, K;
	    cin>>N>>K;
        if(K==1){
            if(N%2==0)cout<<"Even"<<endl;
            else cout<<"Odd"<<endl;
        }else if(K==2)cout<<"Odd"<<endl;
        else cout<<"Even"<<endl;
	}
	return 0;
}
