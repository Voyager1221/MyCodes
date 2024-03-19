#include <iostream>
#include <vector>

using namespace std;


int ninjaTraining_dp(vector<vector<int>>&pointsTable, vector<int>&maxPointsTillDay, int dayNo, int lastActivity){

    // Base Condition
    if(dayNo<0)return 0;
    if(maxPointsTillDay[dayNo] != -1)return maxPointsTillDay[dayNo];

    for(int itr=0; itr<3; itr++){
        if(lastActivity!=itr){
            int pointsTillCurrDay = pointsTable[dayNo][itr] + ninjaTraining_dp(pointsTable, maxPointsTillDay, dayNo-1, itr);
            maxPointsTillDay[dayNo] = max(maxPointsTillDay[dayNo], pointsTillCurrDay);
        } 
    }
    return maxPointsTillDay[dayNo];
}

int main(){
    int N;
    cout<<"Enter the size of array: "<<endl;
    cin>>N;

    vector<vector<int>>pointsTable(N, vector<int>(3, 0));
    vector<int>maxPointsTillDay(N, -1);
    cout<<"Enter the values in the table: "<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin>>pointsTable[i][j];
        }
    }


    cout<<"The maximum merit points that a  ninja can earn are: "<<ninjaTraining_dp(pointsTable, maxPointsTillDay, N-1, -1)<<endl;
    return 0;
}