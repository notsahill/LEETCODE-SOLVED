class Solution {
public: 
    vector<vector<int>> ans;
    void helper(int idx,int target,vector<int> &nums,vector<int> &temp)
    {
        if(idx==nums.size()&&target==0)
        {
            ans.push_back(temp);
            return;
        }
        if(idx==nums.size()) return;
        if(nums[idx]<=target)
        {
            temp.push_back(nums[idx]);
            helper(idx,target-nums[idx],nums,temp);
            temp.pop_back();
        }
        helper(idx+1,target,nums,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) 
    { 
        vector<int> temp;
        helper(0,target,nums,temp);
        return ans;
    }
};