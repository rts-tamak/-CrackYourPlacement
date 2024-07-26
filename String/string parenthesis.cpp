class Solution {
public:
    vector<string> ans;

    void rec(int opening, int closing, string s, int n)
    {
        if(opening > n || closing > opening) return;
        if(s.size() == n*2 && opening == closing)
        {
            ans.push_back(s);
            return;
        }        
        rec(opening + 1, closing, s + '(', n);
        rec(opening, closing + 1, s + ')', n);
    }
    vector<string> generateParenthesis(int n) {
        
        rec(0, 0, "", n);
        return ans;
    }
};