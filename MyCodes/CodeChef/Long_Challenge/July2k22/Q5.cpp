#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int X1, Y1, X2, Y2;
        cin>>X1>>Y1>>X2>>Y2;

        if((abs(X2-X1)+abs(Y2-Y1))%2==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;    
    }
    return 0;
}