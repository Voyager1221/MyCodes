#include <iostream>
typedef long long ll;
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        ll res=0;
        while(n>1){
            res += ((n-1)/2)*(n-1)*4;
            n -=2;
        }
        cout<<res<<endl;
    }
    return 0;
}

//2nd Approach
// #include<iostream>
 
// using namespace std;
//  typedef long long ll;
// int main(){
//     int T;
//     cin >> T;
//     while(T--)
//     {
//         ll n;
//         ll sum=0;
//         cin >> n;
//         while((n/2)>0)
//         {
//             sum = sum + 8*(n/2)*(n/2);
//             n = n-2; 
//         }
//         cout << sum  << endl;
//     }
    
//     return 0;
 
// }