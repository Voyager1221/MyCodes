#include <iostream>

using namespace std;



/*

typedef long long int ll;

void timeCalc(ll N){
    int flag = 1;
    
    if(N%6==0 && flag==1 ) {cout<<N/6*15<<endl; flag=0;}
    if(N%8==0 && flag==1) {cout<<N/8*20<<endl; flag=0;}
    if(N%10==0 && flag==1){cout<<N/10*25<<endl; flag=0;}
    // if(N%){
    //     cout<<(N/5+1)*15<<endl;
    // }else if(rem==7){
        
    // }
    if(flag==1 && N>10){
        ll t6, t8 ,t10;
    
        t6 = (N/6 + 1)*15;
        t8 = (N/8 + 1)*20;
        t10 = (N/10 + 1)*25;
        
        if(N%10==6) {cout<<N/10*25+15<<endl; flag=0;}
        else if(N%10==8) {cout<<N/10*25+20<<endl; flag=0;}
        else cout<<min(t6, min(t8, t10))<<endl;
        
    }else{
        if(N<6)cout<<"15"<<endl;
        else if(N==7) cout<<"20"<<endl;
        else cout<<"25"<<endl;
    }
}

void solve(){
    ll N;
    cin>>N;
    timeCalc(N);
}

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    solve();
	}
	return 0;
}

*/

typedef long long ll;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        (n<=6)?cout<<"15"<<endl:cout<<(n+1)/2*5<<endl;
        cout<<endl;
    }
    return 0;
}