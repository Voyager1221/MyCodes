#include <climits>
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev=0, prev2=0;
    
    for(int i=1; i<n; i++){
        int oneStep = prev + abs(heights[i] - heights[i-1]);
        int twoStep = INT_MAX;
        if(i>1){
            twoStep = prev2 + abs(heights[i] - heights[i-2]);
        }
        int curri = min(oneStep, twoStep);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}