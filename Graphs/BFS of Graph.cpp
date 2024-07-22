class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        
        queue<int> q;
        q.push(0);
        vector<int> ans;
        ans.push_back(0);
        vis[0] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node])
            {
                if(vis[it] == 1) continue;
                ans.push_back(it);
                q.push(it);
                vis[it] = 1;
            }
        }
        return ans;
    }
};