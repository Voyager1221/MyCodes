#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        char A[N+1];
        A[0] = 'E';
        char prev = A[0];
        for(int i=0; i<N; i++){
            int num;
            cin>>num;
            if(num==1){
                if(prev =='E'){
                    A[i+1] = 'O';
                    prev = 'O';
                }
                else{
                    A[i+1] = 'E';
                    prev = 'E';
                }
            }else{
                if(prev=='E'){
                    A[i+1] = 'E';
                    prev = 'E';
                }
                else{
                    A[i+1] = 'O';
                    prev = 'O';    
                }
            }
            if(i==N-1){
                if(num==1){
                    if((A[0]=='E' && A[N-1]=='O') || (A[0]=='O' && A[N-1]=='E'))cout<<"Yes"<<endl;
                    else cout<<"No"<<endl;
                }else{
                    if((A[0]=='E' && A[N-1]=='E') || (A[0]=='O' && A[N-1]=='O'))cout<<"Yes"<<endl;
                    else cout<<"No"<<endl;
                }
            }
        }
        // for(int i=0; i<=N; i++){
        //     cout<<A[i]<<" ";
        // }
        // cout<<endl;
        // if(A[0]==A[N])cout<<"Yes"<<endl;
        // else cout<<"No"<<endl;        
    }
    return 0;
}