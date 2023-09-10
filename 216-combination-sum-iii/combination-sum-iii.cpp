class Solution {
public:
    vector<vector<int>> ans;
    void h(int idx,int target,int k,vector<int> &nums,vector<int> &temp)
    {
        if(target==0)
        {
            if(temp.size()==k) ans.push_back(temp);
            return;
        }

        if(idx>=nums.size()) return;

        if(nums[idx]>target) return;
        temp.push_back(nums[idx]);
        h(idx+1,target-nums[idx],k,nums,temp);
        temp.pop_back();

        h(idx+1,target,k,nums,temp);
    }
    vector<vector<int>> combinationSum3(int k, int target) {
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        h(0,target,k,nums,temp);

        return ans;
    }
};