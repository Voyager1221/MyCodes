#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){

        int arr[4];
        for(int i=0; i<4; i++){
            cin>>arr[i];
        }

        sort(arr, arr+4);
        int sum, sub;
        if(arr[3]-arr[2]==1){
            sum = arr[3];
            sub = arr[0];
        }else{
            sum = arr[2];
            sub = arr[0]; 
        }
        
        // if(arr[3]-arr[2]==1){
        //     sum = arr[3];
        //     sub = arr[0];
        // }else{
        //     sum = arr[2];
        //     sub = arr[0];
        // }
        int r1,r2;
        if(sum+sub>=2){
            r1 = (sum+sub)/2;
            r2 = sum - r1;
            if(arr[0]>=0)cout<<r1<<" "<<r2<<endl;
            else cout<<r2<<" "<<r1<<endl;
        }else cout<<"-1 -1"<<endl;
    }
    return 0;
}