class Solution {
public:
    set <vector<int>> s;
    void helper(int idx,vector<int>& nums,vector<int>& temp)
    {
        int n=nums.size();
        if(idx>=n) 
        {
            s.insert(temp);
            return;
        }
        temp.push_back(nums[idx]);
        helper(idx+1,nums,temp);
        temp.pop_back();
        helper(idx+1,nums,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        helper(0,nums,temp);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};