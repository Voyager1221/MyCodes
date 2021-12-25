#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<int> input;
    vector<bool> visited(m);
    for(ll i=0; i<m; i++){
        ll num;
        cin>>num;
        input.push_back(num);
    }

    ll cost=0, prev=1;
    for(ll i=0; i<m; i++){
        if(!visited[i]){
            if(prev>input[i]){
                cost += n- prev + input[i]; 
                // cout<<"cost: "<<cost<<endl;
            }else{
                // if(prev==0){
                //     cost += input[i]-1;
                // }else cost += input[i] - prev;
                cost += input[i] - prev;
                // cout<<"cost: "<<cost<<endl;
            }
            visited[i] = true;
            prev = input[i];
        }
    }
    cout<<cost<<endl;
    return 0;
}