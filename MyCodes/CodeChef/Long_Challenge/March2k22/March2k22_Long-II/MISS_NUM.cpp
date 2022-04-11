#include <iostream>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        
        int arr[4];
        for(int i=0; i<4; i++){
            cin>>arr[i];
        }
        sort(arr, arr+4);
        if(arr[0]<0){
            // cout<<"In less than zero"<<endl;
            //a-b= arr[0]
            //X = arr[0]
            //Y = arr[3]
            //a = b + X;
            //a*b = Y;
            //b^2 + Xb -Y = 0
            int Discriminant = arr[0]*arr[0]-4*1*(-1*arr[3]); 
            if(Discriminant>=0){
                int r1, r2, a1, a2;
                r1 = (-1*arr[0] + sqrt(Discriminant))/2;
                r2 = (-1*arr[0] - sqrt(Discriminant))/2;
                //b = r1
                a1 = r1 + arr[0];
                a2 = r2 + arr[0];
                
                if(r1>=1 && a1>=1)cout<<a1<<" "<<r1<<endl;
                    else if(r2>=1 && a2>=1)cout<<a2<<" "<<r2<<endl;
                    else cout<<-1<<" "<<-1<<endl;
            }else cout<<-1<<" "<<-1<<endl;
        }else{
            //a+b= X
            //X = arr[2]
            //Y = arr[3]
            //a = X - b;
            //a*b = Y;
            //b^2 -Xb +Y = 0
            // if(arr[0]==0 && arr[1]==1 && arr[2]==1 && arr[3]==2)cout<<"1 1"<<endl;
            if(arr[3]-arr[2]==1){
                //a+b = X
                //a*b = Y
                //X = arr[3]
                //Y = arr[2]
                //a = X-b
                //b^2 -Xb + Y = 0
                int Discriminant =arr[3]*arr[3] - 4*arr[2];        
                if(Discriminant>=0){
                    int r1, r2, a1, a2;
                    r1 = (arr[3] + sqrt(Discriminant))/2;
                    r2 = (arr[3] - sqrt(Discriminant))/2;
                    
                    a1 = arr[3] - r1;
                    a2 = arr[3] - r2;
                    if(r1>=1 && a1>=1)cout<<r1<<" "<<a1<<endl;
                    else if(r2>=1 && a2>=1)cout<<r2<<" "<<a2<<endl;
                    else cout<<-1<<" "<<-1<<endl;
                }else cout<<-1<<" "<<-1<<endl;
            }
            else{
                
                int Discriminant = arr[2]*arr[2]-4*1*arr[3]; 
                if(Discriminant>=0){
                    int r1, r2, a1, a2;
                    r1 = (arr[2] + sqrt(Discriminant))/2;
                    r2 = (arr[2] - sqrt(Discriminant))/2;
                    //b = r1
                    
                    a1 = arr[2] - r1;
                    a2 = arr[2] - r2;
                    if(r1>=1 && a1>=1)cout<<r1<<" "<<a1<<endl;
                    else if(r2>=1 && a2>=1)cout<<r2<<" "<<a2<<endl;
                    else cout<<-1<<" "<<-1<<endl;
                }else cout<<-1<<" "<<-1<<endl;
            }
        }
    }
    return 0;
}