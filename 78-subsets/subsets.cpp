class Solution {
public:
    vector<vector<int>> ans;
    void h(int i,vector<int> &temp,vector<int> &nums){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        h(i+1,temp,nums);
        temp.pop_back();
        h(i+1,temp,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        h(0,temp,nums);
        return ans;
    }
};