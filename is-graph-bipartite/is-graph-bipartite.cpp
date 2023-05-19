class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<int> color(n,0);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(color[i]==0)
            {
                q.push(i);
                color[i]=-1;
            }
            while(q.size())
            {
                int node=q.front();
                q.pop();
                int c=color[node];
                for(auto a:graph[node])
                {
                    if(color[a]==0)
                    {
                        color[a]=-1*c;
                        q.push(a);
                    }
                    else
                    {
                        if(color[a]!=-1*c) return false;
                    }
                }
            }
        }
        return true;
    }
};