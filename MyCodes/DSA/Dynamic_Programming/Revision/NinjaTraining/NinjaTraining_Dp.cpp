#include <iostream>
#include <vector>

using namespace std;


int ninjaTraining_dp(vector<vector<int>>&pointsTable,
                     vector<vector<int>>&maxPointsTillDay, 
                     int dayNo, 
                     int lastActivity)
{
    // Base Condition
    if(dayNo<0)return 0;
    if(maxPointsTillDay[dayNo][lastActivity] != -1)return maxPointsTillDay[dayNo][lastActivity];

    for(int itr=0; itr<3; itr++){
        if(lastActivity!=itr){
            int pointsTillCurrDay = pointsTable[dayNo][itr] + ninjaTraining_dp(pointsTable, maxPointsTillDay, dayNo-1, itr);
            cout<<"Day No: "<<dayNo<<" lastActivity: "<<lastActivity<<" pointsTillCurrDay: "<<pointsTillCurrDay<<endl;
            maxPointsTillDay[dayNo][lastActivity] = max(maxPointsTillDay[dayNo][lastActivity], pointsTillCurrDay);
        } 
    }
    return maxPointsTillDay[dayNo][lastActivity];
}

int main(){
    int N;
    cout<<"Enter the no. of days: "<<endl;
    cin>>N;

    vector<vector<int>>pointsTable(N, vector<int>(3, 0));
    vector<vector<int>>maxPointsTillDay(N, vector<int>(3, -1));
    cout<<"Enter the values in the table: "<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin>>pointsTable[i][j];
        }
    }


    cout<<"The maximum merit points that a  ninja can earn are: "<<ninjaTraining_dp(pointsTable, maxPointsTillDay, N-1, 3)<<endl;
    for(auto i:pointsTable){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    for(auto i:maxPointsTillDay){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}