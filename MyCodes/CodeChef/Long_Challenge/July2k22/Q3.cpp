#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N, X;
        cin>>N>>X;
        if(N-X>0)cout<<((N-X)+3)/4<<endl;    
        else cout<<0<<endl;

    }
    return 0;
}