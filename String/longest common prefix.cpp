class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int count = 0;
        int n = strs.size();
        int m = INT_MAX;
        for(int i = 0; i < strs.size(); i++)
        {
            m = min(m, int(strs[i].size()));
        }
        int ans = 0;
        bool flag = false;
        for(int col = 0; col < m; col++)
        {
            char c ='.';
            for(int row = 0; row < n; row++)
            {
                if(c == '.')
                {
                    c = strs[row][col];
                }
                if(strs[row][col] != c)
                {
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            ans++;
        }
        string s= "";
        for(int i = 0; i < ans; i++)
        {
            s += strs[0][i];
        }
        return s;
    }
};