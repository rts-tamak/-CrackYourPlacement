class Solution {
public:
    bool dfs(int x, int y, vector<vector<char>>& board, string& word, int index, vector<vector<int>>& vis) {
        if (index == word.size()) {
            return true;
        }
        
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || vis[x][y] || board[x][y] != word[index]) {
            return false;
        }
        
        vis[x][y] = 1;
        
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            
            if (dfs(newX, newY, board, word, index + 1, vis)) {
                return true;
            }
        }
        

        vis[x][y] = 0;
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, word, 0, vis)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
