#include <iostream>

using namespace std;

struct couple{
    int sum;
    int nod;
};

int pod(int sod, int nod){
    int prod=1;
    while(sod!=0){
        if(sod%nod!=0){
            prod = prod*sod%nod;
            sod = sod - sod%nod;
        }else{
            prod = prod*sod/nod;
            sod = sod - sod/nod;
        }
    }
    return prod;
}

couple sod(int n, int k){
    int sum=0,temp = n,cnt=0;
    couple c;    
    while(temp>0){
        sum = sum + temp%10;
        temp = temp/10;
        cnt++;
    }
    c.sum = sum + k;
    c.nod = cnt;
    return c;
}

void solve(){
    int N,K;
    cin>>N>>K;
    couple c = sod(N, K);
    cout<<pod(c.sum, c.nod)<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}