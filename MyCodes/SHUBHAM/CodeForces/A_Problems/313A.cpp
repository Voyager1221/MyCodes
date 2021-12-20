#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> vec;
    if(n<0){
        int t=n,min=1e9+1,max=0,index;
        for(int i=0; i<2; i++){
            double D  = pow(10, i+1);
            int rem = (-1)*t%10;
            t = t/10;
            if(rem<min){
                min = rem;
            }
            if(rem>max){
                max = rem;
                index = i;
            }
        }
        if(index==0){
            n = n/10;
        }else{
            n = (n/100)*10 - min;
        }
    }
    cout<<n<<endl;   
    return 0;
}