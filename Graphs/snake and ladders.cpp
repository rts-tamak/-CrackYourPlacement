#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> flattened(n * n + 1, -1);
        
        bool leftToRight = true;
        int index = 1;
        
        // Flatten the board to 1D considering the zigzag pattern
        for (int i = n - 1; i >= 0; i--) {
            if (leftToRight) {
                for (int j = 0; j < n; j++) {
                    flattened[index++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    flattened[index++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }
        
        queue<pair<int, int>> q;
        q.push({1, 0}); // start from square 1 with 0 moves
        vector<int> vis(n * n + 1, 0);
        vis[1] = 1;
        
        while (!q.empty()) {
            int cell = q.front().first;
            int dist = q.front().second;
            q.pop();
            
            if (cell == n * n) {
                return dist;
            }
            
            for (int i = 1; i <= 6; i++) {
                int newCell = cell + i;
                
                if (newCell <= n * n && vis[newCell] == 0) {
                    vis[newCell] = 1;
                    if (flattened[newCell] == -1) {
                        q.push({newCell, dist + 1});
                    } else {
                        q.push({flattened[newCell], dist + 1});
                    }
                }
            }
        }
        
        return -1;
    }
};
