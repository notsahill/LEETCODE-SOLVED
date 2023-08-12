class Solution {
public:
    set<vector<int>> s;
    void h(int idx,vector<int>& nums, int target,vector<int>& temp)
    {
        int n=nums.size();
        if(target==0)
        {
            s.insert(temp);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx and nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            temp.push_back(nums[i]);
            h(i+1,nums,target-nums[i],temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        h(0,nums,target,temp);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};