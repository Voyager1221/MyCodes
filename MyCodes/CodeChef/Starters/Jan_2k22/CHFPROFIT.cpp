#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;

    while(T--){
        int X,Y,Z;
        cin>>X>>Y>>Z;

        cout<<X*(Z-Y)<<endl;
    }
    return 0;
}