class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) 
    {
        vector<int> indegree(n,0);
        vector<int> adj[n];
        for(auto a:prerequisites)
        {
            int u=a[1],v=a[0];
            indegree[v]++;
            adj[u].push_back(v);
        }
        // for(auto a:indegree) cout<<a<<" ";
        int c=0;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(q.size())
        {
            int course=q.front();
            q.pop();
            c++;
            for(auto a:adj[course])
            {
                indegree[a]--;
                if(indegree[a]==0) q.push(a);
            }
        }
        return c==n;
    }
};