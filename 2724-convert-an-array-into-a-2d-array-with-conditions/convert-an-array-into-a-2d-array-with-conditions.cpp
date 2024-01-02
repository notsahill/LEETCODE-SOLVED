class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        unordered_map<int,int> um;
        int mx=0;
        for(auto a:nums)
        {
            um[a]++;
            mx=max(mx,um[a]);
        }
        vector<vector<int>> ans(mx);
        for(auto a:nums)
        {
            int occ=um[a];
            if(occ>=1) ans[occ-1].push_back(a);
            um[a]--;
        }
        return ans;
    }
};