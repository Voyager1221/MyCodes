#include <iostream>
#include <map>

using namespace std;

void solve(){

    int N;
    cin>>N;
    map<int, int> m;
    for(int i=0; i<N; i++){
        int num;
        cin>>num;
        m[num]++;
    }

    int max=0,flag=-1;

    for(auto itr = m.begin(); itr!=m.end(); itr++){
        if((*itr).second==N){
            cout<<0<<endl;
            break;
        }else if((*itr).second>1){
            if((*itr).second>max) max = (*itr).second;
        }else flag=0;
    }

    if(max>1){
        cout<<N-max+1<<endl;
    }
    if(max==0 && flag==0){
        cout<<-1<<endl;
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}