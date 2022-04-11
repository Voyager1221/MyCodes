#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int X,Y;
        cin>>X>>Y;
        if(Y>X)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}