#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n+1];
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }

        int cnt=0;
        //4 1 3
        for(int i=1; i<=n; i++){
            if(arr[i]==i+cnt)cnt++;
        }
        cout<<cnt<<endl;
    }
}