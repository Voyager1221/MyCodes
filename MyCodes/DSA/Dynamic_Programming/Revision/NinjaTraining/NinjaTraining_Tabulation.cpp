#include <iostream>
#include <vector>

using namespace std;

int ninjaTraining_Tabulation(vector<vector<int>>&pointsTable, int noOfDays){
    vector<vector<int>>maxPointsTillDay(noOfDays, vector<int>(3, 0));

    // We don't need these steps as in the very next step all the possible combinations will be executed.
    // Remember, we are storing the maximum sum in each iteration for each position
    // Ex: dp(1,1) = max(pt(0,1)+ pt(1,0), pt(0,1) + pt(1, 2)) 
    
    // maxPointsTillDay[0][0] = max(pointsTable[0][1],pointsTable[0][2]) ;
    // maxPointsTillDay[0][1] = max(pointsTable[0][0],pointsTable[0][2]) ;
    // maxPointsTillDay[0][2] = max(pointsTable[0][0],pointsTable[0][1]) ;


    // Base Condition
    maxPointsTillDay[0][0] = pointsTable[0][0];
    maxPointsTillDay[0][1] = pointsTable[0][1];
    maxPointsTillDay[0][2] = pointsTable[0][2];
    
    for(int dayNo=1; dayNo<noOfDays; dayNo++){
        for(int lastActivity=0; lastActivity<3; lastActivity++){
            for(int activity = 0; activity<3; activity++){
                if(activity != lastActivity){
                    int pointsTillCurrDayCurrActivity = pointsTable[dayNo][activity] + maxPointsTillDay[dayNo-1][lastActivity];
                    maxPointsTillDay[dayNo][activity] = max(maxPointsTillDay[dayNo][activity], pointsTillCurrDayCurrActivity);
                    // maxPointsTillDay[dayNo][lastActivity] = max(maxPointsTillDay[dayNo][lastActivity], pointsTillCurrDayCurrActivity);

                }
            }
        }
    }
    int maxPointsTillLastDay = -1;
    for(int itr=0; itr<3; itr++){
        maxPointsTillLastDay = max(maxPointsTillLastDay, maxPointsTillDay[noOfDays-1][itr]);
    }

    cout<<"Printing the tabulation data..."<<endl;
     for(auto i:maxPointsTillDay){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    return maxPointsTillLastDay;
}

int ninjaTraining_Tabulation_Opt(vector<vector<int>>&pointsTable, int noOfDays){
    vector<int>maxPointsTillLastDay(3, -1);

    // Base Condition
    maxPointsTillLastDay[0] = pointsTable[0][0];
    maxPointsTillLastDay[1] = pointsTable[0][1];
    maxPointsTillLastDay[2] = pointsTable[0][2];

    for(int dayNo=1; dayNo<noOfDays; dayNo++){
        for(int lastActivity=0; lastActivity<3; lastActivity++){
            for(int activity = 0; activity<3; activity++){
                if(activity != lastActivity){
                    int pointsTillCurrDayCurrActivity = pointsTable[dayNo][activity] + maxPointsTillLastDay[lastActivity];
                    maxPointsTillLastDay[activity] = max(maxPointsTillLastDay[activity], pointsTillCurrDayCurrActivity);
                    // maxPointsTillDay[dayNo][lastActivity] = max(maxPointsTillDay[dayNo][lastActivity], pointsTillCurrDayCurrActivity);

                }
            }
        }
    }
    cout<<"Printing the tabulation data..."<<endl;
    int maxPoints = -1;
     for(auto point:maxPointsTillLastDay){
            cout<<point<<" ";
            maxPoints = max(maxPoints, point);
    }
    cout<<endl;

    return maxPoints;

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
    cout<<"Using Optimized Tabulation the maximum merit points that a  ninja can earn are: "<<ninjaTraining_Tabulation_Opt(pointsTable, N)<<endl;
    
   


    return 0;
}