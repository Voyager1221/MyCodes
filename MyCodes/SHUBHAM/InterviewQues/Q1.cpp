#include <iostream>

using namespace std;
int main(){
    // int cin;
    // cin>>cin;
    // cout<<"cin "<<cin;
    int x = 1;
    for(int i=1; i<=128; i+=i){
        x += x;
    }
    cout<<x<<endl;
    return 0;
}