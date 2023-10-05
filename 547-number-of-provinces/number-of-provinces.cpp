class Solution {
public:
    void dfs(int i,vector<int> adj[],vector<int> &vis)
    {
        vis[i]=1;
        for(auto a:adj[i])
        {
            if(!vis[a]) dfs(a,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j])
                {
                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }
        int c=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(i,adj,vis);
            }
        }
        return c;
    }
};