class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool ans = false;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        
        for(auto it: adj[node])
        {
            if(it == parent) continue;
            
            if(!vis[it])
            {
                dfs(it, node, adj, vis);
            }
            else
            {
                ans = true;
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                dfs(i, -1, adj, vis);
            }
        }
        return ans;
    }
};