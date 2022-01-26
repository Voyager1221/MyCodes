//fibonacci using bottom up approach
#include <iostream>

typedef long long ll;

using namespace std;

ll Button_Up_fibonacci(ll n){
    if(n==1 || n==2)return 1;
    ll memo[n+1] = {0};
    memo[1] = 1;
    memo[2] = 1;
    for(int i=3; i<=n; i++){
        memo[i] = memo[i-1] + memo[i-2];
    }
    return memo[n];
}

int main(){

    ll n;
    cout<<"Enter the nth element to find: ";
    cin>>n;
    cout<<"\nResult: "<<Button_Up_fibonacci(n);
    return 0;
}