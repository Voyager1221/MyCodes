#include <iostream>
#include <map>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){

        int N;
        cin>>N;
        string A,B;
        cin>>A>>B;

        map<char,int>m;
        for(int i=0; i<N; i++){
            m[B[i]]++;
        }

        for(int i=0; i<N; i++){
            if(A[i]==B[i]){
                m[B[i]]--;
            }
        }
        int op=0;
        for(auto itr:m){
            if(itr.second!=0)op++;
        }
        cout<<op<<endl;

    }
    return 0;
}