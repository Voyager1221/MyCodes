#include <iostream>
#include <map>
using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;

        map<int,int>m;

        for(int i=0; i<2*N; i++){
            int num;
            cin>>num;
            m[num]++;
        }
        bool flag = false;
        for(int i=0; i<=N; i++){
            if(m[i]==0){
                flag=true;
                break;
            }
            if(m[i]==1)break;
        }
        if(flag==true)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}