class Solution {
public:
    vector<vector<int>> ans;
    void h(int idx,vector<int> &temp,vector<int>& nums, int target)
    {
        if(idx>=nums.size())
        {
            if(target==0) ans.push_back(temp);
            return;
        }
        if(nums[idx]<=target)
        {
            temp.push_back(nums[idx]);
            h(idx,temp,nums,target-nums[idx]);
            temp.pop_back();
        }
        h(idx+1,temp,nums,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        h(0,temp,candidates,target);
        return ans;
    }
};