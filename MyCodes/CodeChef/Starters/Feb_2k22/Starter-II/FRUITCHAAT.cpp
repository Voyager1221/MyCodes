#include <iostream>

using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){
        int X,Y;
        cin>>X>>Y;
        cout<< min(X/2, Y)<<endl;
    }
    return 0;
}