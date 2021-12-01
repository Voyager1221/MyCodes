#include <iostream>

using namespace std;

void solve(){
    int N,K;
    cin>>N>>K;
    int arr[N];
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }

    for(int i=1; i<=K; i++){
        int prev=0,cnt=0;
        for(int j=0; j<N; j++){
            if(arr[j]==i)continue;
            else{
                if(arr[j]==prev)continue;
                else cnt++;
                prev = arr[j];
            }
        }
        if(K!=1)cout<<cnt-1<<" ";
        else cout<<0<<" ";
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