#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int diff = N-1;
        int Qo3 = diff/3;
        int rem = Qo3%3;
        if(Qo3==0){
            if(diff>=1)cout<<1<<endl;
            else cout<<0<<endl;
        }else{
            if(rem==0){
                if(Qo3<=3){
                    cout<<Qo3/3 -1 +2<<endl;
                }
                else{
                    if(Qo3%3==0)cout<<Qo3/3 -1 +2*(Qo3 - Qo3/3 + 1)<<endl;
                    else cout<<Qo3/3+ (Qo3-Qo3/3)<<endl;
                }
            }else{
                if(Qo3<=3){
                    cout<<Qo3/3 -1 +2+1<<endl;
                }else{
                     if(Qo3%3==0)cout<<Qo3/3 -1 +2*(Qo3 - Qo3/3 + 1)+1<<endl;
                     else cout<<Qo3/3+ (Qo3-Qo3/3)+1<<endl; 
                }
            }
        }
    }
    return 0;
}