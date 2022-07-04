#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int recursion(int currDay, int prevTask, vector<vector<int>>&dp, vector<vector<int>>&points){
    if(dp[currDay][prevTask]!=-1)return dp[currDay][prevTask];

    int maxPoint=INT_MIN;
    for(int i=0; i<3; i++){
        if(i!=prevTask){
            int L = points[currDay][i];
            if(currDay-1>=0){
                 L += recursion(currDay-1, i, dp, points);
            }
            maxPoint = max(L, maxPoint);
            }
    }
    return dp[currDay][prevTask] = maxPoint;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>>dp(n, vector<int>(4, -1));
    return recursion(n-1, 3, dp, points);
    
}