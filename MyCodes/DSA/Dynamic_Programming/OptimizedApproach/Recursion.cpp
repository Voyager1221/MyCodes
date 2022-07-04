#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int prev2 = 0;
        int prev = 1;
        for(int i=2; i<=N; i++){
            int curri = prev + prev2;
            prev2 = prev;
            prev = curri;
        }
        cout<<prev<<endl;
    }
}