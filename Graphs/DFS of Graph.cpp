class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> ans;
    
    void dfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it, adj, vis);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        dfs(0, adj, vis);
        return ans;
    }
};