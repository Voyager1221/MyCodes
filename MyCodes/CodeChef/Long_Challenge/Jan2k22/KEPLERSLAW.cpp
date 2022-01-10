#include <iostream>

using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){
        int T1,T2,R1,R2;
        cin>>T1>>T2>>R1>>R2;
        double k1 = (T1*T1)/(double)(R1*R1*R1);
        double k2 = (T2*T2)/(double)(R2*R2*R2);
        if(k1==k2)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}