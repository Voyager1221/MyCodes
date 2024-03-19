#include <iostream>
#include <vector>

using namespace std;


int ninjaTraining(vector<vector<int>>&pointsTable, int index, int prev){
    int maxPointsTillCurrDay = 0;
    // Base Condition
    if(index<0)return 0;
    for(int itr=0; itr<3; itr++){
        if(prev!=itr){
            int pointsTillCurrDay = pointsTable[index][itr] + ninjaTraining(pointsTable, index-1, itr);
            maxPointsTillCurrDay = max(maxPointsTillCurrDay, pointsTillCurrDay);
        } 
    }
    return maxPointsTillCurrDay;
}

int main(){
    int N;
    cout<<"Enter the size of array: "<<endl;
    cin>>N;

    vector<vector<int>>pointsTable(N, vector<int>(3, 0));
    cout<<"Enter the values in the table: "<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin>>pointsTable[i][j];
        }
    }


    cout<<"The maximum merit points that a  ninja can earn are: "<<ninjaTraining(pointsTable, N-1, -1)<<endl;
    return 0;
}