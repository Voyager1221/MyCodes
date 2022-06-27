#include <iostream>
#include <map>
#include <climits>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        map<int,int>m;
        for(int i=0; i<N; i++){
            int num;
            cin>>num;
            m[num]++;
        }
        int max_reps=INT_MIN;                
        for(auto itr:m){
            if(itr.second>max_reps)max_reps = itr.second;
        }
        cout<<N-max_reps<<endl;
    }
    return 0;
}
