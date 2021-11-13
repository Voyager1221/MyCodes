#include <iostream>

using namespace std;

bool powerOfTwo(int n){
    if(n<1) return false;
    while(n%2==0){
        n = n/2;
    }
    return (n==1)?true:false;
}

int main(){
    int n;
    cin>>n;
    //MY METHOD/ APPROACH
/*
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
*/
    bool result = powerOfTwo(n);
    cout<<"The result is : "<<result<<endl;
    return 0;

}