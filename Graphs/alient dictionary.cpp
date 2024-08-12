// User function Template for C++

class Solution{
    public:
    vector<vector<int>> adj;
    vector<int> indegree;
    vector<int> topo, vis;
    void kahn(int u, int K)
    {
        queue<int> q;
        
        for(int i = 0; i < K; i++)
        {
            if(indegree[i] == 0)
            {
                // cout << i << '\n';
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            vis[node] = 1;
            q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        indegree.assign(K, 0);
        adj.assign(K, vector<int>());
        vis.assign(K, 0);
        for(int i = 1; i < N; i++)
        {
            string s1 = dict[i-1];
            string s2 = dict[i];
            bool flag = false;
            for(int j = 0; j < min(s1.size(), s2.size()); j++)
            {
                if(s1[j] != s2[j])
                {
                    int val1 = int(s1[j] - 'a');
                    int val2 = int(s2[j] - 'a');
                    indegree[val2]++;
                    adj[val1].push_back(val2);
                    flag = true;
                    break;
                }
            }
            // if(!flag)
            // {
                
            // }
            
        }
        
        // for(int i = 0; i < K; i++)
        // {
        //     if(!vis[i])
        //     {
                kahn(0, K);
            // }
        // }
        string ans="";
        
        // for(int i = 0; i < adj.size(); i++)
        // {
        //     cout << i << " -> ";
        //     for(auto it: adj[i])
        //     {
        //         cout << it << " ";
        //     }
        //     cout << '\n';
        // }
        
        // cout << topo.size() << '\n';
        for(int i = 0; i < topo.size(); i++)
        {
            ans += char(topo[i] + 'a');
        }
        // cout << ans << '\n';
        return ans;
        
    }
};