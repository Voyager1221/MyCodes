#include <iostream>
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll N;
        cin>>N;
        ll totalSum = 0;
        ll B[N];
        for(ll i=0; i<N; i++){
            cin>>B[i];
            totalSum+=B[i];
        }
        totalSum = totalSum/(N+1);
        for(ll i=0; i<N; i++){
            cout<<B[i]-totalSum<<" ";
        }
        cout<<endl;
    }
    return 0;
}