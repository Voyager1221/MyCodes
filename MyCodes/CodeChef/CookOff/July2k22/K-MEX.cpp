#include <iostream>
#include <vector>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M,K;
        cin>>N>>M>>K;

        vector<int>vec(N,0);
        for(int i=0; i<N; i++){
            int num;
            cin>>num;
            vec[num]++;
        }
        int min = 0;
        for(int i=0; i<K; i++){
            if(vec[i]!=0){
                min++;
            }else break;
        }
        int remSpace = N-vec[K];
        if(M>=K && min==K && remSpace>=M)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;   
    }
}