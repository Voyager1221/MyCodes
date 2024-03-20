#include <iostream>
#include <vector>

using namespace std;

int ninjaTraining_Tabulation(vector<vector<int>>&pointsTable, int noOfDays){
    vector<vector<int>>maxPointsTillDay(noOfDays, vector<int>(3, 0));
    int lastActivity = -1;

    // Base Condition
    maxPointsTillDay[0][1] = pointsTable[0][1];
    maxPointsTillDay[0][2] = pointsTable[0][2];
    maxPointsTillDay[0][3] = pointsTable[0][3];
    
    for(int dayNo=1; dayNo<noOfDays; dayNo++){
        for(int lastActivity=0; lastActivity<3; lastActivity++){
            for(int activity = 0; activity<3; activity++){
                if(activity != lastActivity){
                    int pointsTillCurrDayCurrActivity = pointsTable[dayNo][activity] + maxPointsTillDay[dayNo-1][lastActivity];
                    maxPointsTillDay[dayNo][activity] = max(maxPointsTillDay[dayNo][activity], pointsTillCurrDayCurrActivity);

                }
            }
        }
    }
    int maxPointsTillLastDay = -1;
    for(int itr=0; itr<3; itr++){
        maxPointsTillLastDay = max(maxPointsTillLastDay, maxPointsTillDay[noOfDays-1][itr]);
    }
    return maxPointsTillLastDay;
}

int main(){
    int N;
    cout<<"Enter the no. of days: "<<endl;
    cin>>N;

    vector<vector<int>>pointsTable(N, vector<int>(3, 0));

    cout<<"Enter the values in the table: "<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin>>pointsTable[i][j];
        }
    }


    cout<<"The maximum merit points that a  ninja can earn are: "<<ninjaTraining_Tabulation(pointsTable, N)<<endl;
    return 0;
}