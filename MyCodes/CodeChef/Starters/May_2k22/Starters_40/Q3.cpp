#include<iostream>
#include <climits>

using namespace std;
int main(){

    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int prev=INT_MIN;
        bool flag = true;
        // for(int i=0; i<N; i++){
        //     int num;
        //     cin>>num;
        //     // cout<<"num: "<<num<<" prev: "<<prev<<endl;
        //     if(num>=prev)prev = num;
        //     else {
        //         flag = false;
        //         break;
        //     }
        // }
        // if(flag)cout<<"Yes"<<endl;
        // else cout<<"No"<<endl;
        int arr[N];
        for(int i=0; i<N; i++){
            cin>>arr[i];
        }
        for(int i=0; i<N-1; i++){
            if(arr[i+1]<arr[i]){
                flag = false;
                break;
            }
        }
        if(flag)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}