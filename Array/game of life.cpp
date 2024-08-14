class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> v(n, vector<int>(m, 0));

        int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
        int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int count = 0;
                for(int index = 0; index < 8; index++)
                {
                    int newX = i + dx[index];
                    int newY = j + dy[index];

                    if(newX >= 0 && newY >= 0 && newX < n && newY < m && board[newX][newY] == 1)
                    {
                        count++;
                    }
                }
                v[i][j] = count;
            }
        }


        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 1)
                {
                    if(v[i][j] < 2)
                    {
                        board[i][j] = 0;
                    }
                    else if(v[i][j] >= 2 && v[i][j] <= 3)
                    {
                        board[i][j] = 1;
                    }
                    else
                    {
                        board[i][j] = 0;
                    }
                }
                else
                {
                    if(v[i][j] == 3)
                    {
                        board[i][j] = 1;
                    }
                }
            }
        }



    }
};