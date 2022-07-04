#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ninjaTraining(int n, vector<vector<int>>&points){
    
    vector<vector<int>>dp(n, vector<int>(4,0));

    dp[0][0] = max(dp[0][1], dp[0][2]);
    dp[0][1] = max(dp[0][0], dp[0][2]);
    dp[0][2] = max(dp[0][0], dp[0][1]);
    dp[0][3] = max(max(dp[0][0], dp[0][1]), dp[0][2]);

    for(int day=1; day<n; day++){
        for(int lastTask=0; lastTask<4; lastTask++){
            for(int task=0; task<3; task++){
                if(task!=lastTask){
                    int pnts = points[day][task] + dp[day-1][task];
                    dp[day][lastTask] = max(pnts, dp[day][lastTask]);
                }
            }
        }
    }
    return dp[n-1][3];
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<vector<int>>points(n, vector<int>(3,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<3; j++)cin>>points[i][j];
        }
        cout<< ninjaTraining(n, points)<<endl;
    }
    return 0;
}