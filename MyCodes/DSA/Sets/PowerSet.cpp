#include <iostream>
#include <cmath>

using namespace std;
string DecimalToBinary(int num){
    string S;
    if(num!=0){
        while(num){
            if(num & 1)S+='1';
            else S+='0';
            num>>=1;
        }
    }else S+='0';
    return S;
}

string Reverse(string S){
    char fwd, bwd;
    int len = S.length();

    // fwd = S[0];
    // bwd = S[len -1];
    for(int i=0; i<len/2; i++){
        int temp = S[i];
        S[i] = S[len -i -1];
        S[len-i-1] = temp;
    }
    return S;
}
int main(){
    int set_size;
    cin>>set_size;
    
    char set[set_size];
    
    for(int i=0; i<set_size; i++){
        cin>>set[i];
    }
    int pow_set_size = pow(2, set_size);

    for(int counter=0; counter<pow_set_size; counter++){
        for(int j=0; j<set_size; j++){
            if(counter  & (1<<j)){
               string S_counter = Reverse(DecimalToBinary(counter));
               string S_j = Reverse(DecimalToBinary(1<<j));
               //cout<<(1<<j)<<"\t"<<S_counter<<" & "<<S_j<<" => "<<Reverse(DecimalToBinary((counter  & (1<<j))))<<"----------------->";
               cout<<set[j]<<" "; 
            }
        }
        cout<<endl;
    }    
    return 0;
}