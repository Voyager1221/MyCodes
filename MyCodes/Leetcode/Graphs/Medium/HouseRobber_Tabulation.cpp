class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            int rob = nums[i];
            if(i>1)rob += dp[i-2];
            int notRob = 0 + dp[i-1];
            dp[i] = max(rob, notRob);
        }
        return dp[n-1];
    }
};