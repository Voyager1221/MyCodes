#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    ll A;
	    cin>>A;
	    int i;
	    int bits = floor(log2(A)) +1;
	    //cout<<"no of bit are: "<<bits<<endl;
	    for(i=0; i<bits; i++){
	        if((A) & 1) A = A>>1;
	        else break;
	    }
	    ll B = 1;
	    B = B<<i;
	    cout<<B<<endl;
	}
	return 0;
}
