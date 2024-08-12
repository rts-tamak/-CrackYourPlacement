class Solution {
public:
    vector<bool> vis;
    vector<int> pathvis;
    vector<int> check;
    bool dfs(int node, vector<vector<int>>& adj)
    {
        // cout << node << '\n';
        vis[node] = 1;
        pathvis[node] = 1;
        check[node] = 0;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                if(dfs(it, adj))
                {
                    check[node] = 0;
                    return true;
                }
            }
            else
            {
                if(pathvis[it])
                {
                    check[node] = 0; 
                    return true;
                }
            }
        }
        check[node] = 1;
        pathvis[node] = 0;
        return false;
    }


    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vis.assign(graph.size(), 0);
        pathvis.assign(graph.size(), 0);
        check.assign(graph.size(), 0);    
        // cout << dfs(0, graph) << '\n';
        for(int i = 0; i < graph.size(); i++)
        {
            if(!vis[i])
            {
                dfs(i, graph);
            }
        }  
        vector<int> ans;

        for(int i = 0; i < graph.size(); i++)
        {
            if(check[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};