#include<iostream>

using namespace std;
int main(){

    int T;
    cin>>T;
    while(T--){
        int N,X,Y;
        cin>>N>>X>>Y;
        int sum1 =0, sum2=0;
        for(int i=0; i<N; i++){
            int num;
            cin>>num;
            sum1 += num;
            if(num<=Y)continue;
            else sum2+= (num-Y);
        }
        sum2 += X;
        if(sum2<sum1)cout<<"COUPON"<<endl;
        else cout<<"NO COUPON"<<endl;
    }
    return 0;
}