class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        int mn=nums[0]+k,mx=nums[nums.size()-1]-k;
        return max(0,mx-mn);
    }
};