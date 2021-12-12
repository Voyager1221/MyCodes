#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

char winner(char a, char b){
    if(a==b) return a;
    else if(a=='R' && b=='P' || a=='P' && b=='R'){
        return 'P';
    }else if(a=='R' && b=='S' || a=='S' && b=='R'){
        return 'R';
    }else if(a=='P' && b=='S' || a=='S' && b=='P'){
        return 'S';
    }else{
        assert(false);
    }
}

void solve(){
    int N;
    cin>>N;

    string s;
    cin>>s;

    vector <char> vec_R(N+1);
    vector <char> vec_P(N+1);
    vector <char> vec_S(N+1);

    vector <char> result(N+1);

    result[N] = s[N-1];

    vec_R[N] = winner('R', s[N-1]);
    vec_P[N] = winner('P', s[N-1]);
    vec_S[N] = winner('S', s[N-1]);

    for(int i=N-1; i>=1; i--){

        char res_R = winner('R', s[i-1]);
        if(res_R=='R'){
            vec_R[i] = vec_R[i+1];
        }
        else if(res_R=='P'){
            vec_R[i] = vec_P[i+1];
        }
        else if(res_R=='S'){
            vec_R[i] = vec_S[i+1];
        } 

        char res_P = winner('P', s[i-1]);
        if(res_P=='R'){
            vec_P[i] = vec_R[i+1];
        }
        else if(res_P=='P'){
            vec_P[i] = vec_P[i+1];
        }
        else if(res_P=='S'){
            vec_P[i] = vec_S[i+1];
        }

        char res_S = winner('S', s[i-1]);
        if(res_S=='R'){
            vec_S[i] = vec_R[i+1];
        }
        else if(res_S=='P'){
            vec_S[i] = vec_P[i+1];
        }
        else if(res_S=='S'){
            vec_S[i] = vec_S[i+1];
        }

        if(s[i-1]=='R'){
            result[i] = vec_R[i+1];
        }
        else if(s[i-1]=='P'){
            result[i] = vec_P[i+1];
        }
        else if(s[i-1]=='S'){
            result[i] = vec_S[i+1];
        } 
    }
    // cout<<"\nPrinting vectors."<<endl;
    // // cout<<"\nPrinting vec_R"<<endl;
    // for(int i=1; i<=N; i++){
    //     cout<<vec_R[i];
    // }
    // cout<<endl;

    // // cout<<"\nPrinting vec_P"<<endl;
    // for(int i=1; i<=N; i++){
    //     cout<<vec_P[i];
    // }

    // cout<<endl;

    // // cout<<"\nPrinting vec_S"<<endl;
    // for(int i=1; i<=N; i++){
    //     cout<<vec_R[i];
    // }

    // cout<<"\n"<<endl;
    
    for(int i=1; i<=N; i++){
        cout<<result[i];
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