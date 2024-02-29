#include <iostream>

using namespace std;

int fibonacci_tabulation_optimized(int n){
    int last2=0;
    int last1=1;

    for(int i=2; i<=n; i++){
        int res = last1 + last2;
        last2 = last1;
        last1 = res;
    }

    return last1;
}

int main(){
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    cout<<"Printing the results: "<<fibonacci_tabulation_optimized(n); 

    return 0;
}