class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        int i = 0, j = cardPoints.size()-1;

        for(int i = 0; i < k; i++)
        {
            ans += cardPoints[i];
        }
        int maxi = ans;
        i = k-1;
        while(j >= 0)
        {
            if(k == 0) break;
            ans -= cardPoints[i];
            i--;
            ans += cardPoints[j];
            j--;
            maxi = max(maxi, ans);
            k--;
        }
        return maxi;
    }
};