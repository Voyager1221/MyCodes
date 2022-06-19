#include <iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;

        if(N%2==0){
            for(int i=0; i<N; i++){
                if(i!=N/2-2 && i!=N/2+1)cout<<"0";
                else cout<<"1";
            }
            cout<<endl;
        }else{
            for(int i=0; i<N; i++){
                if(i!=N/2)cout<<"0";
                else cout<<"1";
            }
            cout<<endl;
        }
    }     
    return 0;
}
