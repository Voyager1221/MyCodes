#include <iostream>

using namespace std;

int main(){

    int T;
    cin>>T;
    while(T--){
        //int r,g,b,w;
        //cin>>r>>g>>b>>w;
        int arr[4], min=INT32_MAX;
        int odd_cnt=0, even_cnt=0;
        for(int i=0; i<4; i++){
            // int num;
            cin>>arr[i];
            
            if(arr[i]%2!=0)odd_cnt++;
            else{
                even_cnt++;
                if(arr[i]<min)min = arr[i];
            }
        }

        if(odd_cnt!=2 && odd_cnt>=1){
            if(odd_cnt!=3)cout<<"YES"<<endl;
            else{
                if(min>=2 || arr[3]==0)cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }else if (even_cnt==4){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
    }
    return 0;
}