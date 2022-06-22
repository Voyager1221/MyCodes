class Solution {
public:
    int maxRobbery(int index, vector<int>&nums, vector<int>&dp){
        if(index==0)return nums[index];
        if(index<0)return 0;
        if(dp[index]!=-1)return dp[index];
        int rob = nums[index] + maxRobbery(index-2, nums, dp);
        int notRob = 0 + maxRobbery(index-1, nums, dp);
        return dp[index] = max(rob, notRob);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return maxRobbery(n-1, nums, dp);
    }
};