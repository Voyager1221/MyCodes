#include <iostream>

using namespace std;

int remove_zeros(int a){
    int n=0,pow=1;
    while(a>0){
        int rem = a%10;
        a /= 10;
        if(rem!=0){
            n += rem*pow;
            pow *= 10; 
        }
    }
    return n;
}
int main(){

    int a,b,c;
    cin>>a>>b;
    c = a+b;
    a = remove_zeros(a);
    b = remove_zeros(b);
    c = remove_zeros(c);
    if(a+b==c)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}