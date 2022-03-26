#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
    int n;
    cin>>n;
    
    int X[n], Y[n], Z[n];
    for(int i=0; i<n; i++){
        cin>>X[i];
    }

    for(int i=0; i<n; i++){
        if(i==0){
            Y[i] = 0;
            Z[i] = X[i] - Y[i];
        }
        else if(X[i]- Z[i-1]>Y[i-1]){
            Y[i] = X[i] - Z[i-1];
            Z[i] = Z[i-1];
        }else{
            Z[i] = X[i] - Y[i-1];
            Y[i] = Y[i-1];
        }
    }
    int sum=0;
    for(int i=0; i<n; i++){
        // cout<<Y[i]<<" "<<Z[i]<<endl;
        sum+= abs(Y[i]) + abs(Z[i]);
    }
    cout<<sum<<endl;

    }
    return 0;
}