class Solution {
public:
    void dfs(int node, vector<int> adj[],vector<int> & vis)
    {
        vis[node]=1;
        for(auto i:adj[node])
        {
            if(!vis[i]) dfs(i,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int V=isConnected.size();
        int c=0;
        vector<int> vis(V,0);
        vector<int> adj[V];
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(i!=j&&isConnected[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                c++;
            }
        }
        return c;

    }
};