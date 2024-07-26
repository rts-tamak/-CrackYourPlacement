class Solution {
public:
    bool check(pair<int, int> p, vector<vector<bool>>& vis, vector<vector<char>>& board, int n, int m)
    {
        if(p.first >= 0 && p.first < n && p.second >= 0 && p.second < m && vis[p.first][p.second] == 0 && board[p.first][p.second] == 'O') return true;
        else return false;
    }

    void bfs(int x, int y, vector<vector<bool>>& vis, vector<vector<char>>& board, int n, int m)
    {
        vis[x][y] = 1;
        queue<pair<int, int>> q;
        q.push({x, y});

        int dx[] = {+1, -1, 0, 0};
	    int dy[] = {0, 0, +1, -1};

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();


            for(int i = 0; i < 4; i++)
            {
                if(check(make_pair(it.first + dx[i], it.second + dy[i]), vis, board, n, m))
                {
                    vis[it.first + dx[i]][it.second + dy[i]] = 1;
                    q.push({it.first + dx[i], it.second + dy[i]});
                }
            }
        }
        return;
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(i == 0 || i == n-1 || j == 0 || j == m-1)
                {
                    if(board[i][j] =='O' && vis[i][j] == 0)
                    {
                        bfs(i, j, vis, board, n, m);
                    }
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(vis[i][j] == 0 && board[i][j] == 'O')
                {
                    board[i][j] ='X';
                }
            }
        }

    }
};