#include <iostream>

using namespace std;

int noOfUniqueSubString(int length){
    return length*(length+1)/2;
}

void solve(){
    int N,M;
    cin>>N>>M;

    /*
        TLE with this approach

    // int noz = N-M, sum=0;
    // int partition = M+1;
    
    // while(noz!=0){
    //     if(noz%partition!=0){
    //         int rem = noz%partition;
    //         sum = sum + (rem*(rem+1))/2;
    //         noz = noz - rem;
    //         partition--;
    //     }else{
    //         int rem = noz/partition;
    //         sum = sum + (rem*(rem+1))/2;
    //         noz = noz - rem;
    //         partition--;
    //     }
    // } 
    // cout<<sum<<endl;
    */
    int numZero = N-M;
    int numPart = M+1;
    int reqZero = numZero/numPart;
    //int extraZero  = numZero%numPart;   
    int extraZero = numZero - reqZero*numPart;
    cout<<(numPart-extraZero)*noOfUniqueSubString(reqZero) + (extraZero)*noOfUniqueSubString(reqZero+1)<<endl;   
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}