class Solution {
public:

    
    void dfs(int node, vector<int> &vis, vector<int> adj[])
    {
        vis[node] = 1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs(it, vis, adj);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections)
    {
        if (connections.size() < n - 1)
        {
            return -1;
        }

        vector<int> vis(n, 0);
        vector<int> adj[n];
        

        for(const auto& conn : connections)
        {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        int components = 0;

        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                dfs(i, vis, adj);
                components++;
            }
        }

        return components - 1;
    }
};
