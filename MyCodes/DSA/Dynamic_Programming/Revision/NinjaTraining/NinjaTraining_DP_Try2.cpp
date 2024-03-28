#include <iostream>
#include <vector>

using namespace std;

int NinjaTraining_Dp(vector<vector<int>>&pointsTable,
                     vector<vector<int>>&maxPointsTillDayAndLastActivity,
                     int dayNo, 
                     int lastActivity)
{
    cout<<"where are we?"<<endl;
    // Base Condition
    if(dayNo<0)return 0;
    cout<<"Did we crossed 1st base condition?"<<endl;

    // if(maxPointsTillDayAndLastActivity[dayNo][lastActivity] != -1)return maxPointsTillDayAndLastActivity[dayNo][lastActivity];
    cout<<"Did we crossed 2nd base condition?"<<endl;
    for(int activity=0; activity<3; activity++){
        if(activity != lastActivity){
            cout<<"Are we in if statement inside of for loop?"<<endl;
            int pointsTillCurrDayCurrActivity = pointsTable[dayNo][activity] + NinjaTraining_Dp(pointsTable, maxPointsTillDayAndLastActivity, dayNo-1, activity);
            maxPointsTillDayAndLastActivity[dayNo][lastActivity] = max(maxPointsTillDayAndLastActivity[dayNo][activity], pointsTillCurrDayCurrActivity);
        }
    }
    return maxPointsTillDayAndLastActivity[dayNo][lastActivity];
}

int main(){
    int days;
    cout<<"Enter the no. of days in training programme: "<<endl;
    cin>>days;

    vector<vector<int>>pointsTable(days, vector<int>(3, -1));
    vector<vector<int>>maxPointsTillDayAndLastActivity(days, vector<int>(4, -1));
    for(int i=0; i<days; i++){
        for(int j=0; j<3; j++){
            cin>>pointsTable[i][j];
        }
    }

    cout<<NinjaTraining_Dp(pointsTable, maxPointsTillDayAndLastActivity, days-1, 3)<<endl;
    for(auto i:pointsTable){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    cout<<endl;
    
    for(auto i:maxPointsTillDayAndLastActivity){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}