#include <iostream>
#include <vector>

using namespace std;

int fibonacci_tabulation(vector<int>&dp_array, int n){
    // Base Condition
    dp_array[0] = 0;
    dp_array[1] = 1;

    for(int i=2; i<=n; i++){
        dp_array[i] = dp_array[i-1] + dp_array[i-2];
    }
    return dp_array[n];
}

int main(){
    int n;
    vector<int>dp_array(n+1, -1);
    cout<<"Enter the number: "<<endl;
    cin>>n;

    cout<<"Printing the results: "<<fibonacci_tabulation(dp_array, n);
    return 0;
}