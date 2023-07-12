class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++)
        {
            for(auto a:graph[i])
            {
                adj[a].push_back(i);
            }
        }
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++)
        {
            indegree[i]=(int)graph[i].size();
        }
        // for(auto a:indegree) cout<<a<<" ";
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            // cout<<node<<endl;
            q.pop();
            ans.push_back(node);
            for(auto a:adj[node])
            {
                indegree[a]--;
                if(indegree[a]==0) q.push(a);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};