class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        set<int> adj[n];
        for(auto a:roads)
        {
            int u=a[0],v=a[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int c=adj[i].size()+adj[j].size();
                if(adj[i].find(j)!=adj[i].end()) c-=1;
                mx=max(mx,c);
            }
        }
        return mx;
    }
};