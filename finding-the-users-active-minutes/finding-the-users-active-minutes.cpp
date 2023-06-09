class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        map<int,set<int>> m;
        vector<int> ans(k,0);
        for(int i=0;i<logs.size();i++)
        {
            int id=logs[i][0];
            int t=logs[i][1];
            m[id].insert(t);
        }
        cout<<m.size();
        for(auto a:m)
        {
            int sz=a.second.size();
            if(sz>=1 and sz <=k)
            {
                ans[sz-1]++;
            }
        }
        return ans;
    }
};