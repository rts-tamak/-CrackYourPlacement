class Solution {
public:
    void dfs(int x, int y, vector<vector<bool>> &vis, vector<vector<char>>& grid)
    {
        if(x >= grid.size() || x < 0 || y >= grid[0].size() || y < 0 || grid[x][y] == '0' || vis[x][y] == 1) return;
        vis[x][y] = 1;

        dfs(x+1, y, vis, grid);
        dfs(x, y+1, vis, grid);
        dfs(x-1, y, vis, grid);
        dfs(x, y-1, vis ,grid);

    }

    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), 0));

        int count = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1' && vis[i][j] == 0)
                {
                    dfs(i, j, vis, grid);
                    count++;
                }
            }
        }

        return count;
    }
};