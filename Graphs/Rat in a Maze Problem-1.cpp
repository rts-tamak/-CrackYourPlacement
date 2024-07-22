class Solution {
  public:
    vector<string> ans;
    void rec(int i, int j, vector<vector<int>> &mat, string s, int n, int m, vector<vector<int>> &vis)
    {
        
        if(i >= n || j >= m || i < 0 || j < 0 || mat[i][j] == 0 || vis[i][j] == 1) return;
        
        if(i == n-1 && j == m-1)
        {
            ans.push_back(s);
            return;
        }
        vis[i][j] = 1;
        
        // down
        rec(i+1, j, mat,  s + "D", n, m, vis);
        // right
        rec(i, j+1, mat,  s + "R", n, m, vis);
        // left
        rec(i, j-1, mat, s + "L", n, m, vis);
        //up
        rec(i-1, j, mat, s + "U", n, m, vis);
        vis[i][j] = 0;
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        rec(0, 0, mat,  "", n, m, vis);
        return ans;
    }
};