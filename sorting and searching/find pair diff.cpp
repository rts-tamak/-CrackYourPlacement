class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        
        map<int, int> m;
        
        for(auto it: arr)
        {
            m[it]++;
        }

        for(auto it: arr)
        {
            if(x == 0 && m[it] >= 2) return 1;
            if(m[x+it] >= 1 && x != 0)
            {
                return 1;
            }
        }
        return -1;
    }
};