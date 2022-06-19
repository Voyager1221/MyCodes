#include <iostream>
#include <cmath>
using namespace std;

int highestpow(int n){
    int degree=-1;
    while(n!=0){
        degree++;
        n /= 2;
    }
    return pow(2, degree);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int A,B,N;
        cin>>A>>B>>N;

        int tempA = A, tempB = B;
        int pow_A = -1;
        int pow_B = -1;
        int ops = 0;
        int i=0;
        int maxVal=0, minVal=0;
        while(tempA!=0 || tempB!=0){
            if(tempA%2!=tempB%2){
                maxVal += pow(2, i);
            }
            if(tempA!=0){
                pow_A++;
                tempA /= 2;
            }
            if(tempB!=0){
                pow_B++;
                tempB /= 2;
            }
            i++;
        }
        minVal = pow(2, max(pow_A, pow_B));
        if(A==B)cout<<0<<endl;
        else if(pow_A==pow_B){
            int hpow = highestpow(maxVal);
            if(N>maxVal)cout<<1<<endl;
            else if( N>hpow && maxVal!=hpow)cout<<2<<endl;
            else cout<<-1<<endl;
        }else{
            if(N>maxVal)cout<<1<<endl;
            else if(N<=maxVal && N>minVal)cout<<2<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}