#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        int arr[N+1]; 
        arr[N] = N;
        bool subtract = true; 
        for(int i=N-1; i>0; i--){
            if(subtract){
                arr[i] = arr[i+1] - i;
                subtract = false;
                continue;
            }
            if(!subtract){
                arr[i] = arr[i+1] + i;
                subtract = true;
            }
        }
        for(int i=1; i<=N; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}