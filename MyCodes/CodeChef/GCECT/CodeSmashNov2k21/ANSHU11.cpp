#include <iostream>

using namespace std;

void Budget(){
    int N;
    float B, sum=0;
    cin>>N>>B;
    
    for(int i=0; i<N; i++){
        float num;
        cin>>num;
        sum += num;
    }
    if(sum>1000){
        sum = 0.9*sum;
    }
    (sum>B)?cout<<"NO"<<endl:cout<<"YES"<<endl;
    cout<<endl;
}

int main(){

    int T;
    cin>>T;
    while(T--){
        Budget();
    }
    return 0;
}