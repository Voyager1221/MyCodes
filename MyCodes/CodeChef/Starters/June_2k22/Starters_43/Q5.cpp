#include<iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    vector<char>characters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p','q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    while(T--){
        int N,X;
        cin>>N>>X;

        int upperLimit = ((N/2)+(N/2-X))-1;
        if(N%2==0 && N>=2*X){
                if(N!=2*X){
                    for(int i=0; i<N; i++){
                        if(i<X){
                            cout<<characters[i];
                        }
                        else if(i>=X && i<=upperLimit){
                            cout<<characters[0];
                        }
                        else{
                            cout<<characters[N-i-1];
                        }
                    }
                }else{
                    for(int i=0; i<N; i++){
                        if(i<N/2){
                            cout<<characters[i];
                        }else{
                            cout<<characters[N-i-1];
                        }
                    }
                }

                cout<<endl;
        }
        else if(N%2!=0 && N>=(2*X-1)){
                if(N!=(2*X-1)){
                    for(int i=0; i<N; i++){
                        if(i==N/2)cout<<characters[0];
                        else if(i<X)cout<<characters[i];
                        else if(i>=X && i<=(upperLimit+1))cout<<characters[0];
                        else cout<<characters[N-i-1];
                    }
                }else{
                    for(int i=0; i<N; i++){
                        if(i<=N/2)cout<<characters[i];
                        else cout<<characters[N-i-1];
                    }
                }
            cout<<endl;
            }
        else cout<<-1<<endl;    
    }
    return 0;
}