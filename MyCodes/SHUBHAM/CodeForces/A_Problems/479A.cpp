#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int res;
    if(a==b==c==1){
        res = 3;
    }else if(a==1 && c==1){
        res = a+b+c;
    }else if(a==1){
        res = (a+b)*c;
    }else if(b==1){
        res = (min(a,c) + b) * max(a,c);
    }else if(c==1){
        res = (b+c)*a;
    }else{
        res = a*b*c;
    }
    cout<<res<<endl;
}