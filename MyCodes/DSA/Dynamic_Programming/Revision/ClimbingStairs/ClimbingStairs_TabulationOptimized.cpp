#include <iostream>

using namespace std;

int climbingStairs_TabulationOptimized(int N){
    // Base Condition
    int last1=1;
    int last2=1;

    // Bottom-Up calculation
    for(int i=2; i<=N; i++){
        int curr = last1 + last2;
        last2 = last1;
        last1 = curr;
    }
    return last1;
}

int main(){
    int N;
    cout<<"Enter the stair number: "<<endl;
    cin>>N;

    cout<<"The total no. of ways to climb are: "<<climbingStairs_TabulationOptimized(N)<<endl;

    return 0;
}