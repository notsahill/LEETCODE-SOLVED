class Solution {
public:
    // void print(vector<int> &v)
    // {
    //     for(auto a:v)
    //     {
    //         cout<<a<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> toposort(vector<int> &indegree,vector<int> adj[],int n)
    {
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(q.size())
        {
            int ele=(q.front());
            ans.push_back(ele);
            q.pop();
            for(auto a:adj[ele])
            {
                indegree[a]--;
                if(indegree[a]==0) q.push(a);
            }
        }
        return ans.size()==n ? ans : vector<int> ();
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) 
    { 
        for(int i=0;i<n;i++)
        {
            if(group[i]==-1) group[i]= m++;
        }
        vector<int> adjG[m],adjI[n];
        vector<int> indegreeG(m,0),indegreeI(n,0),ans;
        for(int v=0;v<n;v++)
        {
           for(auto u:beforeItems[v])
           {
               adjI[u].push_back(v);
               indegreeI[v]++;
               if(group[u]!=group[v])
               {
                   adjG[group[u]].push_back(group[v]);
                   indegreeG[group[v]]++;
               }
           }
        }
        vector<int> Iorder=toposort(indegreeI,adjI,n);
        vector<int> Gorder=toposort(indegreeG,adjG,m);
        vector<int> grouped[m];
        // print(Iorder),print(Gorder);
        for(auto item:Iorder)
        {
            grouped[group[item]].push_back(item);
        }
        // for(int i=0;i<m;i++)
        // {
        //     for(auto a:grouped[i])
        //     {
        //         cout<<a<<" ";
        //     }
        //     cout<<endl;
        // }
        for(auto group:Gorder)
        {
            for(auto a:grouped[group])
            {
                ans.push_back(a);
            }
        }
        return ans;
    }
};