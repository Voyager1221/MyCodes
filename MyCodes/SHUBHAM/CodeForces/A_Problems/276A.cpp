#include<iostream>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int max_fun = -2e9 -5;
    while(n>0){
        int a,b;
        cin>>a>>b;
        if(b<=k && max_fun<a)max_fun = a;
        if(b>k && max_fun<(a-(b-k))){
            max_fun = a-(b-k);
        }
        n--;
    }
    cout<<max_fun<<endl;
    return 0;
}