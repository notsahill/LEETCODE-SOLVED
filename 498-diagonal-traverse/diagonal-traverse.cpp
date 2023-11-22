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
        bool f=0;
        for(auto a:mp)
        {
            vector<int> temp;
            for(int i=a.second.size()-1;i>=0;i--)
            {
                int x=a.second[i].first,y=a.second[i].second;
                temp.push_back(nums[x][y]);
            }
            if(f)
            {
                reverse(temp.begin(),temp.end());
                f=0;
            }
            else f=1;
            for(auto a:temp) ans.push_back(a);
        }
        return ans;
    }
};