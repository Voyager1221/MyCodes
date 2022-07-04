#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll N,A,B;
        cin>>N>>A>>B;
        ll num = 1;
        ll X = 0;
        for(ll i=0; i<N; i++){
            if(!(A&num==0) && !(B&num==0)){
                X += pow(2, i);
            }
            num <<= 1;
        }
        cout<<X<<endl;        
    }
    return 0;
}