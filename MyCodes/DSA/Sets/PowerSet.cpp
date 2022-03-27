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
    }else S='0';
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
               string S_counter = DecimalToBinary(counter);
               string S_j = DecimalToBinary(j);
               cout<<S_counter<<" & "<<S_j<<"----------------->";
               cout<<set[j]<<"\t"; 
            }
        }
        cout<<endl;
    }    
    return 0;
}