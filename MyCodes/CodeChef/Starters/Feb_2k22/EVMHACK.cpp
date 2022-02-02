#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int a,b,c,p,q,r;
        cin>>a>>b>>c>>p>>q>>r;
        int sum, tv;
        sum=a+b+c+max(p-a, max(q-b, r-c));
        tv = p+q+r;
        if(sum>tv/2)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}