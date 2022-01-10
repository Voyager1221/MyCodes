#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll N, D, sum=1,flag=0;
        cin>>N>>D;
        if(D>10){
            sum = pow(2,10);
            for(ll i=0; i<D-10; i++){
                sum = sum*3;
                if(sum>=N){
                    cout<<N<<endl;
                    flag=1;
                    break;
                }
            }
        }else{
            for(ll i=0; i<D; i++){
                sum = sum*2;
                if(sum>=N){
                    cout<<N<<endl;
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){
            cout<<sum<<endl;
        }
    }   
    return 0;    
}