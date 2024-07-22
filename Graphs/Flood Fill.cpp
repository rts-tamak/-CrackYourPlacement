class Solution {
public:
    void dfs(int x, int y, vector<vector<int>>& image, int color, int n, int m, vector<vector<int>> &vis, int value)
    {
        if(x < 0 || x >= n || y < 0 || y >= m || image[x][y] == color || vis[x][y] == 1 || image[x][y] != value) return;

        vis[x][y] = 1;
        image[x][y] = color;

        dfs(x + 1, y, image, color, n, m, vis, value);
        dfs(x, y + 1, image, color, n, m, vis, value);
        dfs(x - 1, y, image, color, n, m, vis, value);
        dfs(x, y - 1, image, color, n, m, vis, value);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        dfs(sr, sc, image, color, n, m, vis, image[sr][sc]);
        return image;
    }
};