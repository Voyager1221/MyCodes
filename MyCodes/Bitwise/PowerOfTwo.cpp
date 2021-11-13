#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"true"<<endl;
    }
    int num = n;
    int cnt = 0;
    while(num>0){
        num = num/2;
        cnt++;
    }
    int y = 1<<cnt-1;
    cout<<y<<endl;
}