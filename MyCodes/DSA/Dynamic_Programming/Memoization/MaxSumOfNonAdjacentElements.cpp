int maxSum(int index, vector<int>&nums, vector<int>&dp){
    if(index==0)return nums[index];
    if(index<0)return 0; 
    if(dp[index]!=-1)return dp[index];
    int pick = nums[index] + maxSum(index-2, nums, dp);
    int notPick = 0 + maxSum(index-1, nums, dp);
    return dp[index] = max(pick, notPick);
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int>dp(n,-1);
    return maxSum(n-1, nums, dp);
}