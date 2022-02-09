#include <iostream>
#include <map>
#include <climits>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int flag = 1;
        map<int, int>m;
    
        int min=INT_MAX;
        for(int i=0; i<2*n; i++){
            int num;
            cin>>num;
            m[num]++;
            if(num<min){
                min = num;
            }
        }
        if(min!=0){
            cout<<"Yes"<<endl;
        }else{
            // for(auto itr: m){
            //     if(itr.second<2){
            //         flag=0;
            //         break;
            //     } 
            // }
            // if(flag==1)cout<<"Yes"<<endl;
            // else cout<<"No"<<endl;
            int num;
            for(int i=0; i<n; i++){
                if(m[i]==0){
                    num = i;
                    break;
                }
            }
            for(auto itr: m){
                if(itr.second<2 && itr.first<num){
                    flag=0;
                    break;
                }
            }
            if(flag==1)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}