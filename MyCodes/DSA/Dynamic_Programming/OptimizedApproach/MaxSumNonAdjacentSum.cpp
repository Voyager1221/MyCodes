int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    int prev = 0;
    int prev2 = 0;
    
    for(int i=0; i<n; i++){
        int pick = nums[i];
        if(i>1)pick+= prev2;
        int notPick = 0 + prev;
        int curri = max(pick, notPick);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}