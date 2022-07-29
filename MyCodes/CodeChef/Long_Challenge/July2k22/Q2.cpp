#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int A,B,C;
        cin>>A>>B>>C;
        int sum = A+B+C;
        if(sum>=100 && A>=10 && B>=10 && C>=10)cout<<"Pass"<<endl;
        else cout<<"Fail"<<endl;
    }
    return 0;
}