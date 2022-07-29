#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int A,B,C;
        cin>>A>>B>>C;

        if(A==max(max(A,B),C))cout<<"Alice"<<endl;        
        else if(B==max(max(A,B),C))cout<<"Bob"<<endl;
        else cout<<"Charlie"<<endl;
    }
    return 0;
}