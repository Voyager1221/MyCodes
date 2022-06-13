#include<iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int A,B;
        cin>>A>>B;

        int diff = B-A;
        if(diff%3==0 || diff%3==1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }
    return 0;
}