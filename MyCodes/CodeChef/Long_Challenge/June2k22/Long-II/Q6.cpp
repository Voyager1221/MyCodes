#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N, X;
        cin>>N>>X;

        vector<int>vec(N+1);
        
        
        for(int i=0; i<N; i++){
            cin>>vec[i];
        }

        bool flag = true;
        for(int i=0; i<N; i++){
            if(vec[i]>vec[i+1]){
                if(vec[i]+vec[i+1]<=X){
                    vec[i] = vec[i] + vec[i+1];
                    vec[i+1] = vec[i] - vec[i+1];
                    vec[i] = vec[i] - vec[i+1];
                }elses{
                    flag = false;
                    break;
                }
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}