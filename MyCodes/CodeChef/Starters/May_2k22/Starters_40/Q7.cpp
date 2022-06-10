#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(){

    int N;
    cin>>N;
    vector<int> A(N), B(N);
    for(int i=0; i<N; i++){
        cin>>A[i];
    }
    for(int i=0; i<N; i++){
        cin>>B[i];
    }

    int X=0;
    for(int i=0; i<31; i++){
        int a_zero=0, b_zero=0;
        // for(int j=0; j<N; j++){
        //     if((A[j] & (1<<i)) == 0)a_zero++;
        // }
        // for(int j=0; j<N; j++){
        //     if((B[j] & (1<<i)) == 0)b_zero++;
        // }
        for(int j=0; j<N; j++){
            
            if((A[j] & (1<<i))==0)a_zero++;
            if((B[j] & (1<<i))==0)b_zero++;

        }
        if(b_zero==0) X += (1<<i);
        else if(a_zero!=b_zero){
            cout<<-1<<endl;
            return;
        }
        // cout<<"\nX: "<<X<<endl;
    }
    vector<int>C(N);
    for(int i=0; i<N; i++){
        C[i] = A[i]|X;
    }
    sort(C.begin(), C.end());
    sort(B.begin(), B.end());
    if(C==B)cout<<X<<endl;
    else cout<<-1<<endl;
}

int main(){

    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}