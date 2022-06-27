#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int P;
        cin>>P;
        int ans = P/100;    
        if((P%100) <= (10-(P/100))){
            cout<< ans+(10-(P/100))<<endl;
        }else cout<<-1<<endl;
    }
    return 0;
}