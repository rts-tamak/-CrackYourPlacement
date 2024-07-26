class Solution {
public:
    int rec(int level, int n, vector<int> &dp)
    {
        if(level == n) return 1;
        if(level > n) return 0;
        if(dp[level] != -1) return dp[level];
        int ans = 0;
        for(int steps = 1; steps <= 2; steps++)
        {
            ans += rec(level + steps, n, dp);
        }

        return dp[level] = ans;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return rec(0, n, dp);
    }
};