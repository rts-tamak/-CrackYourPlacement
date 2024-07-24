class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0);
        vector<int> indegree(V, 0);
        
        for(int i = 0; i < V; i++)
        {
            for(auto it: adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                {
                    q.push(it);
                    vis[it] = 1;
                }
            }
        }
        
        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 0)
            {
                return true;
            }
        }
        return false;
    }
};