class Solution {
public:
    bool ans = true;
    vector<int> vis;
    void dfs(int node, int color, vector<int> adj[])
    {
	vis[node] = color;
 
    	for(auto it: adj[node])
    	{
    		if(vis[it] == 0)
    		{
    			dfs(it, 3 - color, adj);
    		}
    		if(vis[it] == vis[node])
    		{
    			ans = false;
    			return;
    		}
    	}
    }

    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vis = vector<int>(V, 0);
	    for(int i = 0; i < V; i++)
	    {
	        if(vis[i] == 0)
	        {
	            dfs(i, 1, adj);
	            
	        }
	    }
	    return ans;
	}

};