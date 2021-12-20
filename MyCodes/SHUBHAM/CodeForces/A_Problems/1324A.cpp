#include <iostream>
#include <vector>
const int MX = 105;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> vec(MX);
        int max=-1,flag=1;
        for(int i=1; i<=n ; i++){
            cin>>vec[i];
            if(max<vec[i])max = vec[i];
        }
        // cout<<"max: "<<max<<endl;
        if(max%2==0){
            for(int i=1; i<=n; i++){
                if(vec[i]%2!=0){
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
            }
            if(flag==1)cout<<"YES"<<endl;    
        }else{
            for(int i=1; i<=n; i++){
                if(vec[i]%2==0){
                    cout<<"NO"<<endl;
                    flag=0;
                    break;
                }
            }
            if(flag==1)cout<<"YES"<<endl;
        }
    }
    return 0;
}