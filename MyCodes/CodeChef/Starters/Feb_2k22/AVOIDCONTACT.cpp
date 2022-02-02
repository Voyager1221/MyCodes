#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int x,y;
        cin>>x>>y;
        if(x==y)cout<<2*x-1<<endl;
        else cout<<2*y+(x-y)<<endl;
    }
    return 0;
}