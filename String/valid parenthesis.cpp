class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;

        for(int i = 0; i < s.size(); i++)
        {
            if(s1.size() == 0)
            {
                s1.push(s[i]);
            }
            else if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                s1.push(s[i]);
            }
            else
            {
                if(s[i] == ')')
                {
                    char c = s1.top();
                    if(c == '(') s1.pop();
                    else s1.push(s[i]);
                }
                else if(s[i] == ']')
                {
                    char c = s1.top();
                    if(c == '[') s1.pop();
                    else s1.push(s[i]);
                    
               }
                else if(s[i] == '}')
                {
                    char c = s1.top();
                    if(c == '{') s1.pop();
                    else s1.push(s[i]);
                }
                
            }
        }

        if(s1.size() == 0) return true;
        else return false;
    }
};