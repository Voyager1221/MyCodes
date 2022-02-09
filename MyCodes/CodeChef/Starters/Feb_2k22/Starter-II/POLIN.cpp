#include <iostream>
#include <set>

using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;

        set<int>x;
        set<int>y;

        for(int i=0; i<n; i++){
            int a,b;
            cin>>a>>b;
            x.insert(a);
            y.insert(b);
        }
        
        cout<<x.size()+y.size()<<endl;
    }
    return 0;
}