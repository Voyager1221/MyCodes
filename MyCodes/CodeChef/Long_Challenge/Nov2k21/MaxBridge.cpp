#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;

        m -= n-1;
        for(int i=1; i<n; i++){
            cout<<i<<" "<<i+1<<endl;
        }

        int i=3;
        while(m>0){
            for(int j=1; j<i-1; j++){
                if(m==0) break;
                cout<<j<<" "<<i<<endl;
                m--;
            }
            i++;
        }
    }
    return 0;
}