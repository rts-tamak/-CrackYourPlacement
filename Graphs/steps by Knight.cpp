class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int bfs(int i, int j, int n, int m, int N, vector<vector<int>> &vis)
    {
        queue<pair<pair<int, int>, int>> q;
        q.push({{i, j}, 0});
        vis[i][j] = 1;
        
        int dx[] = {-1, -1, +1, +1, -2, -2, +2, +2};
        int dy[] = {+2, -2, -2, +2, +1, -1, -1, +1};
        
        
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int distance = q.front().second;
            q.pop();
            
            if(x == n && y == m) return distance;
            
            for(int i = 0; i < 8; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                
                if(newX >= 1 && newX <= N && newY >= 1 && newY <= N && vis[newX][newY] == 0)
                {
                    q.push({{newX, newY}, distance + 1});
                    vis[newX][newY] = 1;
                }
                
            }
        }
        return -1;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<int>> vis(N+1, vector<int>(N+1, 0));
	    return bfs(KnightPos[0], KnightPos[1], TargetPos[0], TargetPos[1], N, vis);
	    
	}
};