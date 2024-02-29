#include <iostream>
#include <vector>

using namespace std;

int fibonacci_dp(vector<int>&dp_array, int n){
    if(n<=1){
        dp_array[n] = n;
    }
    if(dp_array[n]!=-1)return dp_array[n];

    return fibonacci_dp(dp_array, n-1) + fibonacci_dp(dp_array, n-2);
}

int main(){
    int n;
    vector<int>dp_array(n+1, -1);
    cout<<"Enter the number:"<<endl;
    cin>>n;
    cout<<"Printing the result: "<<fibonacci_dp(dp_array, n)<<endl;
    return 0;
}