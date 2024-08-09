class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;

        for(auto it: nums)
        {
            m[it]++;
        }
        vector<pair<int, int>> v;

        for(auto it: m)
        {
            v.push_back({it.second, it.first});
        }
        vector<int> ans;
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        for(int i = 0; i < k; i++)
        {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};