#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int A,B;
        cin>>A>>B;
        cout<<min(7-A, 7-B)<<endl;    
    }
    return 0;
}