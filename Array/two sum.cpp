class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            if(nums.size()<2) return {};
        map<int,int> mp;
        for(int i =0; i<nums.size();i++){
            int tempTarget = target-nums[i];
            auto it = mp.find(tempTarget);
            if(it != mp.end())
                return {i,it->second};
            else
                mp[nums[i]] = i;
            
        }
        return {};
        
    }
};