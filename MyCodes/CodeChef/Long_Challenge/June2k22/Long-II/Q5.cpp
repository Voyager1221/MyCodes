#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int strongElements(int i, int N, vector<int>&pre_comp, vector<int>&suf_comp){
    if(i==0)return suf_comp[i+1];
    if(i==N-1)return pre_comp[i-1];
    return __gcd(pre_comp[i-1], suf_comp[i+1]);

}

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;

        vector<int>pre_comp(N);
        vector<int>suf_comp(N);
        vector<int>vec(N);
        
        for(int i=0; i<N; i++){
            cin>>vec[i];
        }
        
        pre_comp[0] = vec[0];
        for(int i=1; i<N; i++){
            pre_comp[i] = __gcd(pre_comp[i-1], vec[i]);
        }
        
        suf_comp[N-1] = vec[N-1];
        for(int i=N-2; i>=0; i--){
            suf_comp[i] = __gcd(suf_comp[i+1], vec[i]);
        }

        int res = 0;
        for(int i=0; i<N; i++){
            if(strongElements(i, N, pre_comp, suf_comp)>1)res++;
        }
        cout<<res<<endl;
    }
    return 0;
}