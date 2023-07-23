class Solution {
public:
    vector<vector<int>> ans;
    void h(int idx,vector<int>& nums,vector<int>& temp)
    {
        if(idx>=nums.size())
        {
            ans.push_back(temp);
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
        return ans;
    }
};