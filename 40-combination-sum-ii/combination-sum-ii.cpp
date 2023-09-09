class Solution {
public:
    set<vector<int>> s;
    void h(int idx,int target,vector<int> &temp,vector<int> &nums)
    {
        if(target==0) s.insert(temp);
        
        for(int i=idx;i<nums.size();i++)
        {
            if(i>idx and nums[i]==nums[i-1]) continue;
            if(nums[i]>target) break;
            temp.push_back(nums[i]);
            h(i+1,target-nums[i],temp,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        h(0,target,temp,candidates);
        vector<vector<int>> ans;
        for(auto a:s) ans.push_back(a);
        return ans;
    }
};