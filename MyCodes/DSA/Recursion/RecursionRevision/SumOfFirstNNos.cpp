#include <iostream>

using namespace std;

// Solving the problem via Parameterized way i.e. the result of sub-task is passed as parameter.
void sumOfFirstNNos_Parameterized(int i, int sum){
    // Base condition
    if(i<1){
        cout<<"The sum of first N nos using parameterized function approach is: "<<sum<<endl;
        return;
    }
    sumOfFirstNNos_Parameterized(i-1, sum+i);
}

// Solving the problem via Functional way i.e. the function itself returns the value
int sumOfFirstNNos(int num, int N){
    // Base condition
    if(num>N){
        return 0;
    }

    return num + sumOfFirstNNos(num+1, N);
}

int main(){
    int N;
    cout<<"Enter the value of N: "<<endl;
    cin>>N;
    sumOfFirstNNos_Parameterized(N, 0);
    cout<<"The sum of first N nos is: "<<sumOfFirstNNos(1, N)<<endl;
    return 0;
}