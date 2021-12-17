#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> nos;

int nod(int num){
    int cnt=0;
    while(num!=0){
        num = num/10;
        cnt++;
    }
    return cnt;
}

void solve(){
    int n;
    cin>>n;

    int nd = nod(n);
    int arr[2] = {4,7};
    for(int i=1; i<=nd; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                int num;
                if(i-1==0){
                    num = arr[k];
                    j = j+1;
                    nos.push_back(num);
                }
                else if(i-2==0){
                    num = arr[j]*pow(10, i-1) + arr[k];
                    nos.push_back(num);
                }else{
                    // num = arr[j]*pow(10, i-1) + arr[j]*pow(10, i-2) + arr[k];
                    int q=4;
                    for(int p=0; p<2; p++){
                        num = q*100 + arr[j]*pow(10, i-2) + arr[k];
                        q = 7;
                        nos.push_back(num);
                    }               
                }

            }

        }
    }
    int flag=0;
    for(int i: nos){
        // cout<<i<<" ";
        if(n%i==0){ 
            cout<<"YES"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"NO"<<endl;
    }
}

int main(){
    solve();
    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int main(){
//     vector<vector<int>> vec  = {{4,7}, {44,47,74,77}, {444, 447, 474, 477, 744, 747, 774, 777}}
// }