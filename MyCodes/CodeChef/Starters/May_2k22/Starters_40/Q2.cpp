#include<iostream>

using namespace std;
int main(){

    int T;
    cin>>T;
    while(T--){
        int X,Y,Z;
        cin>>X>>Y>>Z;
        if(X>Y)cout<< Z*(X-Y)<<endl;
        else cout<<0<<endl;
    }
    return 0;
}