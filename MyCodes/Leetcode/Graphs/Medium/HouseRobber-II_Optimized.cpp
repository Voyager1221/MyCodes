class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans1=0, ans2=0;
        int prev2=0;
        ans1 = nums[0];
        for(int i=1; i<n-1; i++){
            int rob = nums[i];
            if(i>1)rob += prev2;
            int notRob = 0 + ans1;
            int curri = max(rob, notRob);
            prev2 = ans1;
            ans1 = curri;
        }
        if(n>1){
            ans2 = nums[1];
            prev2 = 0;
            for(int i=2; i<n; i++){
                int rob = nums[i];
                if(i>2)rob += prev2;
                int notRob = 0 + ans2;
                int curri = max(rob, notRob);
                prev2 = ans2;
                ans2  = curri;
            }
        }
        return max(ans1, ans2);
    }
};