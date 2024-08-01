class Solution {
public:
    int minMoves2(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int mid = (0 + nums.size())/2;
        int ans = 0;
        for(auto it: nums)
        {
            if(it != nums[mid])
            {
                ans += (abs(it-nums[mid]));
            }
        }
        return ans;

    }
};