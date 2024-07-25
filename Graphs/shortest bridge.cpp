class Solution {
public:
    int n, m;
    void dfs(int x, int y, vector<vector<int>>& vis, vector<vector<int>>& grid, queue<pair<pair<int, int>, int>> &q)
    {
        if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0 || vis[x][y] == 1) return;
        vis[x][y] = 1;
        q.push({{x, y}, 0});

        dfs(x+1, y, vis, grid, q);
        dfs(x,  y+1, vis, grid, q);
        dfs(x-1, y, vis, grid, q);
        dfs(x, y-1, vis, grid, q);
    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i, j, vis, grid, q);
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        // bfs

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        int ans = INT_MAX;
        int size = q.size();
        // cout << size << '\n';
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            size--;
            if(size < 0 && grid[x][y] == 1)
            {
                ans = min(ans, distance);
            }
            for(int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(newX >= 0 && newX < n && newY >= 0 && newY < m && vis[newX][newY] == 0)
                {
                    q.push({{newX, newY}, distance + 1});
                    vis[newX][newY] = 1;
                }
            }
        }
        return ans-1;
    }
};