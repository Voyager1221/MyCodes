#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    string S;
    cin>>S;
    map<string, int> m;
    int max = INT32_MIN;
    string res;
    for(int i=0; i<n-1; i++){
        string sub_s = S.substr(i, 2);
        // cout<<"\nsub_s: "<<sub_s<<endl;
        m[sub_s]++;
        if(m[sub_s]>max){
            max = m[sub_s];
            res = sub_s;
        }
    }

    cout<<res<<endl;
    return 0;
}