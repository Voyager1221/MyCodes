#include <iostream>

typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;

    while(T--){
        ll score, limit;
        cin>>score>>limit;

        cout<<(limit-score/2)*2*(score-1)<<endl;
        
    }
    return 0;
}