#include <iostream>

typedef long long ll;

using namespace std;

ll fibonacci(ll n, ll *memo){
    ll result;
    if(memo[n]!=0)return memo[n];
    if(n==1 || n==2)result = 1;
    else{
        result = fibonacci(n-1, memo) + fibonacci(n-2, memo);
    }
    memo[n] = result;
    return result;
}

int main(){

    ll n;
    cout<<"Enter the nth fibonacci term to find: ";
    cin>>n;
    ll memo[n+1]={0};
    cout<<"\nResult: "<<fibonacci(n, memo)<<endl;
    return 0;
}
