#include<iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int X,Y,Z;
        cin>>X>>Y>>Z;

        cout<<((5*X)+(10*Y))/Z<<endl;    
    }
    return 0;
}