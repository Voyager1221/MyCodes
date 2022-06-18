#include <climits>
int minEnergy(int n, vector<int>&dp, vector<int>&heights){
    int right = INT_MAX;
    if(dp[n]!=-1)return dp[n];
    if(n==0)return 0;
    int left = minEnergy(n-1, dp, heights) + abs(heights[n] - heights[n-1]);
    if(n>1){
        right = minEnergy(n-2, dp, heights) + abs(heights[n] - heights[n-2]);
    }
    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n, -1);
    return minEnergy(n-1, dp, heights);
}