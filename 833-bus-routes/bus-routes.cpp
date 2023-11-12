class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        map<int,vector<int>> mp;
        for(int i=0;i<routes.size();i++)
        {
            for(auto a:routes[i])
            {
                mp[a].push_back(i);
            }
        }
        int c=1;
        queue<int> q;
        vector<int> vis(501,0);
        for(auto a:mp[source])
        {
            q.push(a);
            vis[a]=1;
        }
        while(q.size())
        {
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int rt=q.front();
                q.pop();
                for(auto a:routes[rt])
                {
                    if(a==target) return c;
                    for(auto b:mp[a])
                    {
                        if(!vis[b])
                        {
                            vis[b]=1;
                            q.push(b);
                        }
                    }
                }
            }
            c++;
        }
        return -1;
    }
};