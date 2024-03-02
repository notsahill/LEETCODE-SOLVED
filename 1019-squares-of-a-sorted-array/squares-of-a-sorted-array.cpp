class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int l=0,h=nums.size()-1;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(abs(nums[l])>abs(nums[h])) ans[nums.size()-i-1]=nums[l]*nums[l++];
            else ans[nums.size()-i-1]=nums[h]*nums[h--];
        }
        return ans;
    }
};