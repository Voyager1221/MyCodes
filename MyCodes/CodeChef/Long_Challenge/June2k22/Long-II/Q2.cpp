#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        string S;
        cin>>N>>S;                
        vector<pair<char,char>>complimentary = {{'A','T'}, {'T','A'}, {'C', 'G'}, {'G', 'C'}};
        for(int i=0; i<N; i++){
            for(auto j: complimentary){
                if(j.first==S[i]){
                    cout<<j.second;
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}