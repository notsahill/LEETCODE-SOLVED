class Solution {
public:
    int findValueOfPartition(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ans=abs(nums[1]-nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            ans=min(ans,abs(nums[i]-nums[i-1]));
        }
        return ans;
    }
};