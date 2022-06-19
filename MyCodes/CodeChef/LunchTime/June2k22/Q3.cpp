#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int X,Y;
        cin>>X>>Y;
        cout<<abs((Y+9)/10 - (X+9)/10)<<endl;        
    }
    return 0;
}