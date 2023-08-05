class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ip=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=nums[i-1]) nums[ip++]=nums[i];
        }
        return ip;
    }
};