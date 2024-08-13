class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp1="", temp2="";
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '#')
            {
                temp1 += s[i];
            }
            else
            {
                if(temp1.size() > 0) temp1.pop_back();
            }
        }

        for(int i = 0; i < t.size(); i++)
        {
            if(t[i] != '#')
            {
                temp2 += t[i];
            }
            else
            {
                if(temp2.size() > 0) temp2.pop_back();
            }
        }
        return temp1 == temp2;
    }
};