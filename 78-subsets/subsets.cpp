class Solution {
public:
    set<vector<int>> s;
    void h(int idx,vector<int>& nums,vector<int>& temp)
    {
        if(idx>=nums.size())
        {
            s.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        h(idx+1,nums,temp);
        temp.pop_back();
        h(idx+1,nums,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> temp;
        h(0,nums,temp);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};