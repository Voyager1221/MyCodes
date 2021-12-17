#include<iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isPalin(int num){
    int mun = 0,temp = num;

    while(num!=0){
        int rem = num%10;
        mun = mun*10 + rem;
        num = num/10;
    }
    // cout<<mun<<endl;
    // cout<<"temp: "<<temp<<endl;
    if(temp==mun)return true;
    return false;   
}

int main(){
    int n;
    cin>>n;
    int cnt=1,flag=0;
    while(true){
        double m = (pow(10, cnt));
        if(n%(int)(m)==0){
            cnt++;
            flag=1;
        }
        else{break;}
    }
    // cout<<"N OG value: "<<n<<endl;
    if(flag==1){
        double m = pow(10, cnt-1);
        // cout<<"value of m: "<<m<<endl;
        n = n/int(m);
    }

    // cout<<"Initial n : "<<n<<endl;
    if(isPalin(n)){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
}