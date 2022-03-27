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
        // if(arr[3]-arr[2]==1){
        //     sum = arr[3];
        //     sub = arr[0];
        // }else{
        //     sum = arr[2];
        //     sub = arr[0];
        // }
        int a,b;
        double res;
        // a = (sum+sub)/2;
        // b = sum - a;
        if(arr[1]*arr[3]>=1){
            
                res = sqrt(arr[1]*arr[3]);
                a = ceil(res);
                b = arr[2] - a;
                if(b>=1)cout<<a<<" "<<b<<endl;
                else cout<<"-1 -1"<<endl;
         
        }else{
                int sum = arr[2];
                int sub = arr[0];
                a = (sum+sub)/2;
                b = sum - a;
                cout<<a<<" "<<b<<endl;
                if(a>=1 && b>=1)cout<<a<<" "<<b<<endl;
                else cout<<"-1 -1"<<endl;
            }
        // if(a>=1 && b>=1)cout<<a<<" "<<b<<endl;
        // else cout<<"-1 -1"<<endl;
    }
    return 0;
}