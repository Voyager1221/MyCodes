#include<iostream>

using namespace std;

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K,X;
        cin>>N>>K>>X;
        int t=N;
        if(K>=X){
            while(t){
                for(int i=0; i<K||i<X; i++){
                    if(t==0)break;
                    cout<<i<<" ";
                    t--;
                }
            }
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}