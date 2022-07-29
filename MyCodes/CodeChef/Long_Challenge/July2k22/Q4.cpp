#include <iostream>
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll maxT, maxN, maxS;
        cin>>maxT>>maxN>>maxS;
        ll Q = maxS/maxN;
        ll rem = maxS%maxN; 
        if(maxT*maxN<=maxS)cout<<maxT*maxN*maxN<<endl;
        else cout<< Q*maxN*maxN + rem*rem<<endl;

    }
    return 0;
}