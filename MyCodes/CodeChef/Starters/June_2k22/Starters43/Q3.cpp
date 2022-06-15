#include <iostream>
#include <map>
using namespace std;

int main(){
    int T;
    cin>>T;
    map<string, char>m;
    m.insert({"00", 'A'});
    m.insert({"01", 'T'});
    m.insert({"10", 'C'});
    m.insert({"11", 'G'});
    while(T--){
        int N;
        string S;
        cin>>N>>S;
        string ans="";
        for(int i=0; i<N; i+=2){
            string sub =  S.substr(i, 2);
            ans += m[sub];
        }
        cout<<ans<<endl;
    }
    return 0;
}