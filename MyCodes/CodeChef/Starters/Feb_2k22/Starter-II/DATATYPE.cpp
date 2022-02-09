#include <iostream>

using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){
        int N,X;
        cin>>N>>X;

        cout<<X%(N+1)<<endl;
    }
}