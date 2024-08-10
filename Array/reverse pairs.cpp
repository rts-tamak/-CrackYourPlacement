class Solution {
public:
    int reversePairs(vector<int>& nums)
    {
        multiset<int> s;
        int count = 0;

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            auto it = s.lower_bound((nums[i] % 2 == 0) ? (nums[i] / 2) : (nums[i] / 2 + 1));
            count += distance(s.begin(), it); 
            s.insert(nums[i]);  
        }

        return count;
    }
};
