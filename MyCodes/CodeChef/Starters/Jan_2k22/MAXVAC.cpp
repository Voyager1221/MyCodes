#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,X;
        cin>>N>>X;
        string S;
        cin>>S;
        int cnt_1=0,cnt_0=0,max_vac=0;
        bool flag = true;
        for(int i=0; i<N; i++){
            // cout<<"\ni: "<<i<<endl;
            if(i+X-1<N){
                for(int j=0; j<X; j++){
                    if(S[i+j]=='0')cnt_0++;
                    else cnt_1++;
                }
                
                if(cnt_1==1 && flag==true){
                    max_vac++;
                    flag = false;
                    i=i+X-1;
                    // cout<<"\ni: "<<i<<endl;
                }
                if(cnt_0==X){
                    max_vac++;
                    i=i+X-1;    
                    // cout<<"\ni: "<<i<<endl;
                }
                // cout<<"\ni:"<<i<<"--> "<<cnt_0<<cnt_1<<endl;
                cnt_0=0;
                cnt_1=0;
            }
        }
        cout<<max_vac<<endl;
    }
    return 0;
}