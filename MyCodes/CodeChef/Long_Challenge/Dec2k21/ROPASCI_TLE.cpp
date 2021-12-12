#include <iostream>

using namespace std;

void solve(){
    int N;
    cin>>N;
    string S;
    cin>>S;
    char res[N];
    char prev;
    for(int i=0; i<N; i++){
        prev = S[i];
        for(int j=i+1; j<N; j++){
            if(prev==S[j]) continue;
            else{
                if(prev=='R'){
                    if(S[j]=='P') prev = S[j];
                    else continue;
                }else if(prev=='S'){
                    if(S[j]=='R') prev = S[j];
                    else continue;
                }else if(prev=='P'){
                    if(S[j]=='S') prev = S[j];
                    else continue;
                }else continue;
            }
        }
        res[i] = prev;
    }

    for(int i=0; i<N; i++){
        cout<<res[i];
    }
    cout<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}