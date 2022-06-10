#include<iostream>
#include<cstring>
using namespace std;

void FirstFit(int blockSize[], int N, int processSize[], int M){

    int allocation[M];

    // memset(allocation , -1 , sizeof(allocation));
    for(int i=0; i<M; i++){
        allocation[i] = -1;
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(blockSize[j]>= processSize[i]){
                blockSize[j] -= processSize[i];
                allocation[i] = j;
                break;
            }
        }
    }
    cout<<"Process Number\t Process Size\t Block Number"<<endl;
    for(int i=0; i<M; i++){
        cout<<i+1<<"\t\t"<<processSize[i]<<"\t\t";
        if(allocation[i]!=-1){
            cout<<allocation[i]+1<<endl;
        }else cout<<"Not Allocated"<<endl;
    }
}

int main(){
    int N,M;
    cin>>N>>M;
    int blockSize[N],processSize[M]; 
    
    for(int i=0; i<N; i++){
        cin>>blockSize[i];
    }

    for(int i=0; i<M; i++){
        cin>>processSize[i];
    }

    FirstFit(blockSize, N, processSize, M);
    return 0;
}