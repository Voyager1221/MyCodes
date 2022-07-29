#include <iostream>
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll N;
        cin>>N;
        // bool flag = true;
        ll cnt_1=0;
        ll n_chances=0;
        for(ll i=0; i<N; i++){
            ll num;
            cin>>num;
            if(num<2)cnt_1++; 
            n_chances += num;
        }
        if(cnt_1!=0){
            n_chances = n_chances - N;
            if(n_chances%2==0)cout<<"Chefina"<<endl;
            else cout<<"Chef"<<endl;
        }  
        else{ 
            n_chances = n_chances - 2*N;
            if(n_chances%2==0)cout<<"Chefina"<<endl;
            else cout<<"Chef"<<endl;
        }
    }
    return 0;
}