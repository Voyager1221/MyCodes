#include <iostream>

using namespace std;

int climbingStairs_usingFibonacci(int index){
    if(index==0)return 1;
    if(index==1) return 1;
    return climbingStairs_usingFibonacci(index-1) + climbingStairs_usingFibonacci(index-2);
}


int climbingStairs(int step, int N){
    if(step>N)return 0;
    if (step==N)return 1;
    return climbingStairs(step+1, N)+climbingStairs(step+2, N);
}

int main(){
    int N;
    cout<<"Enter the stair number: "<<endl;
    cin>>N;

    cout<<"The total no. of ways to climb are: "<<climbingStairs(0, N)<<endl;
    cout<<"Using Fibonacci, the total no. of ways to climb are: "<<climbingStairs_usingFibonacci(N)<<endl;

    return 0;
}