class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 3) return nums[0]*nums[1]*nums[2];
        int pos = 0;
        int neg = 0;
        int zero = 0;
        for(auto it: nums)
        {
            if(it < 0)neg++;
            else if(it > 0) pos++;
            else zero++;
        }
        int n = nums.size();
        if(neg <= 1)
        {
            return nums[n-1]*nums[n-2]*nums[n-3];
        }
        else
        {
            return max({nums[0]*nums[1]*nums[2], nums[0]*nums[1]*nums[n-1], nums[n-1]*nums[n-2]*nums[n-3]});
        }

        
        
    }
};