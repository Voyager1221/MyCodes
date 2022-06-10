#include<iostream>
#include <math.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int X,Y;
        cin>>X>>Y;
        
        int ops;
        if(X>=Y){
            int diff = X-Y;
            if(diff%2==0) ops = diff/2;
            else{
                ops = diff/2 + 2;
            }
        }else{
            ops = Y-X;
        }
        cout<<ops<<endl;
    }
    return 0;
}