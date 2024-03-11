#include <iostream>
#include <vector>

using namespace std;

int frogJump_K_Tab_Optimized(vector<int>&height, int N, int K){
    vector<int>first(K, INT_MAX);

    first[0] = 0;
    first[1] = abs(height[1] - height[0]);
    
    // Initialize the 'first' vector like solving using tabulation method of K elements instead of N.
    // Refer the just below snippet replace N with K
    // for(int index=2; index<N; index++){
    //     for(int jump=1; jump<=K; jump++){
    //         if(index-jump>=0){
    //             int energyDiff = abs(height[index] - height[index-jump]);
    //             int minEnergyTillCurrStep =  minEnergyAtStep[index-jump] + energyDiff;
    //             minEnergyAtStep[index] = min(minEnergyAtStep[index], minEnergyTillCurrStep);
    //         }
    //     }
    // }

    // After the initialization of 'first' vector is done then we can solve remaning index from Kth index.
    for(int index=2; index<N; index++){
        int minEnergyAtStep = INT_MAX;
        for(int jump=1; jump<=K; jump++){
            if(index-jump>=0){
                int energyDiff = abs(height[index] - height[index-jump]);
                int minEnergyTillCurrStep =  first[jump] + energyDiff;
                minEnergyAtStep = min(minEnergyAtStep, minEnergyTillCurrStep);

            }
        }
        for(int itr=0; itr<K-1; itr++){
            first[itr] = first[itr+1];
        }
        first[K-1] = minEnergyAtStep;
    }

    return first[K-1];
}
int frogJump_K_Tab(vector<int>&height, int N, int K){
    vector<int>minEnergyAtStep(N, INT_MAX);

    // Base Condition
    minEnergyAtStep[0] = 0;
    minEnergyAtStep[1] = abs(height[1] - height[0]);

    for(int index=2; index<N; index++){
        for(int jump=1; jump<=K; jump++){
            if(index-jump>=0){
                int energyDiff = abs(height[index] - height[index-jump]);
                int minEnergyTillCurrStep =  minEnergyAtStep[index-jump] + energyDiff;
                minEnergyAtStep[index] = min(minEnergyAtStep[index], minEnergyTillCurrStep);
            }
        }
    }

    for(auto i:minEnergyAtStep){
        cout<<i<<" ";
    }
    cout<<endl;
    return minEnergyAtStep[N-1];
}

int main(){

    int N,K;
    cout<<"Enter the no. of steps and the range of jump: "<<endl;
    cin>>N>>K;

    vector<int>height(N, -1);
    cout<<"Enter the energy state of each step: "<<endl;
    for(int i=0; i<N; i++){
        cin>>height[i];
    }

    cout<<"The minimum energy required to climb the steps is: "<<frogJump_K_Tab(height, N, K)<<endl;
    cout<<"The minimum energy required to climb the steps is: "<<frogJump_K_Tab_Optimized(height, N, K)<<endl;
    return 0;
}