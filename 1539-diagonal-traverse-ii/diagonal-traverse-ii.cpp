class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> ans;
        map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                int val=i+j;
                mp[val].push_back({i,j});
            }
        }

        for(auto a:mp)
        {
            for(int i=a.second.size()-1;i>=0;i--)
            {
                int x=a.second[i].first,y=a.second[i].second;
                ans.push_back(nums[x][y]);
            }
        }
        return ans;
    }
};