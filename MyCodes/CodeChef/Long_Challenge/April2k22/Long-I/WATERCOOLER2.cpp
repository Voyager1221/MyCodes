#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int X,Y,M;
        cin>>X>>Y;
        M = Y/X;
        if(Y%X==0 && M>=1){
            cout<<M-1<<endl;
        }
        else if(M>=1){
            cout<<M<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}