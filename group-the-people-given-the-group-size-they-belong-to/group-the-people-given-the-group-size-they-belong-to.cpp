class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        int n=groupSizes.size();
        vector<vector<int>> ans;
        map<int,vector<int>> m;
        for(int i=0;i<n;i++)
        {
            int sz=groupSizes[i];
            m[sz].push_back(i);
        }
        cout<<m.size();
        for(auto a:m)
        {
            int sz=a.first;
            int sz1=a.second.size();
            int k=0;
            for(int i=0;i<sz1/sz;i++)
            {
                vector<int> temp;
                for(int j=0;j<sz;j++)
                {
                    temp.push_back(a.second[j]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
    
};