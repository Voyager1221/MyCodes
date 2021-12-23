#include <iostream>

using namespace std;

int main(){
    int n,b,d;
    cin>>n>>b>>d;
    int sum=0, cnt=0;
    for(int i=0; i<n; i++){
        int orange;
        cin>>orange;
        if(orange<=b){
            sum += orange;
            if(sum>d){
                sum =0;
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
