#include <iostream>

using namespace std;

int main(){
    int x;
    cin>>x;
    int cnt=0;
    while(x/2!=0){
        if(x%2!=0){
            cnt++;
        }
        x = x/2;
    }
    cout<<cnt+1<<endl;
    return 0;
}