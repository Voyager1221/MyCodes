#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int sumx=0, sumy=0, sumz=0;
    for(int i=0; i<N; i++){
        int x,y,z;
        cin>>x>>y>>z;
        sumx += x;
        sumy += y;
        sumz += z;
    }
    if(sumx==0 && sumy==0 && sumz==0 ){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
    return 0;
}