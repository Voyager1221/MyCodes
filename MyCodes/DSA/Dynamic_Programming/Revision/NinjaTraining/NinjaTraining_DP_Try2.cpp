#include <iostream>
#include <vector>

using namespace std;

// The sub-problems are saved exactly in the same order for both the approaches/functions
int NinjaTraining_Dp(vector<vector<int>>&pointsTable,
                     vector<vector<int>>&maxPointsTillDayAndLastActivity,
                     int dayNo, 
                     int lastActivity)
{
    // Base Condition
    if(dayNo<0)return 0;
    if(maxPointsTillDayAndLastActivity[dayNo][lastActivity] != -1)return maxPointsTillDayAndLastActivity[dayNo][lastActivity];
    
    for(int activity=0; activity<3; activity++){
        if(activity != lastActivity){
            int pointsTillCurrDayCurrActivity = pointsTable[dayNo][activity] + NinjaTraining_Dp(pointsTable, maxPointsTillDayAndLastActivity, dayNo-1, activity);
            maxPointsTillDayAndLastActivity[dayNo][lastActivity] = max(maxPointsTillDayAndLastActivity[dayNo][lastActivity], pointsTillCurrDayCurrActivity);
        }
    }
    return maxPointsTillDayAndLastActivity[dayNo][lastActivity];
}

// The sub-problems are saved exactly in the same order for both the approaches/functions
int NinjaTraining_Dp_Tweaks(vector<vector<int>>&pointsTable,
                     vector<vector<int>>&maxPointsTillDayAndLastActivity,
                     int dayNo, 
                     int lastActivity)
{
    // Base Condition
    if(dayNo<0)return 0;
    if(maxPointsTillDayAndLastActivity[dayNo][lastActivity] != -1)return maxPointsTillDayAndLastActivity[dayNo][lastActivity];
    int maximum = 0;
    for(int activity=0; activity<3; activity++){
        if(activity != lastActivity){
            int pointsTillCurrDayCurrActivity = pointsTable[dayNo][activity] + NinjaTraining_Dp(pointsTable, maxPointsTillDayAndLastActivity, dayNo-1, activity);
            // maxPointsTillDayAndLastActivity[dayNo][lastActivity] = max(maxPointsTillDayAndLastActivity[dayNo][lastActivity], pointsTillCurrDayCurrActivity);
            maximum = max(maximum, pointsTillCurrDayCurrActivity);
        }
    }
    return maxPointsTillDayAndLastActivity[dayNo][lastActivity] = maximum;
}

int main(){
    int days;
    cout<<"Enter the no. of days in training programme: "<<endl;
    cin>>days;

    vector<vector<int>>pointsTable(days, vector<int>(3, -1));

    vector<vector<int>>maxPointsTillDayAndLastActivity(days, vector<int>(4, -1));
    vector<vector<int>>maxPointsTillDayAndLastActivity_forTweaked(days, vector<int>(4, -1));

    for(int i=0; i<days; i++){
        for(int j=0; j<3; j++){
            cin>>pointsTable[i][j];
        }
    }

    cout<<NinjaTraining_Dp(pointsTable, maxPointsTillDayAndLastActivity, days-1, 3)<<endl;
    cout<<NinjaTraining_Dp_Tweaks(pointsTable, maxPointsTillDayAndLastActivity_forTweaked, days-1, 3)<<endl;
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
    cout<<endl;
    for(auto i:maxPointsTillDayAndLastActivity_forTweaked){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return 0;
}