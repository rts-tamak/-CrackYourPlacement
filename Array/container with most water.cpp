class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int ans = INT_MIN;
        int val = min(height[i], height[j]);
        ans = max(ans, val*(j-i));

        while(i < j)
        {
            if(height[i] <= height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
            cout << i << " " << j << '\n';
            val = min(height[i], height[j]);
            ans = max(ans, val*(j-i));
        }
        return ans;
    }
};