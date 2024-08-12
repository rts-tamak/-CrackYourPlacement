#include<bits/stdc++.h>
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> s(wordList.begin(), wordList.end());

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        while(!q.empty())
        {
            string word = q.front().first;
            string worde = word;
            int dist = q.front().second;
            q.pop();
            if(word == endWord) return dist;
            for(int i = 0; i < word.size(); i++)
            {
                worde = word;
                for(char j = 'a'; j <= 'z'; j++)
                {
                    worde[i] = j;
                    auto it = s.find(worde);
                    if(it != s.end())
                    {
                        q.push({worde, dist+1});
                        s.erase(worde);
                    }
                }
            }
        }
        return 0;
    }
};