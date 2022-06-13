#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits.h>
typedef long long ll;
typedef unsigned long long int ull;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ull X, Y;
        cin>>X>>Y;
        
        if(X==0 || Y==0){
            cout<<-1<<endl;
        }else if(X==Y){
            cout<<X<<endl;
        }else{
            ull ops=0;
            ull maxm = ull(max(X,Y));
            ull minm = ull(min(X,Y));
            while(minm<maxm){
                minm *= 2;
                ops++;
            }
            if(minm>=maxm){
                minm /= 2;
                ops--;
            }
            // cout<<"\nPrinting minm: "<<minm<<endl;
            if(minm==maxm)cout<<ops + minm<<endl;
            else{
                ull diff = maxm - minm;
                ull temp_ops = minm-diff;
                maxm -= temp_ops;
                minm -= temp_ops; 
                ops +=  temp_ops;
                minm *= 2;
                ops++;
                ops += maxm;
                cout<<"Diff: "<<diff<<" Maxm: "<<maxm<<" Minm: "<<minm<<" temp_ops : "<<temp_ops<<endl;
                cout<<ops<<endl;
            }
        }
    }
    return 0;
}