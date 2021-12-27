#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverse(string &str){
    string temp;
    for(int i=str.length()-1; i>=0; i--){
        temp += str[i];
    }
    str = temp;
}


int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        string S;
        cin>>N>>K>>S;
        int t=K;
        string str1,str2;
        str2 = S.substr(K,(N-1)-K+1);
        // for(int i=K-1; i>=0; i--){
        //     str1 += S.substr(i, 1);
        // }
        // cout<<"str1: "<<str1<<endl;
        // cout<<"str2: "<<str2<<endl;
        // S = str1+str2;
        int flag1=0, flag2=0;
        do{
            if(flag1==0){
                t -= 2;
                flag1=1;
            }
            str1 = str1+S[t];
            if(t==1){
                t += 1;
                str1 =  str1 + S[t];
                flag2=1;
            }
            if(flag2!=1) t -=2;
            else t +=2;
            // if(flag1==0){
            //     t = t-2;
            //     flag1=1;
            // }
            // if(K%2!=0){
                
            //     if(t==0){
            //         str1 = S[t] + str1;
            //         t += 1;
            //         flag2=1;
            //     }
            //     if(flag1==0){
            //         t = t-1;
            //         flag1=1;
            //     }
            //     str1 = S[t] + str1;
            //     std::cout<<"str1: "<<str1<<endl; 
            //     if(flag2==1)t += 2;
            //     else t -= 2; 
            // }else{
            //     if(t==0){
            //         t += 2;
            //         flag2=1;
            //     }
            //     if(flag1==0){
            //         t = t-1;
            //         flag1 = 1;
            //     }
            //     str1 += S[t];
            //     if(flag2==1) t +=2;
            //     else if(t==1)t -=1;
            //     else t-=2;
            // }
        }while(t<K);
        // str1 += str1 + S[0];
        S = str1 + S[0] + str2;
        std::cout<<S<<endl;
    }
    return 0;
}