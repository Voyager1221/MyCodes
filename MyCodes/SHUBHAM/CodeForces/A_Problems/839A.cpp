#include<iostream>

using namespace std;

int main(){

    int n,k;
    cin>>n>>k;
    int arr[n+5];
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    int sum=0,prev=0;
    for(int i=1; i<=n; i++){
        if(arr[i]<=8 && prev==0){
            sum +=arr[i];
        }else if(arr[i]<=8 && prev!=0){
            // sum +=arr[i] + ;
            if(arr[i]+prev>=8){
                sum += 8;
                prev -= (8-arr[i]);
            }else{
                sum += arr[i]+prev;
                prev=0;
            }

        }else{
            sum +=8;
            prev += (arr[i]-8);
        }
        if(sum>=k){
            cout<<i<<endl;
            break;
            }
    }
    if(sum<k)cout<<-1<<endl;
    return 0;
}