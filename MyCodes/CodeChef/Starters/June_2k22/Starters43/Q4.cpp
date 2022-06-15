#include<iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N>>K;
        cout<< (N+4)/5 - ((K+4)/5)<<endl;
    }
    return 0;
}