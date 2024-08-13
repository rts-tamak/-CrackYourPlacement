class Solution {
public:
    int bfs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int,int>, int>> q;
        int fresh = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                if(grid[i][j] == 1) fresh++;
            }
        }
        
        int ans = 0;
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int time = q.front().second;
            q.pop();
            cout << x << " " << y << '\n';
            ans = max(ans, time);

            
            // iterating over rotten oranges

            int dx[] = {1, 0, 0, -1};
            int dy[] = {0, 1, -1, 0};

            for(int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];


                if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] ==1  && vis[newX][newY] == 0)
                {
                    q.push({{newX, newY}, time + 1});
                    vis[newX][newY] = 1;
                    fresh--;
                }

            }
        }
        
        if(fresh > 0) return -1;

        return ans;  
    } 

    int orangesRotting(vector<vector<int>>& grid) {
        return bfs(grid);
    }
};