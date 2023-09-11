class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> m;
        int n=groupSizes.size();
        for(int i=0;i<n;i++)
        {
            m[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for(auto a:m)
        {
            int sz=a.first;
            int persons=a.second.size();
            for(int i=0;i<persons/sz;i++)
            {
                vector<int> temp;
                for(int j=0;j<sz;j++)
                {
                    temp.push_back(a.second[j+(sz*i)]);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};