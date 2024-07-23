class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,false);
        dp[n-1] = true;
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=nums[i] && j+i<n;j++){
                if(dp[j+i]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
        
    }
};