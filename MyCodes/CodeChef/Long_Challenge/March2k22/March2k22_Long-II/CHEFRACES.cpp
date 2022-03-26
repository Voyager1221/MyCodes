#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int X, Y, A, B, cnt=2;
        cin>>X>>Y>>A>>B;
        if(X==A || X==B)cnt--;
        if(Y==A || Y==B)cnt--;
        cout<<cnt<<endl;
    }
    return 0;
}