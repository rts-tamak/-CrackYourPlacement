class Solution {
public:
    string reverseWords(string s) {

        while(s[s.size()-1] == ' ') s.pop_back();
        reverse(s.begin(), s.end());
        while(s[s.size()-1] == ' ') s.pop_back();

        int prev = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
            {
                reverse(s.begin()+prev, s.begin()+i);
                prev = i+1;
            }
        }
        reverse(s.begin()+prev, s.end());
        string ans = "";

        for(int i = 0; i < s.size(); i++)
        {
            if(ans.size() > 0 && ans[ans.size()-1] == ' ' && s[i] == ' ') continue;
            ans += s[i];
        }
        return ans;


    }
};