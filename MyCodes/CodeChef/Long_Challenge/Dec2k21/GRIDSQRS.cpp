#include<iostream>
#include<vector>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<string> vec;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        vec.push_back(s);
    }

    for(int i=0 ; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<vec[i][j];
        }
        cout<<endl;
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