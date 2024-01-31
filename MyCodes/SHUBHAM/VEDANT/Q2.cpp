#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int dp[201][201];
int t[201][201];
char s[201][201];

int solve(int day, int skip)
{
    if(day < 0) return 0;
    if(dp[day][skip] != -1) return dp[day][skip];
    int res = INT_MAX;
    for(int x=0;x <= skip;x++) res = min(res, solve(day-1, skip - x) + t[day][x]);
    dp[day][skip]=res;
    return res;
}

void computeTime()
{
    for(int i=0;i<n;i++) for(int j=0;j<=k;j++) t[i][j]=INT_MAX;
    for(int i=0;i<n;i++)
    {
        vector<int>pos;
        for(int col=0;col<m;col++) if(s[i][col] == '1') pos.push_back(col);

        for(int x = 0; x <= k; x++)
        {
            if(x >= pos.size()) t[i][x] = 0;
            else
            {
                t[i][x]  = pos[pos.size()-1] - pos[0] + 1;
                for(int j=0; j<pos.size();j++)
                {
                    int left_remove = j;
                    if(left_remove > x) break;
                    int more = x - left_remove;
                    int r = pos.size()-1-more;
                    t[i][x]=min(t[i][x], pos[r] - pos[j] + 1);
                }
            }
        }
    }
}

int main() 
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>s[i][j];
    memset(dp,-1,sizeof(dp));
    computeTime();
    cout<<solve(n-1,k);
}