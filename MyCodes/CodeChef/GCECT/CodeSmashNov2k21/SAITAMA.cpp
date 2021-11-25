#include <iostream>
#include <math.h>
typedef long long ll;

using namespace std;

//THIS METHOD GIVES T.L.E.

// int fOy(int n){
//     int GCF, cnt=1;
//     if(n==1)return 0;

//     for(int i=2; i*i<=n; i++){
//         for(int j=2; j<=i; j++){
//             if(i%j==0 && n%j==0){ 
//                 GCF = j;
//                 break;  
//             }

//         }
//         if(GCF==1)cnt++;
//         GCF = 1;
//     }
//     return cnt;
// }

ll Eulers_Totient_Function(ll n){
    ll result = 1;

    for(ll i=2; i*i<=n; i++){
        ll c = 0;
        if(n%i==0){
            while(n%i==0){
                n /= i;
                c++;
            }
        }
        if(c>0){
            //ll power = (ll)pow(i, c-1);
            ll sm = (ll)pow(i, c-1) * (i-1);
            result *= sm;
            cout<<"\nResult "<<i<< " : "<<result<<endl;
        }
    }

    if(n>1){
        result *= (n-1);
        cout<<"In if Condition. The value of n is: "<<n<<endl;
        cout<<"\nResult in If condition is : "<<result<<endl;
    }
    return result;
}

int main(){
    
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        n = n*(n-1);
        if(n<=1)cout<<"0"<<endl;
        else cout<<Eulers_Totient_Function(n)<<endl;
        cout<<endl;
    }
    return 0;
}