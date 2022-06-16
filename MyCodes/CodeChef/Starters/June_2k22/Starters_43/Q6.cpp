#include<iostream>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        map<int,int>m;
        int min = INT_MAX;
        int cnt=0,j=N-1;
        if(N%2==0){
            for(int i=1; i<=N/2; i++){
                int sum = 0;
                if(i%2==0){
                    sum = __gcd(i,j) + j;
                }else{
                    int GCD = __gcd(i, j);
                    if(GCD==1){
                        sum = GCD + j; //GCD = 1;
                    }else{
                        sum = GCD + i*j;
                    }
                }
                if(min>sum)min = sum;
                // cout<<"\nSum: "<<sum<<" i: "<< i<< " j: "<<j<<endl;
                m[sum] += 2;
                    
                // if(i!=N/2)cnt = cnt + 2*cnt;
                // else cnt += 1;
                j--;
            }
        }else{
            for(int i=1; i<=N/2; i++){
                int sum = 0;
                if(i%2==0){
                    sum = 1 + i*j;
                }else{
                    int GCD = __gcd(i, j);
                    if(GCD==1){
                        sum = GCD + i*j;
                    }else{
                        sum = GCD + ((i/GCD) * j);
                    }
                }
                // cout<<"\nSum: "<<sum<<" i: "<< i<<" j: "<<j<<endl;
                if(min>sum)min = sum;
                if(i!=N/2)m[sum] += 2;
                else m[sum]++;
                j--;
            }
        }
        // for(auto itr:m){
        //     cout<<"First: "<<itr.first<<" Second: "<<itr.second<<endl;
        // }
        cout<<m[min]<<endl;        
    }
    return 0;
}