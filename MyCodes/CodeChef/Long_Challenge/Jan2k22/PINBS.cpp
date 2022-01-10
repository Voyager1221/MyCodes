// #include <iostream>
// #include <cmath>

// typedef long long ll;

// using namespace std;


// bool isPrime(int num){
//     if(num==1)return 0;
//     for(int i=2; i<=sqrt(num); i++){
//         if(num%i==0)return 0;
//     }
//     return 1;
// }

// int main(){

//     int T;
//     cin>>T;
//     while(T--){
//         string s;
//         cin>>s;
//         int l = s.length();
//         ll num=0;
//         if(s.length()>1){
//             if((s[l-1]=='0'&& s[l-2]=='0')){
//                 cout<<"NO"<<endl;
//             }else{
//                 for(int i=l-1; i>=0; i--){
//                     if(s[i]=='1'){
//                         num = num + pow(2,l-1-i);
//                         // cout<<"num: "<<num<<"   i: "<<i<<endl;
//                         if(num!=2 && num%2==0){
//                             cout<<"NO"<<endl;
//                             break;
//                         }else{
//                             if(isPrime(num)){
//                                 cout<<"YES"<<endl;
//                                 break;
//                             }

//                         }
//                     }
//                     if(i==0)cout<<"NO"<<endl;
//                 }
//             }
//         }else cout<<"NO"<<endl;
//     }
//     return 0;
// }

#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        string S;
        cin>>S;
        int l=S.length(),flag=0;
        for(int i=0; i<l-1; i++){
            if(S[i]=='0')continue;
            else{
                // if(S[i+1]=='1' || S[i+1]=='0'){
                //     cout<<"YES"<<endl;
                //     flag=1;
                //     break;
                // }
                cout<<"YES"<<endl;
                flag=1;
                break;
            } 
        }
        if(flag==0)cout<<"NO"<<endl;
    }
    return 0;
}