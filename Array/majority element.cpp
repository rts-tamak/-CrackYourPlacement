class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for(auto it: nums)
        {
            m[it]++;
        }

        int ans = 0;
        int occ = 0;

        for(auto it: m)
        {
            if(it.second > occ)
            {
                occ = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};